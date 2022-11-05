#pragma once

namespace Common::Util
{
#if defined(Q_OS_WIN)
constexpr bool isWindows() { return true; }

constexpr bool isLinux() { return false; }

constexpr bool isMac() { return false; }
#elif defined(Q_OS_LINUX)
constexpr bool isWindows() { return false; }

constexpr bool isLinux() { return true; }

constexpr bool isMac() { return false; }
#elif defined(Q_OS_MACOS)
constexpr bool isWindows() { return false; }

constexpr bool isLinux() { return false; }

constexpr bool isMac() { return true; }
#endif
}
