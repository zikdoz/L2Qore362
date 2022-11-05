#pragma once

namespace Common::Database
{
class COMMON_EXPORT DBFactory
    : public QObject
    , public Common::Type::TSingleton< DBFactory >
    , public Common::Interface::IInitializable
{
    Q_OBJECT

private:
    static QThreadStorage< QSqlDatabase > s_db_pool;

#pragma region [ C/D-tor ]

public:
    DBFactory( SingletonCtorToken )
        : QObject() {}

    ~DBFactory() override = default;

#pragma endregion

#pragma region [ Interface ]

public:
    bool init() override;

#pragma endregion

#pragma region [ Utility ]

public:
    QSqlDatabase getConnection();

    void close();

#pragma endregion
};
}
