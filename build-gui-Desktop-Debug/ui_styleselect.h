/********************************************************************************
** Form generated from reading UI file 'styleselect.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLESELECT_H
#define UI_STYLESELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_styleSelect
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *Add;
    QPushButton *Default;
    QLabel *label;

    void setupUi(QDialog *styleSelect)
    {
        if (styleSelect->objectName().isEmpty())
            styleSelect->setObjectName(QStringLiteral("styleSelect"));
        styleSelect->resize(651, 300);
        buttonBox = new QDialogButtonBox(styleSelect);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Add = new QPushButton(styleSelect);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setGeometry(QRect(30, 90, 89, 25));
        Default = new QPushButton(styleSelect);
        Default->setObjectName(QStringLiteral("Default"));
        Default->setGeometry(QRect(30, 130, 89, 25));
        label = new QLabel(styleSelect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(176, 99, 401, 71));

        retranslateUi(styleSelect);
        QObject::connect(buttonBox, SIGNAL(accepted()), styleSelect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), styleSelect, SLOT(reject()));

        QMetaObject::connectSlotsByName(styleSelect);
    } // setupUi

    void retranslateUi(QDialog *styleSelect)
    {
        styleSelect->setWindowTitle(QApplication::translate("styleSelect", "Dialog", 0));
        Add->setText(QApplication::translate("styleSelect", "Add", 0));
        Default->setText(QApplication::translate("styleSelect", "Default", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class styleSelect: public Ui_styleSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLESELECT_H
