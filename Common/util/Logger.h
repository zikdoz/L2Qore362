#pragma once

namespace Common
{
#ifndef CM_LOG
#   define CM_LOG Common::Logger::the()
#endif

class COMMON_EXPORT Logger
    : public QObject
    , public Common::Type::TSingleton< Logger >
    , public Common::Interface::IInitializable
{
    Q_OBJECT

#pragma region [ C/D-tor ]

public:
    Logger( SingletonCtorToken )
        : QObject() {}

    ~Logger() override = default;

#pragma endregion

#pragma region [ Interface ]

public:
    bool init() override;

#pragma endregion

#pragma region [ Utility ]

public:
    std::shared_ptr< spdlog::logger > setupRoot();

    std::shared_ptr< spdlog::logger > get( const std::string& logger_name );

private:
    const std::vector< spdlog::sink_ptr >& setupCommonSinks();

#pragma endregion
};
}
