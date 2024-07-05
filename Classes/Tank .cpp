#include"Tank.h"
USING_NS_CC;
Tank* Tank::create(const std::string& TankImage) {
    Tank* tank = new (std::nothrow) Tank();
    if (tank && tank->initWithFile(TankImage)) {
        tank->autorelease();
        tank->Tank_Current_Postion = tank->getPosition();
        //tank->bullet=Bullet::create();
        return tank;
    }
    CC_SAFE_DELETE(tank);
    return nullptr;
}

void Tank::movedown() {
    vec = Vec2(0, -5.0f);
}
void Tank::moveup() {
    vec = Vec2(0, 5.0f);
}
void Tank::moveleft() {
    vec = Vec2(-5.0f, 0);
}
void Tank::moveright() {
    vec = Vec2(5.0f, 0);
}
void Tank::stopmoving() {
    vec = Vec2(0, 0);
}
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


