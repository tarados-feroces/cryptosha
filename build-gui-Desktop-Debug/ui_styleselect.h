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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StyleSelect
{
public:
    QGridLayout *gridLayout;
    QPushButton *Default;
    QPushButton *Add;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *StyleSelect)
    {
        if (StyleSelect->objectName().isEmpty())
            StyleSelect->setObjectName(QStringLiteral("StyleSelect"));
        StyleSelect->resize(439, 166);
        gridLayout = new QGridLayout(StyleSelect);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Default = new QPushButton(StyleSelect);
        Default->setObjectName(QStringLiteral("Default"));

        gridLayout->addWidget(Default, 1, 0, 1, 1);

        Add = new QPushButton(StyleSelect);
        Add->setObjectName(QStringLiteral("Add"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Add->sizePolicy().hasHeightForWidth());
        Add->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Add, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(StyleSelect);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        label = new QLabel(StyleSelect);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 1, 2, 1);


        retranslateUi(StyleSelect);
        QObject::connect(buttonBox, SIGNAL(accepted()), StyleSelect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StyleSelect, SLOT(reject()));

        QMetaObject::connectSlotsByName(StyleSelect);
    } // setupUi

    void retranslateUi(QDialog *StyleSelect)
    {
        StyleSelect->setWindowTitle(QApplication::translate("StyleSelect", "Choose style", 0));
        Default->setText(QApplication::translate("StyleSelect", "Default", 0));
        Add->setText(QApplication::translate("StyleSelect", "Choose", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StyleSelect: public Ui_StyleSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLESELECT_H
