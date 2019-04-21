#pragma once

#include <QMainWindow>
#include "ui_main.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
Q_OBJECT
public:
    MainWindow();

private slots:
    void rescanPlugins();
};
