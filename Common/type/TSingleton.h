#pragma once

namespace Common::Type
{
template < typename TSingletonClass >
class TSingleton
{
#pragma region [ C/D-tor ]

protected:
    struct SingletonCtorToken {};

    TSingleton() = default;
    ~TSingleton() = default;

#pragma endregion

#pragma region [ Copy/move ]

public:
    TSingleton( const TSingleton< TSingletonClass >& ) = delete;
    void operator=( const TSingleton< TSingletonClass >& ) = delete;

    TSingleton( TSingleton< TSingletonClass >&& ) = delete;
    TSingleton& operator=( TSingleton< TSingletonClass >&& ) = delete;

#pragma endregion

public:
    static TSingletonClass& the()
    {
        static TSingletonClass singleton_instance{ SingletonCtorToken{} };
        return singleton_instance;
    }
};
}
