#include "widget.h"
#include <QApplication>
#include "C:/Users/Sopha/Downloads/gg/lab4/LoggerFactory.h"
#include "playlistselector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlaylistSelector selector;
    selector.show();
    return a.exec();
}

// int main(int argc, char *argv[]) {
//     QApplication a(argc, argv);
//     Widget w;
//     w.show();
//     auto consoleLogger = LoggerFactory::CreateLogger(1); // Консольный логгер
//     auto fileLogger = LoggerFactory::CreateLogger(2, "user_interface.log"); // Файловый логгер
//     return a.exec();
// }
