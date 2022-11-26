#pragma once

#include "fmt/format.h"

template <>
struct fmt::formatter< QString >
{
    constexpr auto parse( format_parse_context& ctx ) -> decltype(ctx.begin())
    {
        return ctx.end();
    }

    template < typename FormatContext >
    auto format( const QString& str
               , FormatContext& ctx ) const -> decltype(ctx.out())
    {
        return fmt::format_to( ctx.out(), "{}", qUtf8Printable( str ) );
    }
};
