#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include "distance_aj.h"
using namespace std;

int main(int argc, char *argv[])
{
    distance_aj dist1(100.0f), dist2(20.0f);
    distance_aj dist3 = dist1 / dist2;
    //char unit = 'm';
    //cout << dist.getDistance(&unit);
    cout << dist3.getDistance();
    //dist1 -= dist2;
    //cout << dist1.getDistance();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
