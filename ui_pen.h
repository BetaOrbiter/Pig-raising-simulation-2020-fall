/********************************************************************************
** Form generated from reading UI file 'pen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEN_H
#define UI_PEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pen
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *pen)
    {
        if (pen->objectName().isEmpty())
            pen->setObjectName(QString::fromUtf8("pen"));
        pen->resize(728, 251);
        gridLayout = new QGridLayout(pen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(pen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(pen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(pen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(pen);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_5 = new QLabel(pen);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(pen);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 1, 1, 1);

        label_7 = new QLabel(pen);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        label_8 = new QLabel(pen);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 3, 1, 1);


        retranslateUi(pen);

        QMetaObject::connectSlotsByName(pen);
    } // setupUi

    void retranslateUi(QWidget *pen)
    {
        pen->setWindowTitle(QApplication::translate("pen", "\347\214\252\345\234\210\345\206\205\351\203\250", nullptr));
        label->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_2->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_3->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_4->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_5->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_6->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_7->setText(QApplication::translate("pen", "\347\251\272", nullptr));
        label_8->setText(QApplication::translate("pen", "\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pen: public Ui_pen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEN_H
