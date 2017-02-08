#ifndef FILM_GLOBAL_H
#define FILM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FILM_LIBRARY)
#  define FILMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define FILMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FILM_GLOBAL_H
