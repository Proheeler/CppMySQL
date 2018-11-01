#include <iostream>
#include <boost/variant.hpp>
#include <boost/any.hpp>
#include <vector>

#include <string.h>
#include <exception>

#include <QApplication>
#include "headers/myWidget.h"
int main (int argc, char* argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.show();

    return a.exec();


}


