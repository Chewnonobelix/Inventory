#ifndef VUE_GLOBAL_H
#define VUE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VUE_LIBRARY)
#  define VUESHARED_EXPORT Q_DECL_EXPORT
#else
#  define VUESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VUE_GLOBAL_H
