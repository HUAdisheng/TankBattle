#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

class Bullet : public cocos2d::Sprite
{
public:
    static Bullet* create(const std::string& bulletImage);

    void shootFrom(cocos2d::Vec2 origin, float angle, float speed);

    void shoot();
    void deletebullet();


private:
    float m_speed;
    cocos2d::Vec2 m_velocity;

};

#endif // __BULLET_H__