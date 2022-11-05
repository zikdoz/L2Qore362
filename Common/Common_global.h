#pragma once

namespace Common
{
#pragma region [ Macro ]

#if defined(COMMON_LIBRARY)
#  define COMMON_EXPORT __declspec(dllexport)
#else
#  define COMMON_EXPORT __declspec(dllimport)
#endif

#define ESC(x) x

#define TXT(x) #x

#define QSL(str) QStringLiteral(str)

// translation-helper macro
// should be detected by lupdate like qtTrId
// same as QT_TRID_NOOP (means it doesnt return actual translation like qtTrId)
#define zTrId(x) x

#define DELETE_PTR(obj) Common::Generics::DeletePtr((obj));
#define DELETE_ARR_PTR(arr) Common::Generics::DeleteArrPtr((arr));

#pragma endregion

#pragma region [ Generics ]

#define TYPE_ENABLE_IF(base, cond) base = typename std::enable_if_t< (cond) >
#define TYPE_IS_BASE_OF(base, derived) std::is_base_of_v<base, derived>

#pragma endregion
}
