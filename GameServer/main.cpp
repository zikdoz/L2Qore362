#include "pch/pch.h"

#include "ui/form/mwgameserver.h"

#include <QApplication>

int main( int argc, char* argv[ ] )
{
    QApplication a( argc, argv );
    MWGameServer w;
    w.show();
    return a.exec();
}
