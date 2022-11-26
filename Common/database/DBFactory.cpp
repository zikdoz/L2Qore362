#include "pch/pch.h"

#include "database/DBFactory.h"

#include "util/Logger.h"

namespace Common::Database
{
#pragma region [ Define static ]

QThreadStorage< QSqlDatabase > DBFactory::s_db_pool;

#pragma endregion

#pragma region [ Interface ]

bool DBFactory::init()
{
    return true;
}

#pragma endregion

#pragma region [ Utility ]

QSqlDatabase DBFactory::getConnection()
{
    if ( s_db_pool.hasLocalData() )
    {
        return s_db_pool.localData();
    }

    auto db_con = QSqlDatabase::addDatabase( "QMYSQL", QUuid::createUuid().toString() );

    // TODO: extract to config
    db_con.setHostName( "localhost" );
    db_con.setDatabaseName( "l2jmobiusessence362" );
    db_con.setUserName( "root" );
    db_con.setPassword( "" );
    db_con.setConnectOptions( "MYSQL_OPT_CONNECT_TIMEOUT=5000" );

    const auto logger = Logger::the().getCommon();

    logger->debug( QString( "Trying to open DB connection.." ) );

    // NOTE: it cant respect set timeout if DB driver is not loaded,
    //       thus it'll enter infinite do-while loop and spam like hell
    do
    {
        if ( !db_con.open() )
        {
            logger->error( "Failed to connect to the database: {0}", db_con.lastError().text() );
        }
    }
    while ( !db_con.isOpen() );

    logger->info( "Connection is open!" );

    s_db_pool.setLocalData( db_con );
    return db_con;
}

void DBFactory::close()
{
    if ( !s_db_pool.hasLocalData() )
    {
        return;
    }

    s_db_pool.localData().close();
}

#pragma endregion
}
