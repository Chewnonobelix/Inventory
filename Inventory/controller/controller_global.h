#ifndef CONTROLLER_GLOBAL_H
#define CONTROLLER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CONTROLLER_LIBRARY)
#  define CONTROLLERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CONTROLLERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CONTROLLER_GLOBAL_H
