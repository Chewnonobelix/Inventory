#ifndef JEUXFIGURINE_GLOBAL_H
#define JEUXFIGURINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JEUXFIGURINE_LIBRARY)
#  define JEUXFIGURINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define JEUXFIGURINESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // JEUXFIGURINE_GLOBAL_H