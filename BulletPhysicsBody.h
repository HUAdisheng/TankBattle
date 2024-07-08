#pragma once
#include "Bullet.h"
#include "cocos2d.h"
USING_NS_CC;

class BulletPhysicsBody: public PhysicsBody
{
public:
	Sprite* getUserData();
	void setUserData(Sprite* data);

private:
	Sprite* UserData;
};

