#include <iostream>
#include "calculator.h"
#include <QApplication>
#include <QIcon>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator window;
    window.show();
    window.setWindowTitle("Kalkulajtor");
    window.setWindowIcon(QIcon(":/new/icons/kalkulator.png"));

    return a.exec();
}
