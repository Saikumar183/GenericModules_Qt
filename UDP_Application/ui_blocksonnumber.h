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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlocksOnNumber
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *applyFormatButton;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QComboBox *CmBx_byteFormate;

    void setupUi(QWidget *BlocksOnNumber)
    {
        if (BlocksOnNumber->objectName().isEmpty())
            BlocksOnNumber->setObjectName(QStringLiteral("BlocksOnNumber"));
        BlocksOnNumber->resize(400, 300);
        gridLayout = new QGridLayout(BlocksOnNumber);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(BlocksOnNumber);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        applyFormatButton = new QPushButton(BlocksOnNumber);
        applyFormatButton->setObjectName(QStringLiteral("applyFormatButton"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        applyFormatButton->setFont(font);

        gridLayout->addWidget(applyFormatButton, 1, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 2, 0, 1, 4);

        checkBox = new QCheckBox(BlocksOnNumber);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 1, 1, 1, 1);

        CmBx_byteFormate = new QComboBox(BlocksOnNumber);
        CmBx_byteFormate->setObjectName(QStringLiteral("CmBx_byteFormate"));
        CmBx_byteFormate->setFont(font);

        gridLayout->addWidget(CmBx_byteFormate, 1, 2, 1, 1);


        retranslateUi(BlocksOnNumber);

        QMetaObject::connectSlotsByName(BlocksOnNumber);
    } // setupUi

    void retranslateUi(QWidget *BlocksOnNumber)
    {
        BlocksOnNumber->setWindowTitle(QApplication::translate("BlocksOnNumber", "Form", Q_NULLPTR));
        applyFormatButton->setText(QApplication::translate("BlocksOnNumber", "CONVERT", Q_NULLPTR));
        checkBox->setText(QApplication::translate("BlocksOnNumber", "Formated O/P", Q_NULLPTR));
        CmBx_byteFormate->clear();
        CmBx_byteFormate->insertItems(0, QStringList()
         << QApplication::translate("BlocksOnNumber", "ABCD", Q_NULLPTR)
         << QApplication::translate("BlocksOnNumber", "CDAB", Q_NULLPTR)
         << QApplication::translate("BlocksOnNumber", "BADC", Q_NULLPTR)
         << QApplication::translate("BlocksOnNumber", "DCBA", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class BlocksOnNumber: public Ui_BlocksOnNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKSONNUMBER_H
