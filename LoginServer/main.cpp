#include "pch/pch.h"

#include "ui/form/mwloginserver.h"

#include <QApplication>

int main( int argc, char* argv[ ] )
{
    QApplication  a( argc, argv );
    MWLoginServer w;
    w.show();
    return a.exec();
}
