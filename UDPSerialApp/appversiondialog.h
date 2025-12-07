#pragma once

#include <QWidget>

class AppVersionDialog
{
public:
    // parent = MainWindow, etc.
    static void show(QWidget *parent = nullptr);
};
