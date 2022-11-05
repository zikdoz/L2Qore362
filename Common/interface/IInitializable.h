#pragma once

namespace Common::Interface
{
class IInitializable
{
public:
    virtual ~IInitializable() = default;

    virtual bool init() = 0;
};
}
