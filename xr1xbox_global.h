#ifndef XR1XBOX_GLOBAL_H
#define XR1XBOX_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XR1XBOX_LIBRARY)
#  define XR1XBOXSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XR1XBOXSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XR1XBOX_GLOBAL_H
