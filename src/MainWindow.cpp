#include "MainWindow.h"

#include <qDebug>
#include <QDirIterator>
#include <QTabBar>
#include <QPluginLoader>

#include "labs/lab3/Lab3Plugin.h"

MainWindow::MainWindow() {
    setupUi(this);

    connect(rescanBut, &QPushButton::clicked, this, &MainWindow::rescanPlugins);
    show();
}

void MainWindow::rescanPlugins() {
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
                labTabs->tabBar()->addTab(plugin->tabTitle());
            } else {
                qDebug() << "qobject_cast<> returned nullptr";
            }
        } else {
            qDebug() << loader.errorString();
        }
    }
}
