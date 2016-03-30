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

Vec2 Stick::tail(){
    return Vec2(head.x + cos(angle)* len,
                head.y + sin(angle) * len);
}

Stick::Stick(StickRole role, Stick *pPar, float delay){
    this->role = role;
    parent = pPar;
    time = delay;
    digit = 1;
    angle = 0;

    tick(0.0);
}

float Stick::ratio(){
    return time/roundTime;
}


void Stick::tick(float dt){
    time += digit * dt;
    switch (role){
    case SR_BODY:{
        roundTime = 4.0f;
        len = .3;

        angle = -PI/2;
        head = Vec2(.2 + .6 * ratio(), .6);


        break;
    }
    case SR_HAND_UPPER:{
        roundTime = 1.0f;
        len = .1;

        head = parent->head;
        angle = 1.4 * PI + PI*.2f * ratio();
        break;
    }
    case SR_HAND_LOWER:{
        roundTime = 1.0f;
        len = .05;

        head = parent->tail();
        angle = parent->angle + PI*.2f * ratio();
        break;
    }
    case SR_FOOT_UPPER:{
        roundTime = 1.0f;
        len = .1;

        head = parent->tail();
        angle = parent->angle - .05*PI + PI*.15f * ratio();
        break;
    }
    case SR_FOOT_LOWER:{
        roundTime = 1.0;
        len = .1;

        head= parent->tail();
        angle = parent->angle + .02*PI - PI*.17f * ratio();
        break;
    }
    }

    digit = time > roundTime ? -1 : digit;
    digit = time < 0 ? 1 : digit;
}
