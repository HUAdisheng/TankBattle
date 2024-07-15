#include"Tank.h"
USING_NS_CC;
Tank* Tank::create(const std::string& TankImage) {
    Tank* tank = new (std::nothrow) Tank();
    if (tank && tank->initWithFile(TankImage)) {
        tank->autorelease();
        tank->setTankspeed(2.5f);
        tank->Tank_Current_Postion = tank->getPosition();
        return tank;
    }
    CC_SAFE_DELETE(tank);
    return nullptr;
}
void Tank::speedup(float times)
{
    vec = Vec2(times * vec.x, times * vec.y);
}
float Tank::setTankspeed(float speed) {
    this->Tank_Speed = speed;
    return speed;
}
void Tank::movedown() {
    vec = Vec2(0, -Tank_Speed);
}
void Tank::moveup() {
    vec = Vec2(0, Tank_Speed);
}
void Tank::moveleft() {
    vec = Vec2(-Tank_Speed, 0);
}
void Tank::moveright() {
    vec = Vec2(Tank_Speed, 0);
}
void Tank::stopmoving() {
    vec = Vec2(0, 0);
}
void Tank::setGod_mode(int God_mode_time) {
    if (God_mode_time >= 0) {
        this->setOpacity(150);
        this->God_mode = God_mode_time;
    }
    else
        this->setOpacity(255);
};
bool Tank::isReachBoundry() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if (Tank::getPositionX() >= visibleSize.width || Tank::getPositionY() >= visibleSize.height)
        return true;
    return false;
}
void Tank::update(float delta, bool staticFlag) {
    if (!staticFlag) {
        Tank::setPosition(Tank::getPosition() + vec);
    }
}
void Tank::deletetank() {
    auto boom = Sprite::create("boom_1.png");
    boom->setPosition(Tank::getPosition());
    this->getParent()->addChild(boom);
    auto tankboom_animation = Animation::create();
    char nameSize[20] = { 0 };
    for (int i = 1; i < 6; i++)
    {
        sprintf(nameSize, "boom_%d.png", i);
        tankboom_animation->addSpriteFrameWithFile(nameSize);

    }
    tankboom_animation->setDelayPerUnit(0.08f);
    tankboom_animation->setLoops(1);
    tankboom_animation->setRestoreOriginalFrame(false);
    auto removeBoom = CallFunc::create([=]() {
        boom->removeFromParentAndCleanup(true);
        });
    auto tankboom_animate = Animate::create(tankboom_animation);
    auto sequence = Sequence::create(tankboom_animate, removeBoom, nullptr);
    boom->runAction(sequence);
}
bool Tank::isAlive() const
{
    return _isAlive;
}

