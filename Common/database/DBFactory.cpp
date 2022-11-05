#include "pch/pch.h"

#include "database/DBFactory.h"

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

    do
    {
        if ( !db_con.open() )
        {
            // TODO: handle error (e.g. print text using .text() method)
            // const auto con_error = db_con.lastError();
        }
    }
    while ( !db_con.isOpen() );

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
