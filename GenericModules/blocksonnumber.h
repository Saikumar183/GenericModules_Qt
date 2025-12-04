#ifndef BLOCKSONNUMBER_H
#define BLOCKSONNUMBER_H

#include <QWidget>

namespace Ui {
class BlocksOnNumber;
}

class BlocksOnNumber : public QWidget
{
    Q_OBJECT

public:
    explicit BlocksOnNumber(QWidget *parent = 0);
    ~BlocksOnNumber();

private:
    Ui::BlocksOnNumber *ui;
};

#endif // BLOCKSONNUMBER_H
