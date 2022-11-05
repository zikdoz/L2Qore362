#pragma once

namespace Common::Generics
{
template < class TManager >
bool initSingleton()
{
    const auto init_result = TManager::the().init();

    if ( !init_result )
    {
        // TODO: log it ?

        return false;
    }

    return true;
}

template < class TObj >
constexpr void DeletePtr( TObj* & obj )
{
    delete obj;
    obj = nullptr;
}

template < class TArr >
constexpr void DeleteArrPtr( TArr* & arr )
{
    delete[] arr;
    arr = nullptr;
}
}
