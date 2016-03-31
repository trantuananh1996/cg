#ifndef __STICK_H__
#define __STICK_H__


#define PI 3.14
#include <cmath>

class Vec2{
public:
    Vec2(float X, float Y){x = X; y = Y;}
    Vec2(){Vec2(0,0);}
    float x, y;
};

enum StickRole{
    SR_BODY = 0,
    SR_HAND_UPPER,
    SR_HAND_LOWER,

    SR_FOOT_UPPER,
    SR_FOOT_LOWER
};

class Stick{
public:    

    static void ShowStickMan();

    Stick(StickRole role, Stick * pPar = 0, float delay = 0.0);
    Vec2 head;    
    Vec2 tail();
    float len;
    float angle;
    Stick* parent;
    void tick(float dt);
private:
    float ratio();
    float roundTime;
    float time, digit;    
    StickRole role;
};

#endif //__STICK_H__
