#include "MainWindow.h"

#include "common/LabRootWidget.h"
#include "common/LabPluginBase.h"

#include <qDebug>
#include <QDirIterator>
#include <QTabBar>
#include <QPluginLoader>

MainWindow::MainWindow() {
    setupUi(this);

    connect(rescanBut, &QPushButton::clicked, this, &MainWindow::rescanPlugins);
    show();
}

MainWindow::~MainWindow() = default;

void MainWindow::rescanPlugins() {
    labRoots.clear();
    labTabs->clear();
    QDirIterator it("labs");
    while (it.hasNext()) {
        QString labName = it.next();
        if (labName.endsWith(".")) {
            continue;
        }
        QPluginLoader loader(labName);
        if (auto instance = loader.instance()) {
            if (auto plugin = qobject_cast<LabPluginBase *>(instance)) {
                labRoots.push_back(plugin->createRoot());
                labTabs->addTab(labRoots.back().get(), plugin->tabTitle());
            } else {
                qDebug() << "qobject_cast<> returned nullptr";
            }
        } else {
            qDebug() << loader.errorString();
        }
    }
    if (labTabs->count() == 0) {
        labTabs->addTab(emptyTab, "No labs");
    }
}
