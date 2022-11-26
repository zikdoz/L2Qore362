#pragma once

namespace Common
{
namespace Logging
{
static const std::string log_common = "log_common";
}

class COMMON_EXPORT Logger
    : public QObject
    , public Common::Type::TSingleton< Logger >
    , public Common::Interface::IInitializable
{
    Q_OBJECT

private:
    std::shared_ptr< spdlog::logger > _common_logger;

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
    std::vector< spdlog::sink_ptr > constructCommonSinks();

    std::shared_ptr< spdlog::logger > constructLogger( std::vector< spdlog::sink_ptr > sinks );

#pragma endregion

#pragma region [ Accessor ]

public:
    std::shared_ptr< spdlog::logger > getCommon();

#pragma endregion
};
}
