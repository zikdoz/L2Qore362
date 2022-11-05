#include "pch/pch.h"

#include "app/LoginServer.h"

#include "ui/form/mwloginserver.h"

#include <QDebug>

auto bk = qInstallMessageHandler( nullptr );

void messageHandler( QtMsgType                 type
                   , const QMessageLogContext& context
                   , const QString&            msg );

int main( int argc, char* argv[ ] )
{
    qInstallMessageHandler( messageHandler );

    QString app_dir = QFileInfo( argv[ 0 ] ).dir().path();

    QStringList paths = QCoreApplication::libraryPaths();
    paths.append( app_dir + "/../lib/x64" );
    paths.append( app_dir + "/../lib/x64/imageformats" );
    paths.append( app_dir + "/../lib/x64/platforms" );
    paths.append( app_dir + "/../lib/x64/sqldrivers" );
    QCoreApplication::setLibraryPaths( paths );

    QApplication  a( argc, argv );
    MWLoginServer w;
    w.show();

    Common::Generics::initSingleton< App::LoginServer >();

    return a.exec();
}

void messageHandler( QtMsgType                 type
                   , const QMessageLogContext& context
                   , const QString&            msg )
{
    ( *bk )( type, context, msg );
}
