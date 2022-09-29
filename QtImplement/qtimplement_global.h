#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTIMPLEMENT_LIB)
#  define QTIMPLEMENT_EXPORT Q_DECL_EXPORT
# else
#  define QTIMPLEMENT_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTIMPLEMENT_EXPORT
#endif
