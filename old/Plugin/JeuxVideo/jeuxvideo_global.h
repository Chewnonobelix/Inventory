#ifndef JEUXVIDEO_GLOBAL_H
#define JEUXVIDEO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JEUXVIDEO_LIBRARY)
#  define JEUXVIDEOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define JEUXVIDEOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // JEUXVIDEO_GLOBAL_H
