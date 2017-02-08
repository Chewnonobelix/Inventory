#ifndef SERIE_GLOBAL_H
#define SERIE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SERIE_LIBRARY)
#  define SERIESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SERIESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SERIE_GLOBAL_H
