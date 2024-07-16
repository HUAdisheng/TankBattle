#include "Level6_1.h"
USING_NS_CC;
Scene* Level6_1::createScene()
{
    return Level6_1::create();
}
Vec2 Level6_1::calculation(Tank* tank) {
    auto newPosition = tank->getPosition();
    auto r = tank->getRotation();
    auto size = tank->getContentSize();
    auto offset = tank->getScale() * size.height / 2 + 20;
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
void Level6_1::Pausemenu()
{
    Level6_1::unscheduleUpdate();
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
    buttoncontinue->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttoncontinueCallback, this));
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
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttonselectLCallback, this));
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
    buttonBack->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttonbackCallback, this));
    this->addChild(buttonBack, 0, 6);



}
//去选择关卡界面
void Level6_1::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level6_1::buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    Level6_1::scheduleUpdate();
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
void Level6_1::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        auto tryagain = FirstScene::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level6_1::buttontryCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto tryagain = Level6_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level6_1::buttonnextCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {

        auto next = Level7_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, next);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level6_1::event_gameover()
{
    Level6_1::unscheduleUpdate();
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
    buttontry->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttontryCallback, this));
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
    buttonback->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttonbackCallback, this));
    this->addChild(buttonback);

}
void Level6_1::Fire(cocos2d::Vec2 origin, float angle, float speed,int type) {
    if (type == 1)
    {
        m_bullet.push_back(Bullet::create("bullet.png"));
        m_bullet[m_bullet.size() - 1]->setScale(0.5);
        this->addChild(m_bullet[m_bullet.size() - 1]);
        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    else if (type == 2)
    {

        m_bullet.push_back(Bullet::create("bossbullet.png"));
        m_bullet[m_bullet.size() - 1]->settype(2);
        m_bullet[m_bullet.size() - 1]->setScale(2);
        this->addChild(m_bullet[m_bullet.size() - 1]);
        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    else if (type == 3) {
        m_bullet.push_back(Bullet::create("fire.png"));
        m_bullet[m_bullet.size() - 1]->settype(3);
        m_bullet[m_bullet.size() - 1]->setScale(scale * 28 / 678);

        this->addChild(m_bullet[m_bullet.size() - 1]);
        m_bullet[m_bullet.size() - 1]->setPosition(origin);
        auto moveTo = MoveTo::create(1.0f,origin+ Vec2::forAngle(CC_DEGREES_TO_RADIANS(angle))*150);
        m_bullet[m_bullet.size() - 1]->runAction(moveTo);
      
    }
}
int Level6_1::getType(Vec2 pos)
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
    default:
        return 0;
    }
}
bool Level6_1::willContact(Vec2 vec)
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
    point[0] = Vec2(MinX + times*vec.x, MinY + times * vec.y);
    point[1] = Vec2(MinX + times * vec.x, MaxY + times * vec.y);
    point[2] = Vec2(MaxX + times * vec.x, MinY + times * vec.y);
    point[3] = Vec2(MaxX + times * vec.x, MaxY + times * vec.y);
    for (int i = 0; i < 4; i++) {
        switch (getType(point[i])) {
        case 6:
            return true;
        case 7:
            return true;
        default:
            continue;
        }
    }
    return false;
}
bool Level6_1::willContactTrap(Vec2 vec)
{
    // 获取坦克位置信息与尺寸
    Rect rect = tank->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();

    // 计算坦克的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();
    Vec2 Position;
    Sprite *sprite;
    Vec2 point[4];
    point[0] = Vec2(MinX + vec.x, MinY + vec.y);
    point[1] = Vec2(MinX + vec.x, MaxY + vec.y);
    point[2] = Vec2(MaxX + vec.x, MinY + vec.y);
    point[3] = Vec2(MaxX + vec.x, MaxY + vec.y);
    for (int i = 0; i < 4; i++) {
        switch (getType(point[i]))
        {
        case 1:
            Position = physicsbody[iy+1][ix]->getPosition();
            physicsbody[iy+1][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("danger.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy+1][ix] = sprite;
            this->addChild(sprite);
           ;
            if (!physicsbody[12][2]->isVisible()) {
                dategold();
            }
            return true;
       
        
        
       
       
       
        default:
            continue;
        }
    }
    return false;
}
void Level6_1::ContactBullet()
{
    for (int i = 0; i < m_bullet.size(); i++) {
        if (willContactBullet(m_bullet[i])) {
            Vec2 pos = m_bullet[i]->getPosition();
            destroyMap(m_bullet[i]);
            if (m_bullet[i]->gettype() != 3) {
                m_bullet[i]->deletebullet();
                m_bullet.erase(m_bullet.begin() + i);
            }
        }
        else if ((tank->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox())||(tank->getBoundingBox().intersectsRect(Boss->getBoundingBox())))){
            if (!godtype) {
                if (m_bullet[i]->gettype() != 3) { 
                    m_bullet[i]->deletebullet();
                    m_bullet.erase(m_bullet.begin() + i);
                }
                tank->deletetank();
                lifes--;
                godtype = true;
                tank->setOpacity(150);
                tank->God_mode = 180;
                auto delay1 = DelayTime::create(3.0f);
                auto callFunc1 = CallFunc::create(CC_CALLBACK_0(Level6_1::godmodecancel, this));
                auto sequence1 = Sequence::create(delay1, callFunc1, nullptr);
                this->runAction(sequence1);
            }
        }
        else if (Boss->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox()) && m_bullet[i]->gettype() == 1) {
            m_bullet[i]->setVisible(false);
            m_bullet.erase(m_bullet.begin() + i);
            Bosslife--;                                                     
            bossspeed += 1.5f;
        }
       
    }
}
void Level6_1::godmodecancel()
{
    tank->setOpacity(255);
    godtype = false;
}
bool Level6_1::willContactBullet(Bullet* bullet)
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
    
    for (int i = 0; i < 4; i++){
        getType(point[i]);
         if(iy + 1 >= mapy || ix >= mapx || iy < 0 || ix < 0) {
            return true;
        }
        switch (map[iy+1][ix]) {
        case 2:
            return true;
        case 6:
            return true;
        case 7:
            return true;
        default:
            continue;
        }
    }
    return false;
}
void Level6_1::destroyMap(Bullet* bullet)
{
    Rect rect = bullet->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();

    // 计算坦克的四顶点坐标
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
       

        case 7:
            if (two) {
                Position = physicsbody[iy][ix]->getPosition();
                physicsbody[iy][ix]->removeFromParentAndCleanup(true);
                map[iy][ix] = 5;
            }
            break;
       
        default:
            continue;
        }
    }
}
void Level6_1::event_win()//游戏win!
{
    AudioEngine::stopAll();
    Level6_1::unscheduleUpdate();
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
    buttonnext->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttonnextCallback, this));
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
    buttonback->addTouchEventListener(CC_CALLBACK_2(Level6_1::buttonbackCallback, this));
    this->addChild(buttonback);
};
void Level6_1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
void Level6_1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
void Level6_1::update(float delta) {
    this->delta = delta;
    bool staticflag = false;
    bool staticflag2 = false;
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
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->moveleft();
            
            break;
        case KEY_S_PRESSED:
            staticflag = willContact(Vec2(0, -2.5f));
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->movedown();
            break;
        case KEY_D_PRESSED:

            staticflag = willContact(Vec2(2.5f, 0));
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->moveright();
            break;
        case KEY_W_PRESSED:

            staticflag = willContact(Vec2(0, 2.5f));
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->moveup();
            break;
        case KEY_P_PRESSED:
            tank->stopmoving();
            break;
        }
    }
    ContactBullet();
   
    tank->speedup(times);
        tank->update(delta, staticflag);
        tank->stopmoving();
        tank->update(delta, staticflag2);
  
   
    if (Bosslife <= 0) {
        event_win();
    } 
    if (Bosslife <= 200) {
        Boss->setTexture("boss2.png");
        one = false;
        two = true;
        }
    if (Bosslife <= 100) {
        two = false;
        three = true;
    }
    if (lifes <=0) {
        event_gameover();
    }
    if (one) {
        elapsedTime += delta;
        if (!isactionrunning1) {
            if (repeatcount < 5) {
                if (elapsedTime >= 1.0f) {
                    performAction1();
                    repeatcount++;
                    elapsedTime = 0.0f;
                }
            }
            else {
                if (elapsedTime >= 5.0f) {
                    repeatcount = 0;
                    elapsedTime = 0.0f;
                }
            }
        }


        time1 += delta;
        if (time1 >= 1.0f) {
            time1 = 0.0f;
            for (int i = 0; i < 5; i++) {
                int x = rand() % 17;

                Vec2 vec1 = Vec2(physicsbody[x][1]->getBoundingBox().getMidY(), physicsbody[x][1]->getBoundingBox().getMidX());
                Vec2 vec2 = Vec2(physicsbody[x][17]->getBoundingBox().getMidY(), physicsbody[x][17]->getBoundingBox().getMidX());
                int y = rand() % 180;
                float fy = (float)y;

                this->Fire(vec1, y, 80, 2);
                this->Fire(vec2, -y, 80, 2);
            }
        }
    }
    if (two||three) {
        Boss->setScale(2); 
        if (!existed) {
            for (int i = 0; i < 360.0f; i += 40.0f) {
                this->Fire(Boss->getPosition(), i, 100, 3);
            }
            existed = true;
            bossspeed = 100.0f;
        }
        if (isBossChasing) {
            chaseDuration -= delta; 

            if (chaseDuration <= 0) {
                isBossChasing = false;
                if(two)
                restDuration = 5.0f;
                if(three)
                    restDuration = 3.0f;
                bossspeed = 100.0f;
               
            }
            else {

               Vec2 targetPosition = tank->getPosition();

               
                Vec2 direction = targetPosition - Boss->getPosition();
                direction.normalize();

                
                float distanceToMove = bossspeed * delta;
                Vec2 newPosition = Boss->getPosition() + direction * distanceToMove;
                Boss->setPosition(newPosition);
               
                
                    for (int i = 0; i < m_bullet.size(); i++) {
                        if (m_bullet[i]->gettype() == 3) {
                            m_bullet[i]->setPosition(m_bullet[i]->getPosition() + direction * distanceToMove);
                            
                        }
                    }
                    // 移动Boss到新位置
                
                if (three) {
                    time2 += delta;
                    int x = rand() % 14;
                    int y = rand() % 14;
                    if (time2 >= 2.0f) {
                        for (int i = 0; i < m_bullet.size(); i++) {
                            if (m_bullet[i]->gettype() == 3) {

                                auto moveTo1 = MoveTo::create(1.0f, Boss->getPosition() + Vec2::forAngle(CC_DEGREES_TO_RADIANS(j)) * 1500);
                                m_bullet[i]->runAction(moveTo1);
                                auto moveTo2 = MoveTo::create(1.0f, Boss->getPosition() - Vec2::forAngle(CC_DEGREES_TO_RADIANS(j)) * 1500);
                                m_bullet[i]->runAction(moveTo2);
                                j += 40.0f;
                            }

                        }
                        time2 = 0.0f;
                    }
                }
               
            }
        }
        else {
            restDuration -= delta; // 减去逝去的时间

            if (restDuration <= 0) {
                isBossChasing = true;
                if(two)
                    chaseDuration = 5.0f;
                if(three)
                chaseDuration = 4.0f;
            }
        }

        elapsedTime += delta;
        if (elapsedTime >= 4.0f) {
            if (two) {
                for (float angle = 0.0f; angle < 360.0f; angle += 30.0f) {

                    this->Fire(Boss->getPosition() - Vec2(100, 0), angle, 50, 2);
                    this->Fire(Boss->getPosition() + Vec2(100, 0), angle, 50, 2);
                }
            }
            if (three) {
                for (float angle = 0.0f; angle < 360.0f; angle += 30.0f) {
                    this->Fire(Boss->getPosition() + Vec2(0,100), angle, 50, 2);
                    this->Fire(Boss->getPosition() - Vec2(100, 0), angle, 50, 2);
                    this->Fire(Boss->getPosition() + Vec2(100, 0), angle, 50, 2);
                    this->Fire(Boss->getPosition() - Vec2( 0,100), angle, 50, 2);
                }
            }
            elapsedTime = 0.0f;
        }
   }
    
   
   
}
bool Level6_1::init()
{
        if (!Scene::init())
        {
            return false;
        }
        std::ifstream file1;
        file1.open("level.txt");
        std::string ss;
        std::ofstream file2;
        getline(file1, ss);
        file1.close();
        file2.open("level.txt");
        if (stoi(ss) < 6)
            file2 << "6";
        else
            file2 << ss;
        file2.close();
        auto background1 = cocos2d::AudioEngine::play2d("fight_six.mp3", true, 1.0f);
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
        lifes = 3;
        Bosslife =300                  ;
        for (int y = 0; y < mapy; ++y)
        {
            for (int x = 0; x < mapx; ++x)
            {
                physicsbody[y][x] = NULL;
                switch (map[y][x])
                {
                case 7:
                    physicsbody[y][x] = Sprite::create("wall.png");
                    break;
                case 2:
                    physicsbody[y][x] = Sprite::create("danger.png");
                  
                    break;
                case 3:
                    physicsbody[y][x] = Sprite::create("fireearth.png"); 
                    physicsbody[y][x]->setVisible(false);
                    break;
                case 4:
                    physicsbody[y][x] = Sprite::create("road_earth.png");
                    break;
                case 5:
                    physicsbody[y][x] = Sprite::create("road_earth.png");
                    break;
                case 6:
                    physicsbody[y][x] = Sprite::create("wall.png");
                    break;
              
                default:
                    break;
                }
                if (physicsbody[y][x])
                {
                    if (map[y][x] == 7||map[y][x] == 2 || map[y][x] == 3)
                    {
                        auto sprite = Sprite::create("road_earth.png");
                        sprite->setScale(scale);
                        sprite->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                        sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                        this->addChild(sprite);
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
    Boss = Tank::create("boss.png");
   
 
    if (tank != nullptr)
    {
        //position the sprite on the center of the screen
        tank->setScale(32 / 28);
        tank->setScale(0.75*scale);
        //add the sprite as a child to this layer
        this->addChild(tank, 0);
        Rect rect = tank->getBoundingBox();
        tankWidth = rect.size.width;
        tankHeight = rect.size.height;
        tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 12) * tileSize * scale + offsetY + tankHeight / 2));
        setbirth(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 12) * tileSize * scale + offsetY + tankHeight / 2));
    }
    if (Boss != nullptr)
    {
        //position the sprite on the center of the screen
        Boss->setScale(32 / 28);
        Boss->setScale(scale);
        //add the sprite as a child to this layer
        this->addChild(Boss, 0); 
        Boss->setScale(5);
        Rect rect = Boss->getBoundingBox();
      BossWidth = rect.size.width;
       BossHeight = rect.size.height;
      
        Boss->setPosition(Vec2(13 * tileSize * scale + offsetX + BossWidth / 2, (mapy - 1 - 11) * tileSize * scale + offsetY + BossHeight / 2));
       
    }
        
    //add keyboard listenser below
    listener->onKeyPressed = CC_CALLBACK_2(Level6_1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level6_1::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
   
    Level6_1::scheduleUpdate();
    return true;
}
