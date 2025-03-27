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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *headerLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnBack;
    QTableView *playlistView;
    QPushButton *renameButton;
    QHBoxLayout *trackInfoLayout;
    QLabel *currentTrackLabel;
    QLabel *timeLabel;
    QSlider *progressSlider;
    QHBoxLayout *controlsLayout;
    QToolButton *btn_previous;
    QToolButton *btn_play;
    QToolButton *btn_pause;
    QToolButton *btn_next;
    QSlider *volumeSlider;
    QToolButton *btnRename;
    QHBoxLayout *bottomLayout;
    QToolButton *btnRemove;
    QToolButton *btn_add;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background: #1a1a1a;\n"
"        color: #ffffff;\n"
"        font-family: 'Segoe UI';\n"
"    }\n"
"    QTableView {\n"
"        background: #2d2d2d;\n"
"        border: 1px solid #404040;\n"
"        border-radius: 8px;\n"
"        gridline-color: #404040;\n"
"    }\n"
"    QToolButton {\n"
"        background: #333333;\n"
"        border: 2px solid #404040;\n"
"        border-radius: 20px;\n"
"        padding: 10px;\n"
"        margin: 5px;\n"
"    }\n"
"    QToolButton:hover {\n"
"        background: #404040;\n"
"    }\n"
"    QToolButton:pressed {\n"
"        background: #4d4d4d;\n"
"    }\n"
"    QSlider::groove:horizontal {\n"
"        height: 6px;\n"
"        background: #404040;\n"
"        border-radius: 3px;\n"
"    }\n"
"    QSlider::handle:horizontal {\n"
"        background: #00ff88;\n"
"        width: 16px;\n"
"        margin: -5px 0;\n"
"        border-radius: 8px;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #00ff88;"));

        headerLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(horizontalSpacer);

        btnBack = new QPushButton(Widget);
        btnBack->setObjectName("btnBack");
        btnBack->setStyleSheet(QString::fromUtf8("QPushButton#btnBack {\n"
"    padding: 8px 15px;\n"
"    border-radius: 15px;\n"
"    background: #00ff88;\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#btnBack:hover {\n"
"    background: #00cc6a;\n"
"}\n"
""));
        btnBack->setAutoRepeat(false);

        headerLayout->addWidget(btnBack);


        verticalLayout->addLayout(headerLayout);

        playlistView = new QTableView(Widget);
        playlistView->setObjectName("playlistView");
        playlistView->setStyleSheet(QString::fromUtf8("\n"
"       QHeaderView::section {\n"
"           background: #333333;\n"
"           padding: 8px;\n"
"           border: none;\n"
"       }\n"
"      "));

        verticalLayout->addWidget(playlistView);

        renameButton = new QPushButton(Widget);
        renameButton->setObjectName("renameButton");

        verticalLayout->addWidget(renameButton);

        trackInfoLayout = new QHBoxLayout();
        trackInfoLayout->setObjectName("trackInfoLayout");
        currentTrackLabel = new QLabel(Widget);
        currentTrackLabel->setObjectName("currentTrackLabel");
        currentTrackLabel->setStyleSheet(QString::fromUtf8("color: #00ff88; font-size: 14px;"));

        trackInfoLayout->addWidget(currentTrackLabel);

        timeLabel = new QLabel(Widget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setStyleSheet(QString::fromUtf8("color: #00ff88; font-size: 14px;"));

        trackInfoLayout->addWidget(timeLabel, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout->addLayout(trackInfoLayout);

        progressSlider = new QSlider(Widget);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(progressSlider);

        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        btn_previous = new QToolButton(Widget);
        btn_previous->setObjectName("btn_previous");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/buttons/skip-previous.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_previous->setIcon(icon);
        btn_previous->setIconSize(QSize(32, 32));

        controlsLayout->addWidget(btn_previous);

        btn_play = new QToolButton(Widget);
        btn_play->setObjectName("btn_play");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/buttons/play.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_play->setIcon(icon1);
        btn_play->setIconSize(QSize(48, 48));

        controlsLayout->addWidget(btn_play);

        btn_pause = new QToolButton(Widget);
        btn_pause->setObjectName("btn_pause");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/buttons/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_pause->setIcon(icon2);
        btn_pause->setIconSize(QSize(48, 48));

        controlsLayout->addWidget(btn_pause);

        btn_next = new QToolButton(Widget);
        btn_next->setObjectName("btn_next");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/buttons/skip-next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_next->setIcon(icon3);
        btn_next->setIconSize(QSize(32, 32));

        controlsLayout->addWidget(btn_next);

        volumeSlider = new QSlider(Widget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setStyleSheet(QString::fromUtf8("\n"
"         QSlider::groove:horizontal {\n"
"             height: 4px;\n"
"             background: #404040;\n"
"             border-radius: 2px;\n"
"         }\n"
"         QSlider::handle:horizontal {\n"
"             background: #ffffff;\n"
"             width: 12px;\n"
"             margin: -4px 0;\n"
"             border-radius: 6px;\n"
"         }\n"
"        "));
        volumeSlider->setMinimum(0);
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(75);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);

        controlsLayout->addWidget(volumeSlider);

        btnRename = new QToolButton(Widget);
        btnRename->setObjectName("btnRename");
        btnRename->setVisible(false);
        btnRename->setStyleSheet(QString::fromUtf8("\n"
"      QToolButton {\n"
"          background: #00ff88;\n"
"          color: #ffffff;\n"
"          border: none;\n"
"          border-radius: 10px;\n"
"      }\n"
"      QToolButton:hover {\n"
"          background: #00cc6a;\n"
"      }\n"
"     "));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/buttons/rename.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRename->setIcon(icon4);
        btnRename->setCheckable(true);

        controlsLayout->addWidget(btnRename);


        verticalLayout->addLayout(controlsLayout);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setObjectName("bottomLayout");
        btnRemove = new QToolButton(Widget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setStyleSheet(QString::fromUtf8("\n"
"      QToolButton {\n"
"          padding: 8px 15px;\n"
"          border-radius: 15px;\n"
"          background: #ff4444; /* \320\232\321\200\320\260\321\201\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217 */\n"
"          color: #ffffff;\n"
"          font-weight: bold;\n"
"      }\n"
"      QToolButton:hover {\n"
"          background: #cc0000; /* \320\242\320\265\320\274\320\275\320\265\320\265 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"      }\n"
"     "));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/buttons/remove.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRemove->setIcon(icon5);

        bottomLayout->addWidget(btnRemove);

        btn_add = new QToolButton(Widget);
        btn_add->setObjectName("btn_add");
        btn_add->setStyleSheet(QString::fromUtf8("\n"
"         QToolButton {\n"
"             padding: 8px 15px;\n"
"             border-radius: 15px;\n"
"             background: #00ff88;\n"
"             color: #1a1a1a;\n"
"             font-weight: bold;\n"
"         }\n"
"         QToolButton:hover {\n"
"             background: #00cc6a;\n"
"         }\n"
"        "));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/buttons/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_add->setIcon(icon6);

        bottomLayout->addWidget(btn_add);


        verticalLayout->addLayout(bottomLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "NoName Player", nullptr));
        label->setText(QCoreApplication::translate("Widget", "NoName Player", nullptr));
        btnBack->setText(QCoreApplication::translate("Widget", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        renameButton->setText(QCoreApplication::translate("Widget", "Rename", nullptr));
        currentTrackLabel->setText(QCoreApplication::translate("Widget", "Now Playing: ...", nullptr));
        timeLabel->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
#if QT_CONFIG(tooltip)
        btnRename->setToolTip(QCoreApplication::translate("Widget", "Rename track", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRename->setText(QCoreApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\270\320\274\320\265\320\275\320\276\320\262\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        btnRemove->setToolTip(QCoreApplication::translate("Widget", "Remove selected track", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRemove->setText(QCoreApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\321\200\320\265\320\272", nullptr));
#if QT_CONFIG(tooltip)
        btn_add->setToolTip(QCoreApplication::translate("Widget", "Add music files", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_add->setText(QCoreApplication::translate("Widget", "Add Tracks", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
