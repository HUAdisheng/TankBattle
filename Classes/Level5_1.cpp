#include "Level5_1.h"
USING_NS_CC;
Scene* Level5_1::createScene()
{
    return Level5_1::create();
}
Vec2 Level5_1::calculation(Tank* tank) {
    auto newPosition = tank->getPosition();
    auto r = tank->getRotation();
    auto size = tank->getContentSize();
    auto offset = tank->getScale() * size.height / 2+20;
    if (r == 0.0f) {
        newPosition += Vec2(0, offset);
    }
    if (r == 180.0f) {
        newPosition -= Vec2(0, offset);
    }
    if (r == 90.0f) {
        newPosition += Vec2(offset, 0);
    }
    if (r == -90.0f) {
        newPosition -= Vec2(offset, 0);
    }
    return newPosition;
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
void Level5_1::Pausemenu()
{
    Level5_1::unscheduleUpdate();
    listener->setEnabled(false);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    AudioEngine::pauseAll();
    auto sprite = Sprite::create("pausemenu.PNG");
    sprite->setScale(visibleSize.width / sprite->getContentSize().width, visibleSize.height / sprite->getContentSize().height);
    if (sprite == nullptr)
    {
        problemLoading("'pausemenu.PNG'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0, 7);
    }

    auto labelcontinue = Label::createWithTTF("continue", "fonts/Marker Felt.ttf", 60);
    if (labelcontinue == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        labelcontinue->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 + 2 * labelcontinue->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(labelcontinue, 0, 1);
    }

    auto buttoncontinue = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//NEW GAME
    buttoncontinue->setScale(visibleSize.width / buttoncontinue->getContentSize().width / 21, visibleSize.height / buttoncontinue->getContentSize().height / 16);
    buttoncontinue->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (labelcontinue->getContentSize().width / 2) - buttoncontinue->getContentSize().width,
        origin.y + (visibleSize.height) / 2 + 2 * labelcontinue->getContentSize().height));
    buttoncontinue->setPressedActionEnabled(true);
    buttoncontinue->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttoncontinueCallback, this));
    this->addChild(buttoncontinue, 0, 2);

    auto labelselectL = Label::createWithTTF("select level", "fonts/Marker Felt.ttf", 60);
    if (labelselectL == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        labelselectL->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2));

        // add the label as a child to this layer
        this->addChild(labelselectL, 0, 3);
    }

    auto buttonselectL = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//NEW GAME
    buttonselectL->setScale(visibleSize.width / buttonselectL->getContentSize().width / 21, visibleSize.height / buttonselectL->getContentSize().height / 16);
    buttonselectL->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (labelselectL->getContentSize().width / 2) - buttonselectL->getContentSize().width,
        origin.y + (visibleSize.height) / 2));
    buttonselectL->setPressedActionEnabled(true);
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttonselectLCallback, this));
    this->addChild(buttonselectL, 0, 4);

    auto labelBack = Label::createWithTTF("go back to the start menu", "fonts/Marker Felt.ttf", 60);
    if (labelBack == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        labelBack->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - 2 * labelBack->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(labelBack, 0, 5);
    }

    auto buttonBack = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//NEW GAME
    buttonBack->setScale(visibleSize.width / buttonBack->getContentSize().width / 21, visibleSize.height / buttonBack->getContentSize().height / 16);
    buttonBack->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (labelBack->getContentSize().width / 2) - buttonBack->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - 2 * labelBack->getContentSize().height));
    buttonBack->setPressedActionEnabled(true);
    buttonBack->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttonbackCallback, this));
    this->addChild(buttonBack, 0, 6);



}
//去选择关卡界面
void Level5_1::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
        AudioEngine::stopAll();
        auto hello = LevelSelected::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
//游戏继续
void Level5_1::buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    Level5_1:scheduleUpdate();
    AudioEngine::resumeAll();
    listener->setEnabled(true);
    this->removeChildByTag(1);
    this->removeChildByTag(2);
    this->removeChildByTag(3);
    this->removeChildByTag(4);
    this->removeChildByTag(5);
    this->removeChildByTag(6);
    this->removeChildByTag(7);
}
//去主菜单
void Level5_1::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        
        auto tryagain = FirstScene::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level5_1::buttontryCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        auto tryagain = Level5_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level5_1::buttonnextCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        
        auto next = Level6_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, next);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level5_1::Fire(cocos2d::Vec2 origin, float angle, float speed,int type) {
    if (cocos2d::Director::getInstance()->getTotalFrames() / 60 - lastFireTime >= 0 || m_bullet.size() <= 2) {
        if (type == 1)
        {
            m_bullet.push_back(Bullet::create("bullet.png"));
            m_bullet[m_bullet.size() - 1]->setScale(0.5);
        }
        else if (type == 2)
        {

            m_bullet.push_back(Bullet::create("apple.png"));
            m_bullet[m_bullet.size() - 1]->settype(2);
            m_bullet[m_bullet.size() - 1]->setScale(1.5);
        }
        
        this->addChild(m_bullet[m_bullet.size() - 1]);

        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    lastFireTime = cocos2d::Director::getInstance()->getTotalFrames() / 60;
}
int Level5_1::getType(Vec2 pos)
{
    float x = (pos.x - offsetX) / tileSize / scale;
    float y = (mapy - 1) - (pos.y - offsetY) / tileSize / scale;
    if (y < 0)
        y--;
    if (x < 0)
        x--;
    ix = (int)x;
    iy = (int)y;

    switch (map[iy + 1][ix]) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10:
        return 10;
    default:
        return 0;
    }
}
bool Level5_1::willContact(Vec2 vec)
{
    // 获取坦克位置信息与尺寸
    Rect rect = tank->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();

    // 计算坦克的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

    Vec2 point[4];
    point[0] = Vec2(MinX + vec.x, MinY + vec.y);
    point[1] = Vec2(MinX + vec.x, MaxY + vec.y);
    point[2] = Vec2(MaxX + vec.x, MinY + vec.y);
    point[3] = Vec2(MaxX + vec.x, MaxY + vec.y);
    for (int i = 0; i < 4; i++) {
        switch (getType(point[i])) {
        case 2:
            return true;


        default:
            continue;
        }
    }
    return false;
}
void Level5_1::willContactOther(Vec2 vec)
{
    // 获取坦克位置信息与尺寸
    Rect rect = tank->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();

    // 计算坦克的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

    Vec2 point[4];
    point[0] = Vec2(MinX + vec.x, MinY + vec.y);
    point[1] = Vec2(MinX + vec.x, MaxY + vec.y);
    point[2] = Vec2(MaxX + vec.x, MinY + vec.y);
    point[3] = Vec2(MaxX + vec.x, MaxY + vec.y);
    for (int i = 0; i < 4; i++) {
        switch (getType(point[i]))
        {
        
        
        }
    }
    return;
}
void Level5_1::ContactBullet()
{
    for (int i = 0; i < m_bullet.size(); i++)
    {
        if (willContactBullet(m_bullet[i])) 
        {
            Vec2 pos = m_bullet[i]->getPosition();
            destroyMap(m_bullet[i]);
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
        }
        else if (tank->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox())) 
        {
            if (!godtype)
            {
                m_bullet[i]->deletebullet();
                m_bullet.erase(m_bullet.begin() + i);
                tank->deletetank();
                lifepoint--;
                godtype = true;
                tank->setOpacity(150);
                tank->God_mode = 180;
                auto delay1 = DelayTime::create(3.0f);
                auto callFunc1 = CallFunc::create(CC_CALLBACK_0(Level5_1::godmodecancel, this));
                auto sequence1 = Sequence::create(delay1, callFunc1, nullptr);
                this->runAction(sequence1);
            }
        }
        else 
        {
                if (apple_boss->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox()))
                {
                    if (m_bullet[i]->gettype() == 1)
                    {
                        m_bullet[i]->deletebullet();
                        m_bullet.erase(m_bullet.begin() + i);
                        boss_lp--;
                    }
                }

            
            
        }
        /*else
        {
            for (int j = i + 1; j < m_bullet.size(); j++) 
            {
                if (m_bullet[i]->getBoundingBox().intersectsRect(m_bullet[j]->getBoundingBox())) 
                {
                    m_bullet[i]->deletebullet();
                    m_bullet[j]->deletebullet();
                    m_bullet.erase(m_bullet.begin() + i);
                    if (i < j) 
                    {
                        j--;
                    }
                    m_bullet.erase(m_bullet.begin() + j);
                    break;
                }
            }

        }*/
    }
}
void Level5_1::destroyMap(Bullet* bullet)
{
    Rect rect = bullet->getBoundingBox();

    //将bulletY坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();

    // 计算bullet的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();
    Sprite* sprite;
    Vec2 Position;
    Vec2 point[4];
    point[0] = Vec2(MinX, MinY);
    point[1] = Vec2(MinX, MaxY);
    point[2] = Vec2(MaxX, MinY);
    point[3] = Vec2(MaxX, MaxY);
    for (int i = 0; i < 4; i++) {
        float x = (point[i].x - offsetX) / tileSize / scale;
        float y = (mapy - 1) - (point[i].y - offsetY) / tileSize / scale;
        if (y > 0)
            y++;
        int ix = (int)x;
        int iy = (int)y;
        switch (map[iy][ix]) {
            // 此处根据方块类型执行方块摧毁的操作 
        case 2:

            break;
        default:
            continue;
        }
    }
}
bool Level5_1::willContactBullet(Bullet* bullet)
{
    // 获取子弹位置信息与尺寸
    Rect rect = bullet->getBoundingBox();


    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

    Vec2 point[4];
    point[0] = Vec2(MinX, MinY);
    point[1] = Vec2(MinX, MaxY);
    point[2] = Vec2(MaxX, MinY);
    point[3] = Vec2(MaxX, MaxY);
    for (int i = 0; i < 4; i++) {
        switch (getType(point[i])) {
        case 2:
            return true;
        default:
            continue;
        }
    }
    return false;
}
void Level5_1::godmodecancel()
{
    tank->setOpacity(255);
    godtype = false;
}
void Level5_1::boss_skill_1()//left
{
    for (int i = 1; i < 20; i = i + 2)
    {
        this->Fire(Vec2(physicsbody[i][0]->getBoundingBox().getMidX() + physicsbody[i][0]->getContentSize().width+20, physicsbody[i][0]->getBoundingBox().getMidY())
            , 0, applespeed, 2);
    }
}
void Level5_1::boss_skill_2()
{
    Vec2 pos = apple_boss->getPosition();
    for (int i = 0; i < 18; i++)
    {
        this->Fire(pos, 20.0f*i, applespeed-150, 2);
    }
}
void Level5_1::boss_skill_3()//bottom
{
    for (int i = 1; i < 26; i = i + 2)
    {
        this->Fire(Vec2(physicsbody[19][i]->getBoundingBox().getMidX() , physicsbody[19][i]->getBoundingBox().getMidY()+ physicsbody[19][i]->getContentSize().height + 20)
            , 90.0f, applespeed, 2);
    }
}
void Level5_1::removeSeparation() {
    if (boss[boss_separation-1]) 
    {
        this->removeChild(boss[boss_separation-1]);
        boss.pop_back();
        boss_separation--;
    }
}
void Level5_1::boss_skill_4()
{
    targetpos = tank->getPosition();
    bossmove = true;
    apple_boss->runAction(MoveTo::create(1.0f, targetpos));
    Vec2 bosspos = apple_boss->getPosition();
    
    Tank* separation1 = Tank::create("apple_boss.png");
    separation1->setScale(scale * 2.0f);
    separation1->setPosition(Vec2(1 * tileSize * scale + offsetX + separation1->getContentSize().width / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + separation1->getContentSize().height / 2));
    this->addChild(separation1);
    boss.push_back(separation1);
    boss_separation++;

    Tank* separation2 = Tank::create("apple_boss.png");
    separation2->setScale(scale * 2.0f);
    separation2->setPosition(Vec2(23 * tileSize * scale + offsetX + separation2->getContentSize().width/2, (mapy - 1 - 1) * tileSize * scale + offsetY + separation2->getContentSize().height / 2));
    this->addChild(separation2);
    boss.push_back(separation2);
    boss_separation++;

    Tank* separation3 = Tank::create("apple_boss.png");
    separation3->setScale(scale * 2.0f);
    separation3->setPosition(Vec2(23 * tileSize * scale + offsetX + separation3->getContentSize().width / 2, (mapy - 1 - 17) * tileSize * scale + offsetY + separation3->getContentSize().height / 2));
    this->addChild(separation3);
    boss.push_back(separation3);
    boss_separation++;

    Tank* separation4 = Tank::create("apple_boss.png");
    separation4->setScale(scale * 2.0f);
    separation4->setPosition(Vec2(1 * tileSize * scale + offsetX + separation4->getContentSize().width / 2, (mapy - 1 - 17) * tileSize * scale + offsetY + separation4->getContentSize().height / 2));
    this->addChild(separation4);
    boss.push_back(separation4);
    boss_separation++;
   
        auto call1 = CallFunc::create(CC_CALLBACK_0(Level5_1::removeSeparation, this));
        Sequence* sequence1 = Sequence::create(MoveTo::create(1.5f, targetpos), call1, nullptr);
        auto call2 = CallFunc::create(CC_CALLBACK_0(Level5_1::removeSeparation, this));
        Sequence* sequence2 = Sequence::create(MoveTo::create(1.5f, targetpos), call2, nullptr);
        auto call3 = CallFunc::create(CC_CALLBACK_0(Level5_1::removeSeparation, this));
        Sequence* sequence3 = Sequence::create(MoveTo::create(1.5f, targetpos), call3, nullptr);
        auto call4 = CallFunc::create(CC_CALLBACK_0(Level5_1::removeSeparation, this));
        Sequence* sequence4 = Sequence::create(MoveTo::create(1.5f, targetpos), call4, nullptr);
        boss[4]->runAction(sequence4);
        boss[3]->runAction(sequence3);
        boss[2]->runAction(sequence2);
        boss[1]->runAction(sequence1);
}
void Level5_1::boss_skill()
{
    for (int i = 1; i < 26; i = i + 2)
    {
        this->Fire(Vec2(physicsbody[0][i]->getBoundingBox().getMidX() , physicsbody[0][i]->getBoundingBox().getMidY() - physicsbody[0][i]->getContentSize().height - 20)
            , -90.0f, applespeed, 2);
    }
    //创建一个延时动作，持续x秒
    auto delay1 = DelayTime::create(4.0f);
    auto callFunc1 = CallFunc::create(CC_CALLBACK_0(Level5_1::boss_skill_1, this));
    auto sequence1 = Sequence::create(delay1, callFunc1, nullptr);
    this->runAction(sequence1);

    auto delay2 = DelayTime::create(8.0f);
    auto callFunc2 = CallFunc::create(CC_CALLBACK_0(Level5_1::boss_skill_2, this));
    auto sequence2 = Sequence::create(delay2, callFunc2, nullptr);
    this->runAction(sequence2);
    
    auto delay3 = DelayTime::create(6.0f);
    auto callFunc3 = CallFunc::create(CC_CALLBACK_0(Level5_1::boss_skill_3, this));
    auto sequence3 = Sequence::create(delay3, callFunc3, nullptr);
    this->runAction(sequence3);
    
    if (boss_lp <= 150)
    {
        
        auto callFunc4 = CallFunc::create(CC_CALLBACK_0(Level5_1::boss_skill_4, this));
        auto sequence4 = Sequence::create(delay1, callFunc4, nullptr);
        this->runAction(sequence4);
    }
}
void Level5_1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    Keystate[keyCode] = true;
    switch (keyCode) {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
        ks = KEY_A_PRESSED;
        tank->setRotation(-90.0f);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
        ks = KEY_S_PRESSED;
        tank->setRotation(180.0f);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        ks = KEY_D_PRESSED;
        tank->setRotation(90.0f);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_W:
        ks = KEY_W_PRESSED;
        tank->setRotation(0.0f);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_J:
        this->Fire(calculation(tank), -tank->getRotation() + 90.0f, 1000,1);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_P:
        ks = KEY_P_PRESSED;
        Pausemenu();
        break;
    defalut:
        auto rotateBy = RotateBy::create(delta, 0.0f);
        tank->runAction(rotateBy);
        break;
    }
}
void Level5_1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    Keystate[keyCode] = false;
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_A]) {
        tank->setRotation(-90.0f);
        ks = KEY_A_PRESSED;
    }
    else if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_S]) {
        tank->setRotation(180.0f);
        ks = KEY_S_PRESSED;
    }
    else if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_D]) {
        tank->setRotation(90.0f);
        ks = KEY_D_PRESSED;
    }
    else if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_W]) {
        tank->setRotation(0.0f);
        ks = KEY_W_PRESSED;
    }
}
void Level5_1::event_gameover()
{
        Level5_1::unscheduleUpdate();
        AudioEngine::stopAll();
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();

        auto label1 = Label::createWithTTF("Game over:(", "fonts/Marker Felt.ttf", 60);
        if (label1 == nullptr)
        {
            problemLoading("'fonts/Marker Felt.ttf'");
        }
        else
        {
            // position the label on the center of the screen
            label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
                origin.y + (visibleSize.height) / 2));

            // add the label as a child to this layer
            this->addChild(label1);
        }
        auto label2 = Label::createWithTTF("try again", "fonts/Marker Felt.ttf", 60);
        if (label2 == nullptr)
        {
            problemLoading("'fonts/Marker Felt.ttf'");
        }
        else
        {
            // position the label on the center of the screen
            label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
                origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));

            // add the label as a child to this layer
            this->addChild(label2);
        }
        auto buttontry = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
        buttontry->setScale(visibleSize.width / buttontry->getContentSize().width / 21, visibleSize.height / buttontry->getContentSize().height / 16);
        buttontry->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label2->getContentSize().width / 2) - buttontry->getContentSize().width,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));
        buttontry->setPressedActionEnabled(true);
        buttontry->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttontryCallback, this));
        this->addChild(buttontry);
        auto label3 = Label::createWithTTF("go back to the start menu", "fonts/Marker Felt.ttf", 60);
        if (label3 == nullptr)
        {
            problemLoading("'fonts/Marker Felt.ttf'");
        }
        else
        {
            // position the label on the center of the screen
            label3->setPosition(Vec2(origin.x + visibleSize.width / 2,
                origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label2->getContentSize().height));

            // add the label as a child to this layer
            this->addChild(label3);
        }
        auto buttonback = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
        buttonback->setScale(visibleSize.width / buttonback->getContentSize().width / 21, visibleSize.height / buttonback->getContentSize().height / 16);
        buttonback->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label3->getContentSize().width / 2) - buttonback->getContentSize().width,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label2->getContentSize().height));
        buttonback->setPressedActionEnabled(true);
        buttonback->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttonbackCallback, this));
        this->addChild(buttonback);
    
}
void Level5_1::event_win()//游戏win!
{
    AudioEngine::stopAll();
    Level5_1::unscheduleUpdate();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label1 = Label::createWithTTF("WIN!!", "fonts/Marker Felt.ttf", 60);
    if (label1 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2));

        // add the label as a child to this layer
        this->addChild(label1);
    }
    auto label2 = Label::createWithTTF("Next Level", "fonts/Marker Felt.ttf", 60);
    if (label2 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label2);
    }
    auto buttonnext = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    buttonnext->setScale(visibleSize.width / buttonnext->getContentSize().width / 21, visibleSize.height / buttonnext->getContentSize().height / 16);
    buttonnext->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label2->getContentSize().width / 2) - buttonnext->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));
    buttonnext->setPressedActionEnabled(true);
    buttonnext->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttonnextCallback, this));
    this->addChild(buttonnext);
    auto label3 = Label::createWithTTF("go back to the start menu", "fonts/Marker Felt.ttf", 60);
    if (label3 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label3->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label2->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label3);
    }
    auto buttonback = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    buttonback->setScale(visibleSize.width / buttonback->getContentSize().width / 21, visibleSize.height / buttonback->getContentSize().height / 16);
    buttonback->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label3->getContentSize().width / 2) - buttonback->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label2->getContentSize().height));
    buttonback->setPressedActionEnabled(true);
    buttonback->addTouchEventListener(CC_CALLBACK_2(Level5_1::buttonbackCallback, this));
    this->addChild(buttonback);
};
void Level5_1::update(float delta) {

    //player
    this->delta = delta;
    bool staticflag = false;
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_A] == false &&
        Keystate[cocos2d::EventKeyboard::KeyCode::KEY_S] == false &&
        Keystate[cocos2d::EventKeyboard::KeyCode::KEY_D] == false &&
        Keystate[cocos2d::EventKeyboard::KeyCode::KEY_W] == false)
    {
        tank->stopmoving();
    }
    else {
        switch (ks) {
        case KEY_A_PRESSED:
            staticflag = willContact(Vec2(-2.5f, 0));
            tank->moveleft();
            break;
        case KEY_S_PRESSED:
            staticflag = willContact(Vec2(0, -2.5f));
            tank->movedown();
            break;
        case KEY_D_PRESSED:
            staticflag = willContact(Vec2(2.5f, 0));
            tank->moveright();
            break;
        case KEY_W_PRESSED:
            staticflag = willContact(Vec2(0, 2.5f));
            tank->moveup();
            break;
        case KEY_P_PRESSED:
            tank->stopmoving();
            break;
        }
    }
    if (lifepoint <= 0)
    {
        
        event_gameover();
    }
    
    if (boss_lp <= 0)
    {
        apple_boss->deletetank();
        apple_boss->setTexture("apple_boss_cry.png");
        event_win();
    }
    else if (boss_lp < 150)
    {
        apple_boss->setTexture("apple_boss_angry.png");
        if(applespeed==200)
            applespeed += 50;
    }
    ContactBullet();
    tank->update(delta, staticflag);
    //willContactOther(Vec2(0, 0));
    //chaser
    float playx = targetpos.x;
    float playy = targetpos.y;
    float chaserx = apple_boss->getPositionX();
    float chasery = apple_boss->getPositionY();
    float distancex = playx - chaserx;
    float distancey = playy - chasery;
    float l = sqrt(distancex * distancex + distancey * distancey);
    //skill
    elapsedTime += delta;
    if (elapsedTime >= 4.0f)
    {
        boss_skill();
        elapsedTime = 0;
    }

    if (!godtype)
    {
        for (int i = 0; i < boss.size(); i++)
        {
            if (fabs(boss[i]->getPosition().x - tank->getPosition().x) <= tank->getContentSize().width &&
                fabs(boss[i]->getPosition().y - tank->getPosition().y) <= tank->getContentSize().height)
            {
                tank->deletetank();
                lifepoint--;
                godtype = true;
                tank->setOpacity(150);
                auto delay1 = DelayTime::create(3.0f);
                auto callFunc1 = CallFunc::create(CC_CALLBACK_0(Level5_1::godmodecancel, this));
                auto sequence1 = Sequence::create(delay1, callFunc1, nullptr);
                this->runAction(sequence1);
                
            }
        }
    }
}
bool Level5_1::init()
{
    if (!Scene::init())
    {
        return false;
    }
    lifepoint = 3;
    std::ifstream file1;
    file1.open("level.txt");
    std::string ss;
    std::ofstream file2;
    getline(file1, ss);
    file1.close();
    file2.open("level.txt");
    if (stoi(ss) < 5)
        file2 << "5";
    else
        file2 << ss;
    file2.close();
    auto background1 = cocos2d::AudioEngine::play2d("fight_apple.mp3", true, 0.5f);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //地图砖块的大小
    tileSize = 32;
    //获取窗口大小
    auto winSize = Director::getInstance()->getVisibleSize();
    //计算地图总大小
    int mapWidth = sizeof(map[0]) / sizeof(int) * tileSize;
    int mapHeight = sizeof(map) / sizeof(map[0]) * tileSize;
    //计算地图的缩放比例
    float scaleX = winSize.width / mapWidth;
    float scaleY = winSize.height / mapHeight;
    scale = MIN(scaleX, scaleY);
    //计算地图在窗口的中心位置
    offsetX = (winSize.width - mapWidth * scale) / 2;
    offsetY = (winSize.height - mapHeight * scale) / 2;
    //渲染地图
    for (int y = 0; y < mapy; ++y)
    {
        for (int x = 0; x < mapx; ++x)
        {
            physicsbody[y][x] = NULL;
            switch (map[y][x])
            {
            case 1:
                physicsbody[y][x] = Sprite::create("wall.png");
                break;
            case 2:
                physicsbody[y][x] = Sprite::create("steel.png");
                break;
            case 3:
                physicsbody[y][x] = Sprite::create("road_earth.png");
            default:
                break;
            }
            if (physicsbody[y][x])
            {
                if (map[y][x] == 6)
                {
                    auto sprite = Sprite::create("road_earth.png");
                    sprite->setScale(scale);
                    sprite->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                    sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                    this->addChild(sprite);
                    if (map[y][x] == 10)
                    {
                        physicsbody[y][x]->setVisible(false);
                    }
                }
                physicsbody[y][x]->setScale(scale);
                physicsbody[y][x]->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                physicsbody[y][x]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(physicsbody[y][x]);
            }
        }
    }
    //add tank below
    tank = Tank::create("tank.png");
    if (tank != nullptr)
    {
        //position the sprite on the center of the screen
        tank->setScale(scale*0.5f);
        //add the sprite as a child to this layer
        Rect rect = tank->getBoundingBox();
        tankWidth = rect.size.width;
        tankHeight = rect.size.height;
        tank->setPosition(Vec2(13 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 13) * tileSize * scale + offsetY + tankHeight / 2));
        birthpos = Vec2(13 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 13) * tileSize * scale + offsetY + tankHeight / 2);
        this->addChild(tank, 0);
        
    }
    //add chase below
    apple_boss = Tank::create("apple_boss.png");
    if (apple_boss != nullptr)
    {
        //position the sprite on the center of the screen
        apple_boss->setScale(scale*2.0f);
        //add the sprite as a child to this layer
        apple_boss->setPosition(Vec2(13 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 5) * tileSize * scale + offsetY + tankHeight / 2));
        this->addChild(apple_boss, 0);
        boss.push_back(apple_boss);
    }

    //add keyboard listenser below
    listener->onKeyPressed = CC_CALLBACK_2(Level5_1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level5_1::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    Level5_1::scheduleUpdate();
    return true;
}