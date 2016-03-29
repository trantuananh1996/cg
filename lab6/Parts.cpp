#include "Parts.h"

void Part::checkEnd(){
    if (_time > _roundTime){
        _digit = -1;
    }
    if (_time < 0){
        _digit = 1;
    }
}

BodyPart::BodyPart(){
    head = Vec2(.2, .6);
    angle = -PI/2;
    len = .3;
    _time = 0;
    _roundTime = 4.0f;
}


void BodyPart::tick(float dt){
    _time += dt;
    float ratio = _time / _roundTime;
    head = Vec2(.2 + .6*ratio, .6);
    _time = _time > 4.0f ? 0 : _time;
}

ArmPart::ArmPart(Part *pPar, float delay){
    _parent = pPar;
    head = pPar->head;
    angle = 5.0*PI/4.0;
    len = .1;
    _time = delay;
    _digit = 1;
    _roundTime = 1.0f;
}

void ArmPart::tick(float dt){
    _time += dt * _digit;
    float ratio = _time/_roundTime;
    head = _parent->head;
    angle = 1.4*PI + PI*.2f * ratio;

    checkEnd();
}


HandPart::HandPart(Part *pPar, float delay){
    _parent = pPar;
    head = pPar->getTail();
    angle = 5.0*PI/4.0;
    len = .05;
    _time = delay;
    _digit = 1;
    _roundTime = 1.0f;
}


void HandPart::tick(float dt){
    _time += dt * _digit;
    float ratio = _time/_roundTime;

    head = _parent->getTail();
    angle = _parent->angle + PI*.2f * ratio;

    checkEnd();
}
