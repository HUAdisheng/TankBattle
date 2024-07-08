#include "BulletPhysicsBody.h"

Sprite* BulletPhysicsBody::getUserData()
{
	return UserData;
}

void BulletPhysicsBody::setUserData(Sprite* data)
{
	UserData = data;
}

