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

#include <QApplication>

#include <QFileInfo>
#include <QFuture>
#include <QFutureWatcher>

#include <QMainWindow>

#include <QObject>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QString>
#include <QStringList>

#include <QtGlobal>
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

#include "util/Generics.h"
#include "util/LoggerExt.h"

#pragma endregion

#pragma region [ Library ]

#include "spdlog/logger.h"
#include "spdlog/spdlog.h"

#pragma endregion

#pragma region [ Conditional ]

#pragma endregion

#endif
