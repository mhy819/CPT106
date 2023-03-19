#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include "file.h"
QString filename;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainWindow w;
        w.show();
    return a.exec();
}
