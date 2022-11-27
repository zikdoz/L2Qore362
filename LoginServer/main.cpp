#include "pch/pch.h"

#include "app/LoginServer.h"

#include "ui/form/mwloginserver.h"

#include "util/Logger.h"

int main( int   argc
        , char* argv[ ] )
{
    Common::Generics::initSingleton< Common::Logger >();

    const auto root_logger = CM_LOG.setupRoot();
    spdlog::register_logger( root_logger );

#ifdef LQ_DEBUG
    root_logger->set_level( spdlog::level::trace );
#else
    root_logger->set_level( spdlog::level::info );
#endif

    root_logger->flush_on( spdlog::level::err );

    root_logger->sinks()[ 0 ]->set_pattern( "[%H:%M:%S.%e][ %=9l ][%n] %v" );       // console
    root_logger->sinks()[ 1 ]->set_pattern( "[%m/%d %H:%M:%S.%e][ %=9l ][%n] %v" ); // file

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
