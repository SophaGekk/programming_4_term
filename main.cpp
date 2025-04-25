#include "widget.h"
#include <QApplication>
#include "C:/Users/Sopha/Downloads/gg/lab4/LoggerFactory.h"
#include "playlistselector.h"
#include <QApplication>
#include <QRegularExpression>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include "playlistselector.h"
#include "widget.h"
#include "test.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlaylistSelector selector;
    runTests();
    selector.show();
    return a.exec();
}
