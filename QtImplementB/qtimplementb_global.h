#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTIMPLEMENTB_LIB)
#  define QTIMPLEMENTB_EXPORT Q_DECL_EXPORT
# else
#  define QTIMPLEMENTB_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTIMPLEMENTB_EXPORT
#endif
