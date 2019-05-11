#pragma once

#if defined(BUILDING_COMMON_DLL)
#define SYMBOLS_EXPORT Q_DECL_EXPORT
#else
#define SYMBOLS_EXPORT Q_DECL_IMPORT
#endif
