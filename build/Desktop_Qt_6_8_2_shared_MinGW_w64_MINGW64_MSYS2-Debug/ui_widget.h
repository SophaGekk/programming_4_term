/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QToolButton *btn_add;
    QToolButton *btn_stop;
    QToolButton *btn_next;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_previous;
    QToolButton *btn_play;
    QToolButton *btn_pause;
    QTableView *playlistView;
    QLabel *currentTrack;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        btn_add = new QToolButton(Widget);
        btn_add->setObjectName("btn_add");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/buttons/plus.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_add->setIcon(icon);

        gridLayout->addWidget(btn_add, 0, 0, 1, 1);

        btn_stop = new QToolButton(Widget);
        btn_stop->setObjectName("btn_stop");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/buttons/stop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_stop->setIcon(icon1);

        gridLayout->addWidget(btn_stop, 0, 4, 1, 1);

        btn_next = new QToolButton(Widget);
        btn_next->setObjectName("btn_next");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/buttons/skip-next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_next->setIcon(icon2);

        gridLayout->addWidget(btn_next, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        btn_previous = new QToolButton(Widget);
        btn_previous->setObjectName("btn_previous");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/buttons/skip-previous.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_previous->setIcon(icon3);

        gridLayout->addWidget(btn_previous, 0, 1, 1, 1);

        btn_play = new QToolButton(Widget);
        btn_play->setObjectName("btn_play");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/buttons/play.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_play->setIcon(icon4);

        gridLayout->addWidget(btn_play, 0, 2, 1, 1);

        btn_pause = new QToolButton(Widget);
        btn_pause->setObjectName("btn_pause");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/buttons/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_pause->setIcon(icon5);

        gridLayout->addWidget(btn_pause, 0, 3, 1, 1);

        playlistView = new QTableView(Widget);
        playlistView->setObjectName("playlistView");

        gridLayout->addWidget(playlistView, 1, 0, 1, 8);

        currentTrack = new QLabel(Widget);
        currentTrack->setObjectName("currentTrack");

        gridLayout->addWidget(currentTrack, 0, 7, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Simple Audio Player", nullptr));
        btn_stop->setText(QCoreApplication::translate("Widget", "...", nullptr));
        btn_next->setText(QCoreApplication::translate("Widget", "...", nullptr));
        btn_previous->setText(QCoreApplication::translate("Widget", "...", nullptr));
        btn_play->setText(QCoreApplication::translate("Widget", "...", nullptr));
        btn_pause->setText(QCoreApplication::translate("Widget", "...", nullptr));
        currentTrack->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
