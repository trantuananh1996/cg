#ifndef __CAMERA_H__
#define __CAMERA_H__

enum CameraMode{
    CM_FOCUS = 0,
    CM_MOVE
};

class Camera{
public:
    Camera();
    static Camera* getInstance();
    void changeMode(CameraMode mode);

    void onChangeAxis(float dx, float dy);

    void updateCamera();

    float ex, ey, ez;
    float cx, cy, cz;
    float ux, uy, uz;
private:
    CameraMode _mode;

    static Camera* _instance;
};

#endif
