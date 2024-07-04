#include "Bullet.h"
USING_NS_CC;

Bullet*Bullet::create(const std::string& bulletImage) {
    Bullet* bullet = new (std::nothrow) Bullet();
    if (bullet && bullet->initWithFile(bulletImage)) {
        bullet->autorelease();
       
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return nullptr;
}
void Bullet::shoot() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    this->schedule([=](float dt) {
        auto newPosition = getPosition() + m_velocity * dt;
        if (newPosition.x < 0 || newPosition.x > visibleSize.width ||
            newPosition.y < 0 || newPosition.y > visibleSize.height) {
            unschedule("update_bullet");  
           deletebullet();
        }
        else {
            setPosition(newPosition);
        }
        }, "update_bullet");
}
void Bullet::shootFrom(Vec2 origin, float angle, float speed)
{
    setPosition(origin);
    m_speed = speed;
    m_velocity = Vec2::forAngle(CC_DEGREES_TO_RADIANS(angle)) * m_speed;
    shoot();
}
void Bullet::deletebullet() {
    auto boom = Sprite::create("boom_1.png");
    boom->setPosition(Bullet::getPosition());
    this->getParent()->addChild(boom);
    auto tankboom_animation = Animation::create();
    char nameSize[20] = { 0 };
    for (int i = 1; i < 4; i++)
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

    removeFromParentAndCleanup(true);
}

