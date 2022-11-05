#pragma once

namespace Common::Enum
{
enum class EServerAttr
{
    LIST_STATUS = 0x01
  , TYPE = 0x02
  , LIST_BRACKETS = 0x03
  , MAX_PLAYERS = 0x04
  , AGE_RESTRICTION = 0x05
};

enum class EServerStatus
{
    AUTO = 0x00
  , GOOD = 0x01
  , NORMAL = 0x02
  , FULL = 0x03
  , DOWN = 0x04
  , GM_ONLY = 0x05
};

enum class EServerType
{
    NORMAL = 1 << 0
  , RELAX = 1 << 1
  , TEST = 1 << 2
  , NO_LABEL = 1 << 3
  , CREATION_RESTRICTION = 1 << 4
  , EVENT = 1 << 5
  , FREE = 1 << 6
};

enum class EServerAge
{
    ALL = 0x0

  , OVER_15 = 0x0F
  , OVER_18 = 0x12
};

enum class EServerState
{
    OFF = 0x00
  , ON = 0x01
};
}
