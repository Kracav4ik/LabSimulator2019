#pragma once

#include <QMainWindow>
#include <memory>
#include <vector>
#include "ui_main.h"

class LabRootWidget;

class MainWindow : public QMainWindow, private Ui::MainWindow {
Q_OBJECT
private:
    std::vector<std::unique_ptr<LabRootWidget>> labRoots;

public:
    MainWindow();
    ~MainWindow();

private slots:
    void rescanPlugins();
};
