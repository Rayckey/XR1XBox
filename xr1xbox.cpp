#include "xr1xbox.h"
#include <QTimer>


XR1XBox::XR1XBox()
{
        QXBoxController * X_ptr;


        Y_Speed           = 0;
        X_Speed           = 0;
        Z_CWSpeed         = 0;
        Z_CCWSpeed       = 0;

        XBoxVelocity << 0 , 0 , 0;

        // In case you have a lot of controllers
        // There you go
        for (int i = 0; i < 10; i++)
        {
            X_ptr = new QXBoxController(i, this);
            if (X_ptr->isValid())
            {
                connect(X_ptr, SIGNAL(XBoxControllerAxisEvent(QXBoxControllerAxisEvent*)), this, SLOT(handleQXBoxControllerAxisEvent(QXBoxControllerAxisEvent*)));
                connect(X_ptr, SIGNAL(XBoxControllerButtonEvent(QXBoxControllerButtonEvent*)), this, SLOT(handleQXBoxControllerButtonEvent(QXBoxControllerButtonEvent*)));

                QTimer *timer = new QTimer(this);
                timer->setInterval(10);

                connect(timer, SIGNAL(timeout()), X_ptr, SLOT(readXBoxController()));
                timer->start();
            }
            else
            {
                delete X_ptr;
            }
        }

        speed_scale = 0.2;

}




void XR1XBox::handleQXBoxControllerAxisEvent(QXBoxControllerAxisEvent *event){

    uint axis = event->axis();

    if(axis == 3){
        X_Speed = event->value()*speed_scale;
    }

    else if(axis == 4){
        Y_Speed = -event->value()*speed_scale;
    }

    if(axis == 5){
        Z_CWSpeed = event->value()*speed_scale + 1.0;
    }

    else if(axis == 2){
        Z_CCWSpeed = event->value()*speed_scale + 1.0;
    }

    delete event;   //not deleted automatically.

}

void XR1XBox::handleQXBoxControllerButtonEvent(QXBoxControllerButtonEvent *event){
    delete event;
}


Vector3d XR1XBox::getXboxVelocity(){


    XBoxVelocity(0) = X_Speed;
    XBoxVelocity(1) = Y_Speed;

    XBoxVelocity(2) = Z_CCWSpeed - Z_CWSpeed;

    return XBoxVelocity;
}
