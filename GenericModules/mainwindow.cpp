#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ClassBlocksOnNumber = new BlocksOnNumber(this);
    ui->verticalLayout_2->addWidget(ClassBlocksOnNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}
