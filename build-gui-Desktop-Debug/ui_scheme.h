/********************************************************************************
** Form generated from reading UI file 'scheme.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEME_H
#define UI_SCHEME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Scheme
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Scheme)
    {
        if (Scheme->objectName().isEmpty())
            Scheme->setObjectName(QStringLiteral("Scheme"));
        Scheme->resize(967, 649);
        graphicsView = new QGraphicsView(Scheme);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(60, 41, 871, 591));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        graphicsView->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);

        retranslateUi(Scheme);

        QMetaObject::connectSlotsByName(Scheme);
    } // setupUi

    void retranslateUi(QDialog *Scheme)
    {
        Scheme->setWindowTitle(QApplication::translate("Scheme", "New scheme", 0));
    } // retranslateUi

};

namespace Ui {
    class Scheme: public Ui_Scheme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEME_H
