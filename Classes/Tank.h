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
    float setTankspeed(float speed);
    void setGod_mode(int God_mode_time);
    float Tank_Speed;
    bool isAlive() const;
    void speedup(float times);
    int God_mode;
private:
   // float Tank_Speed;
    Vec2 vec;
    Vec2 Tank_Current_Postion;
    int Lives;
    bool _isAlive = true;
    
    //≤‚ ‘
    
};
#endif