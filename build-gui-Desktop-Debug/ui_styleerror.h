/********************************************************************************
** Form generated from reading UI file 'styleerror.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLEERROR_H
#define UI_STYLEERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StyleError
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Ok;

    void setupUi(QDialog *StyleError)
    {
        if (StyleError->objectName().isEmpty())
            StyleError->setObjectName(QStringLiteral("StyleError"));
        StyleError->resize(468, 123);
        verticalLayout = new QVBoxLayout(StyleError);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(StyleError);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(StyleError);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        Ok = new QPushButton(StyleError);
        Ok->setObjectName(QStringLiteral("Ok"));

        verticalLayout->addWidget(Ok);


        retranslateUi(StyleError);

        QMetaObject::connectSlotsByName(StyleError);
    } // setupUi

    void retranslateUi(QDialog *StyleError)
    {
        StyleError->setWindowTitle(QApplication::translate("StyleError", "Error", 0));
        label->setText(QApplication::translate("StyleError", "Error!", 0));
        label_2->setText(QApplication::translate("StyleError", "Incorrect style file. Scheme display may be invalid.", 0));
        Ok->setText(QApplication::translate("StyleError", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class StyleError: public Ui_StyleError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEERROR_H
