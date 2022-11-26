#include "pch/pch.h"

#include "app/LoginServer.h"

#include "ui/form/mwloginserver.h"

#include "util/Logger.h"

int main( int   argc
        , char* argv[ ] )
{
    Common::Generics::initSingleton< Common::Logger >();

    const auto logger = Common::Logger::the().constructLogger( Common::Logger::the().constructCommonSinks() );
    spdlog::register_logger( logger );

    spdlog::set_level( spdlog::level::debug );

    const QString app_dir = QFileInfo( argv[ 0 ] ).dir().path();

    QStringList paths = QCoreApplication::libraryPaths();
    paths.append( app_dir + "/../lib/x64" );
    paths.append( app_dir + "/../lib/x64/imageformats" );
    paths.append( app_dir + "/../lib/x64/platforms" );
    paths.append( app_dir + "/../lib/x64/sqldrivers" );
    QCoreApplication::setLibraryPaths( paths );

    QApplication a( argc, argv );

    MWLoginServer w;
    w.show();

    Common::Generics::initSingleton< App::LoginServer >();

    return a.exec();
}
