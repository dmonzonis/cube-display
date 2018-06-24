#include <QApplication>

#include <iostream>

#include "window.h"
#include "rotation3d.h"
#include "polygon3d.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget* window = new Window;

    window->show();

    return app.exec();
}
