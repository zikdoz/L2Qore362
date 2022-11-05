#pragma once

#include "enum/ServerStatus.h"

namespace App
{
class LoginServer
    : public QObject
    , public Common::Type::TSingleton< LoginServer >
    , public Common::Interface::IInitializable

{
    Q_OBJECT

public:
    static const int PROTOCOL_REVISION = 0x0106;

private:
    Common::Enum::EServerStatus _server_status = Common::Enum::EServerStatus::NORMAL;

#pragma region [ C/D-tor ]

public:
    LoginServer( SingletonCtorToken )
        : QObject() {}

    ~LoginServer() override = default;

#pragma endregion

#pragma region [ Interface ]

public:
    bool init() override;

#pragma endregion
};
}
