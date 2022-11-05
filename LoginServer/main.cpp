#include "pch/pch.h"

#include "app/LoginServer.h"

#include "ui/form/mwloginserver.h"

int main( int argc, char* argv[ ] )
{
    QApplication  a( argc, argv );
    MWLoginServer w;
    w.show();

    Common::Generics::initSingleton< App::LoginServer >();

    return a.exec();
}
