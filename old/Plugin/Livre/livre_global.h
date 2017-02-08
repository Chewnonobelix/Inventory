#ifndef LIVRE_GLOBAL_H
#define LIVRE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIVRE_LIBRARY)
#  define LIVRESHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIVRESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIVRE_GLOBAL_H
