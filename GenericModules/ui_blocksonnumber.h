/********************************************************************************
** Form generated from reading UI file 'blocksonnumber.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKSONNUMBER_H
#define UI_BLOCKSONNUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlocksOnNumber
{
public:

    void setupUi(QWidget *BlocksOnNumber)
    {
        if (BlocksOnNumber->objectName().isEmpty())
            BlocksOnNumber->setObjectName(QStringLiteral("BlocksOnNumber"));
        BlocksOnNumber->resize(400, 300);

        retranslateUi(BlocksOnNumber);

        QMetaObject::connectSlotsByName(BlocksOnNumber);
    } // setupUi

    void retranslateUi(QWidget *BlocksOnNumber)
    {
        BlocksOnNumber->setWindowTitle(QApplication::translate("BlocksOnNumber", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BlocksOnNumber: public Ui_BlocksOnNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKSONNUMBER_H
