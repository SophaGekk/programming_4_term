/********************************************************************************
** Form generated from reading UI file 'playlistselector.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTSELECTOR_H
#define UI_PLAYLISTSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylistSelector
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *playlistListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddPlaylist;
    QPushButton *btnRemovePlaylist;

    void setupUi(QWidget *PlaylistSelector)
    {
        if (PlaylistSelector->objectName().isEmpty())
            PlaylistSelector->setObjectName("PlaylistSelector");
        PlaylistSelector->resize(800, 600);
        PlaylistSelector->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background: #1a1a1a;\n"
"        color: #ffffff;\n"
"    }\n"
"   QPushButton {\n"
"      padding: 8px 15px;\n"
"      border-radius: 15px;\n"
"      background: #00ff88;\n"
"      color: #ffffff;\n"
"      font-weight: bold;\n"
"   }\n"
"\n"
"   QPushButton:hover {\n"
"      background: #00cc6a;\n"
"   }\n"
"   QListWidget {\n"
"            background: #2d2d2d;\n"
"            color: #00ff88;\n"
"   }\n"
"   QListWidget::item {\n"
"            background: #2d2d2d;\n"
"            color: #00ff88;\n"
"     }\n"
"\n"
"    QListWidget::item:selected {\n"
"            background: #333333;\n"
"            color: #00ff88;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(PlaylistSelector);
        verticalLayout->setObjectName("verticalLayout");
        playlistListWidget = new QListWidget(PlaylistSelector);
        playlistListWidget->setObjectName("playlistListWidget");

        verticalLayout->addWidget(playlistListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAddPlaylist = new QPushButton(PlaylistSelector);
        btnAddPlaylist->setObjectName("btnAddPlaylist");

        horizontalLayout->addWidget(btnAddPlaylist);

        btnRemovePlaylist = new QPushButton(PlaylistSelector);
        btnRemovePlaylist->setObjectName("btnRemovePlaylist");

        horizontalLayout->addWidget(btnRemovePlaylist);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PlaylistSelector);

        QMetaObject::connectSlotsByName(PlaylistSelector);
    } // setupUi

    void retranslateUi(QWidget *PlaylistSelector)
    {
        PlaylistSelector->setWindowTitle(QCoreApplication::translate("PlaylistSelector", "\320\222\321\213\320\261\320\276\321\200 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\320\260", nullptr));
        btnAddPlaylist->setText(QCoreApplication::translate("PlaylistSelector", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        btnRemovePlaylist->setText(QCoreApplication::translate("PlaylistSelector", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaylistSelector: public Ui_PlaylistSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTSELECTOR_H
