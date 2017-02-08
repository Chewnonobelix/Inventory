#ifndef PATTERN_GLOBAL_H
#define PATTERN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PATTERN_LIBRARY)
#  define PATTERNSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PATTERNSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PATTERN_GLOBAL_H
