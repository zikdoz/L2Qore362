#pragma once

#ifdef __cplusplus

#pragma region [ STD ]

#include <algorithm>
#include <array>

#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstring>

#include <exception>

#include <fstream>
#include <functional>

#include <initializer_list>
#include <iostream>
#include <iterator>

#include <memory>

#include <stack>
#include <stdexcept>
#include <string>

#include <tuple>
#include <typeinfo>
#include <type_traits>

#include <utility>

#include <vector>

#pragma endregion

#pragma region [ Qt ]

#include <QFuture>
#include <QFutureWatcher>

#include <QtGlobal>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>

#include <QThreadPool>
#include <QThreadStorage>
#include <QThreadStorageData>
#include <QtSql>

#include <QUuid>

#pragma endregion

#pragma region [ Custom ]

#include "Common_global.h"

#include "interface/IInitializable.h"

#include "type/TSingleton.h"

#include "util/LoggerExt.h"

#pragma endregion

#pragma region [ Library ]

#include "spdlog/logger.h"
#include "spdlog/spdlog.h"

#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"

#pragma endregion

#pragma region [ Conditional ]

#pragma endregion

#endif
