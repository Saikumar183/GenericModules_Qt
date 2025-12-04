#include "blocksonnumber.h"
#include "ui_blocksonnumber.h"

BlocksOnNumber::BlocksOnNumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlocksOnNumber)
{
    ui->setupUi(this);
}

BlocksOnNumber::~BlocksOnNumber()
{
    delete ui;
}
