#ifndef BANDEDESSINE_GLOBAL_H
#define BANDEDESSINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BANDEDESSINE_LIBRARY)
#  define BANDEDESSINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define BANDEDESSINESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BANDEDESSINE_GLOBAL_H