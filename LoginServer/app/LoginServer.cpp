#include "pch/pch.h"

#include "app/LoginServer.h"

#include "database/DBFactory.h"

namespace App
{
#pragma region [ Interface ]

bool LoginServer::init()
{
    Common::Generics::initSingleton< Common::Database::DBFactory >();

    const auto con = Common::Database::DBFactory::the().getConnection();

    return true;
}

#pragma endregion
}
