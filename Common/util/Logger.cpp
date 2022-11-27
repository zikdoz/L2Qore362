#include "pch/pch.h"

#include "util/Logger.h"

namespace
{
const std::string root_logger_name = "root";
}

namespace Common
{
#pragma region [ Interface ]

bool Logger::init()
{
    setupRoot();

    return true;
}

#pragma endregion

#pragma region [ Utility ]

std::shared_ptr< spdlog::logger > Logger::setupRoot()
{
    const auto& sinks = setupCommonSinks();

    auto logger = spdlog::get( root_logger_name );

    if ( !logger )
    {
        if ( sinks.empty() )
        {
            return spdlog::stdout_logger_mt( root_logger_name );
        }

        logger = std::make_shared< spdlog::logger >( root_logger_name,
                                                     std::begin( sinks ),
                                                     std::end( sinks ) );
        spdlog::register_logger( logger );
    }

    return logger;
}

std::shared_ptr< spdlog::logger > Logger::get( const std::string& logger_name )
{
    auto logger = spdlog::get( logger_name );

    if ( !logger )
    {
        const auto root_logger = spdlog::get( root_logger_name );
        logger = root_logger->clone( logger_name );

        spdlog::register_logger( logger );
    }

    return logger;
}

#pragma region [ Private ]

const std::vector< spdlog::sink_ptr >& Logger::setupCommonSinks()
{
    const static std::vector< spdlog::sink_ptr > common_sinks
    {
        std::make_shared< spdlog::sinks::stdout_sink_mt >()
#ifdef CM_RELEASE
      , std::make_shared< spdlog::sinks::rotating_file_sink_mt >( "../../loginserver/log/output.log", 1024 * 1024 * 10, 5, true )
#else
      , std::make_shared< spdlog::sinks::rotating_file_sink_mt >( "log/output.log", 1024 * 1024 * 10, 5, true )
#endif
    };

    return common_sinks;
}

#pragma endregion

#pragma endregion
}
