#pragma once
#ifndef __TANK_H__
#define __TANK_H__
#include "cocos2d.h"
using namespace cocos2d;
#include "Bullet.h"
class Tank :public Sprite {
public:
    static Tank* create(const std::string& TankImage);
    virtual void update(float delta,  bool staticFlag);
    void moveleft();
    void moveright();
    void moveup();
    void movedown();
    void stopmoving();
    bool isReachBoundry();
    void deletetank();
    void speedup(float times);
private:
    Vec2 vec;
    Vec2 Tank_Current_Postion;
    int Lives;
    //Bullet* bullet;

};
#endif