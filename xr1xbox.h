#ifndef XR1XBOX_H
#define XR1XBOX_H

#include "xr1xbox_global.h"
#include <QObject>
#include "qxboxcontroller.h"
#include "Eigen/Dense"

using namespace Eigen;
class XR1XBOXSHARED_EXPORT XR1XBox: public QObject
{
    Q_OBJECT
public:
    XR1XBox();

    Vector3d getXboxVelocity();

private:
    double Y_Speed;
    double X_Speed;
    double Z_CWSpeed;
    double Z_CCWSpeed;

    Vector3d XBoxVelocity;

    double speed_scale;

private slots:
    void handleQXBoxControllerAxisEvent(QXBoxControllerAxisEvent *event);
    void handleQXBoxControllerButtonEvent(QXBoxControllerButtonEvent *event);



};

#endif // XR1XBOX_H
