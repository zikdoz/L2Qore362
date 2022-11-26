#include "pch/pch.h"

#include "util/Logger.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/msvc_sink.h"
#include "spdlog/sinks/stdout_sinks.h"

namespace Common
{
#pragma region [ Interface ]

bool Logger::init()
{
    _common_logger = constructLogger( constructCommonSinks() );

    _common_logger->debug( "test-test-test" );

    return true;
}

#pragma endregion

#pragma region [ Utility ]

std::vector< spdlog::sink_ptr > Logger::constructCommonSinks()
{
    const static std::vector< spdlog::sink_ptr > common_sinks
    {
#ifdef Q_OS_WIN
        std::make_shared< spdlog::sinks::msvc_sink_mt >()
#else
        std::make_shared< spdlog::sinks::stdout_sink_mt >()
#endif
#ifdef LQ_RELEASE
      , std::make_shared< spdlog::sinks::basic_file_sink_mt >( "../../loginserver/log/test.log", true )
#else
      , std::make_shared< spdlog::sinks::basic_file_sink_mt >( "log/test.log", true )
#endif
    };

    return common_sinks;
}

std::shared_ptr< spdlog::logger > Logger::constructLogger( std::vector< spdlog::sink_ptr > sinks )
{
    auto logger = spdlog::get( Logging::log_common );

    if ( !logger )
    {
        if ( sinks.empty() )
        {
            return spdlog::stdout_logger_mt( Logging::log_common );
        }

        logger = std::make_shared< spdlog::logger >( Logging::log_common,
                                                     std::begin( sinks ),
                                                     std::end( sinks ) );
        spdlog::register_logger( logger );
    }

    return logger;
}

#pragma endregion

#pragma region [ Accessor ]

std::shared_ptr< spdlog::logger > Logger::getCommon()
{
    return _common_logger;
}

#pragma endregion
}
