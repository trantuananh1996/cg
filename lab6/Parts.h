#define PI 3.14
#include <cmath>

class Vec2{
public:
    Vec2(float X, float Y){x = X; y = Y;}
    Vec2(){Vec2(0,0);}
    float x, y;
};

class Part {
public:
    Vec2 head;
    float angle;
    float len;
    Vec2 getTail(){return Vec2(head.x + cos(angle) * len,
                               head.y + sin(angle) * len);}
    int tag;

    virtual void tick(float){}
protected:
    Part *_parent;
    float _time;
    float _digit;
    float _roundTime;
    void checkEnd();
};


class BodyPart : public Part{
public:
    BodyPart();
    virtual void tick(float dt);

};


class ArmPart : public Part{
public:
    ArmPart(Part*, float delay = 0);
    virtual void tick(float dt);
};

class HandPart: public Part{
public:
    HandPart(Part* parent, float delay = 0);
    virtual void tick(float dt);

};


class UpLeg : public Part{
public:
    UpLeg(Part * parent, float delay = 0);
    virtual void tick(float);
};

class LowLeg : public Part{
public:
    LowLeg(Part * parent, float delay = 0);
    virtual void tick(float);
};
