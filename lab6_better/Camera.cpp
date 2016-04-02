#include "Camera.h"
#include <GL/glut.h>

Camera* Camera::_instance = 0;

Camera* Camera::getInstance(){
    if (!_instance){
        _instance = new Camera();
    }

    return _instance;
}

Camera::Camera(){
    ex = ey = ez = 5;

    ux = uz = 0;
    uy = 1;

    cx = cy = cz = 2;
    _mode = CM_FOCUS;
}

void Camera::updateCamera(){    
    gluLookAt(5, ey, ez, cx, cy, cz, ux, uy, uz);
    glRotatef(-ex, 0, 1, 0);
}

void Camera::changeMode(CameraMode mode){

}

void Camera::onChangeAxis(float dx, float dy){
    if (_mode == CM_FOCUS){
        ex += dx * 10;
        ey += dy * .5;
    }
}
