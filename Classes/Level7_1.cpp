#include "Level7_1.h"
USING_NS_CC;
Scene* Level7_1::createScene()
{
    return Level7_1::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
void Level7_1::buttonnextCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        auto next = Level7_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, next);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level7_1::event_win()//游戏win!
{
    Level7_1::unscheduleUpdate();
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
    buttonnext->addTouchEventListener(CC_CALLBACK_2(Level7_1::buttonnextCallback, this));
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
    buttonback->addTouchEventListener(CC_CALLBACK_2(Level7_1::buttonbackCallback, this));
    this->addChild(buttonback);
};
void Level7_1::godupdate()
{
    if (tank->God_mode > 0) {
        tank->setOpacity(150);
        tank->God_mode--;
    }
    else
        tank->setOpacity(255);
}
Vec2 Level7_1::calculation(Tank* tank) {
    auto newPosition = tank->getPosition();
    auto r = tank->getRotation();
    auto size = tank->getContentSize();
    auto offset = tank->getScale() * size.height / 2 + 26;
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
void Level7_1::Pausemenu()
{
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
    buttoncontinue->addTouchEventListener(CC_CALLBACK_2(Level7_1::buttoncontinueCallback, this));
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
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(Level7_1::buttonselectLCallback, this));
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
    buttonBack->addTouchEventListener(CC_CALLBACK_2(Level7_1::buttonbackCallback, this));
    this->addChild(buttonBack, 0, 6);


}
//去选择关卡界面
void Level7_1::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level7_1::buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
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
void Level7_1::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto tryagain = FirstScene::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void Level7_1::Fire(cocos2d::Vec2 origin, float angle, float speed,int type) {
    if (cocos2d::Director::getInstance()->getTotalFrames() / 60 - lastFireTime >= 1.0f || m_bullet.size() <= 2) {

        if (type == 1)
        {
            m_bullet.push_back(Bullet::create("gold.png"));
            m_bullet[m_bullet.size() - 1]->setScale(0.5);
        }
        else if (type == 2)
        {

            m_bullet.push_back(Bullet::create("bullet.png"));
            m_bullet[m_bullet.size() - 1]->settype(2);
            m_bullet[m_bullet.size() - 1]->setScale(0.5);
        }

        this->addChild(m_bullet[m_bullet.size() - 1]);

        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    lastFireTime = cocos2d::Director::getInstance()->getTotalFrames() / 60;
}
int Level7_1::getType(Vec2 pos)
{
    float x = (pos.x - offsetX) / tileSize / scale;
    float y = (mapy - 1) - (pos.y - offsetY) / tileSize / scale;
    if (y < 0)
        y--;
    if (x < 0)
        x--;
    ix = (int)x;
    iy = (int)y;
    if (iy + 1 < 0 || ix < 0 || iy + 1 >= mapy || ix >= mapx) {
        ix = 0; 
        iy = 0;
    }
    switch (map[iy + 1][ix]) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
        //触发机关
    case 5:
        return 5;
    case 25:
        return 25;
    case 6:
        return 6;
    case 7:
        return 7;
    case 17:
        return 17;
    case 27:
        return 27;
    case 47:
        return 47;
    case 57:
        return 57;
    case 67:
        return 67;
    case 8:
        return 8;
        //不同按钮

    case 9:
        return 9;
    case 19:
        return 19;
    case 29:
        return 29;
    case 39:
        return 39;
    case 10:
        return 10;
    case 11:
        return 11;
    case 12:
        return 12;
    case 13:
        return 13;
    case 14:
        return 14;
    case 15:
        return 15;
        //不同苹果
    case 21:
        return 21;
        //不同传送门
    case 31:
        return 31;
    case 32:
        return 32;
    case 33:
        return 33;
    case 34:
        return 34;
    case 35:
        return 35;
    case 36:
        return 36;
    case 37:
        return 37;
    case 38:
        return 38;
        //含不同道具方块
    case 112:
        return 112;
    case 212:
        return 212;
    case 312:
        return 312;
    case 412:
        return 412;
    case 109:
        return 109;
    case 108:
        return 108;
    case 107:
        return 107;
    case 106:
        return 106;
        //
    case 888:
        return 888;
    default:
        return 0;
    }
}
void Level7_1::ContactBullet()
{
    for (int i = 0; i < m_bullet.size(); i++) {
        if (willContactBullet(m_bullet[i])) {
            Vec2 pos = m_bullet[i]->getPosition();
            destroyMap(m_bullet[i]);
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
        }
        else if (tank->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox())) {
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
            again();
        }
        else {
            for (int j = i + 1; j < m_bullet.size(); j++) {
                if (m_bullet[i]->getBoundingBox().intersectsRect(m_bullet[j]->getBoundingBox())) {
                    m_bullet[i]->deletebullet();
                    m_bullet[j]->deletebullet();
                    m_bullet.erase(m_bullet.begin() + i);
                    if (i < j) {
                        j--;
                    }
                    m_bullet.erase(m_bullet.begin() + j);
                    break;
                }
            }
        }
    }
}
bool Level7_1::willContact(Vec2 vec)
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
 
        case 21:
            return true;
        case 3:
            return true;
        case 108:
            return true;
        case 12:
            return true;
        case 212:
            return true;
        case 312:
            return true;
        case 112:
            return true;
        case 412:
            return true;
       
        default:
            continue;
        }
    }
    return false;
}
bool Level7_1::willContactBullet(Bullet* bullet)
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
         if (bullet->gettype() == 2) {
             switch (getType(point[i])) {
             case 21:
            
                 return true;

             case 29:
                 return true;
             case 108:
                 return true;
             case 39:
                 return true;
             case 14:
                 return true;
             case 114:
                 return true;
             case 214:
                 return true;
             case 314:
                 return true;
             defalut:
                 continue;
             }
        }
        else if (bullet->gettype() == 1) {
            switch (getType(point[i])) {
            case 15:
                return true;
            case 21:
                return true;
            case 12:
                return true;
            case 6:
                return true;
            case 3:
                return true;
            case 10:
                return true;
            case 2:
                return true;
            case 4:
                return true;
            case 9:
                return true;
            case 19:
                return true;
            case 29:
                return true;
            case 39:
                return true;
            case 31:
                return true;
            case 32:
                return true;
            case 33:
                return true;
            case 34:
                return true;
            case 35:
                return true;
            case 36:
                return true;
            case 37:
                return true;
            case 38:
                return true;
            case 11:
                return true;
            case 312:
                return true;
            case 212:
                return true;
            case 112:
                return true;
            case 412:
                return true;
            case 114:
                return true;
            case 214:
                return true;
            case 314:
                return true;
            case 14:
                return true;
            case 108:
                return true;
            default:
                continue;
            }
      }
       
    }
        
    
    return false;
}
void Level7_1::destroyMap(Bullet* bullet)
{
    Rect rect = bullet->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();
    Sprite* sprite;
    Vec2 Position;
    // 计算坦克的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

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
        case 19:
            if (physicsbody[13][1]) {
                physicsbody[13][1]->removeFromParentAndCleanup(true);
                physicsbody[13][1] = nullptr;
                map[13][1] = 0;       
            }
            break;
        case 9:
            if (physicsbody[5][3]) {
                Position = physicsbody[5][3]->getPosition();
                physicsbody[5][3]->removeFromParentAndCleanup(true);
                sprite = Sprite::create("12.png");
                sprite->setOpacity(100);
                sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                sprite->setScale(scale);
                sprite->setPosition(Position);
                physicsbody[5][3] = sprite;
                this->addChild(sprite);
                map[5][3] = 412;
            }
            Position = physicsbody[iy][ix]->getPosition();
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("8.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy][ix] = sprite;
            this->addChild(sprite);
            map[iy][ix] = 8;          
            break;   
        case 29:
            if (physicsbody[2][10]) {
                physicsbody[2][10]->removeFromParentAndCleanup(true);
                physicsbody[2][10] = nullptr;
                map[2][10] = 0;
            }  
            break;
        case 39:
            Fire(Vec2(physicsbody[1][18]->getBoundingBox().origin.x + 16, physicsbody[1][18]->getBoundingBox().origin.y), -90.0f, 300.0,2);
            return;
        case 108:
            if(bullet->gettype() == 2)
            {
                physicsbody[iy][ix]->removeFromParentAndCleanup(true);
                map[iy][ix] = 0;
            }
            break;
        case 12:
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            map[iy][ix] = 0;
            break;
        case 112:
            Position = physicsbody[iy][ix]->getPosition();
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("8.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy][ix] = sprite;
            this->addChild(sprite);
            map[iy][ix] = 8;
            break;
        case 212:
            Position = physicsbody[iy][ix]->getPosition();
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("2.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy][ix] = sprite;
            this->addChild(sprite);
            map[iy][ix] = 2;
            break;
        case 312:
            Position = physicsbody[iy][ix]->getPosition();
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("4.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy][ix] = sprite;
            this->addChild(sprite);
            map[iy][ix] = 35;
            break;
        case 412:
            Position = physicsbody[iy][ix]->getPosition();
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("4.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy][ix] = sprite;
            this->addChild(sprite);
            map[iy][ix] = 36;
            break;
        case 14:
            Fire(Vec2(physicsbody[3][8]->getBoundingBox().origin.x , physicsbody[3][8]->getBoundingBox().origin.y + 16), 180.0f, 500.0, 2);
            return;
        case 114:
            Fire(Vec2(physicsbody[4][8]->getBoundingBox().origin.x, physicsbody[4][8]->getBoundingBox().origin.y + 16), 180.0f, 500.0, 2);
            return;
        case 214:
            Fire(Vec2(physicsbody[5][8]->getBoundingBox().origin.x , physicsbody[5][8]->getBoundingBox().origin.y + 16), 180.0f, 500.0, 2);
            return;
        case 314:
            Fire(Vec2(physicsbody[1][8]->getBoundingBox().origin.x, physicsbody[1][8]->getBoundingBox().origin.y + 16), 180.0f, 500.0, 2);
            return;
        default:
            continue;
        }
    }
}
void Level7_1::willContactOther(Vec2 vec)
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
        case 7:
            if (physicsbody[8][4]) {
                physicsbody[8][4]->removeFromParentAndCleanup(true);
                physicsbody[8][4] = nullptr;
                map[8][4] = 0;       
            } 
            if (physicsbody[4][1]) {
                physicsbody[4][1]->removeFromParentAndCleanup(true);
                physicsbody[4][1] = nullptr;
                map[4][1] = 0;
            }
            physicsbody[3][3]->setVisible(false);
            break;
        case 27:
            physicsbody[16][17]->setTexture(Director::getInstance()->getTextureCache()->addImage("106.png"));
            if (physicsbody[8][17]->isVisible()==false)               
                map[16][17] = 888;
            physicsbody[11][10]->setVisible(false);
            break;
        case 109:
            again();
            break;
        case 47:
            if(physicsbody[1][10]!=nullptr)
            {
                physicsbody[1][10]->setTexture(Director::getInstance()->getTextureCache()->addImage("4.png"));
            }
            map[1][10] = 38;
            physicsbody[1][11]->setVisible(false);
            break;
        case 57:
            for(int i=3;i<=5;i++)
            {
                physicsbody[i][5]->setVisible(true);
                physicsbody[i][8]->setVisible(true);
            }
            physicsbody[6][5]->setVisible(true);
            physicsbody[1][8]->setVisible(true);
            physicsbody[1][5]->setVisible(true);
            physicsbody[4][18]->setVisible(false);
            break;
        case 67:
            map[13][16] = 107; map[13][19] = 107; map[13][22] = 107; map[14][17] = 107; map[13][16] = 107;
            map[15][16] = 107; map[15][19] = 107; map[15][22] = 107; map[16][20] = 107; map[16][17] = 107;
            physicsbody[13][16]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[13][19]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[13][22]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[14][17]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[13][16]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[15][16]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[15][19]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[15][22]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[16][17]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[16][20]->setTexture(Director::getInstance()->getTextureCache()->addImage("107.png"));
            physicsbody[8][17]->setVisible(false);
            if(physicsbody[4][18]->isVisible()==false)
                
                map[16][17] = 888;
            break;
        case 13:
            if (tank->God_mode <= 0)
            {
                again();
            }
            break;
        case 2:
            again();
            break;
        case 11:
            if (tank->God_mode <= 0)
            {
                again();
            }
            return;
        case 31:
            tank->setPosition(Vec2(11 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 8) * tileSize * scale + offsetY + tankHeight / 2));
            return;
        case 32:
            tank->setPosition(Vec2(10 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 4) * tileSize * scale + offsetY + tankHeight / 2));
            return;
        case 33:
            tank->setPosition(Vec2(23 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + tankHeight / 2));
            return;
        case 34:
        {
             chaser = Tank::create("chaser.png");
            if (chaser!=nullptr)
            {
                chaser->setScale(scale * 32 / 700);
                this->addChild(chaser, 0);
                chaser->setPosition(Vec2(17 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 6) * tileSize * scale + offsetY + tankHeight / 2));
                
            }
            tank->setPosition(Vec2(23 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 6) * tileSize * scale + offsetY + tankHeight / 2));
        }
            return;
        case 35:
            tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2+5, (mapy - 1 - 7) * tileSize * scale + offsetY + tankHeight / 2+5));
            return;
        case 36:
            tank->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2 + 5, (mapy - 1 - 2) * tileSize * scale + offsetY + tankHeight / 2 + 5));
            return;
        case 37:
            tank->setPosition(Vec2(7 * tileSize * scale + offsetX + tankWidth / 2 + 5, (mapy - 1 - 4) * tileSize * scale + offsetY + tankHeight / 2 + 5));
            return;
        case 38:
            tank->setPosition(Vec2(18 * tileSize * scale + offsetX + tankWidth / 2 + 5, (mapy - 1 - 14) * tileSize * scale + offsetY + tankHeight / 2 + 5));
            return;
        case 5:
            for (int i = 1; i <= 3; i++) {
                Fire(Vec2(physicsbody[1][i]->getBoundingBox().origin.x + 16, physicsbody[1][i]->getBoundingBox().origin.y), -90.0f, 1024.0,2);
            }
            return;
        case 25:
            for (int i = 4; i <= 5; i++) {
                Fire(Vec2(physicsbody[i][16]->getBoundingBox().origin.x + 16, physicsbody[i][16]->getBoundingBox().origin.y),180.0f, 1024.0,2);
            }
            return;        
        case 8:
            tank->setGod_mode(210);           
            return;
        case 6:
            tank->setPosition(tank->getPosition() + Vec2(32, 0));
            return;
        case 888:
            event_win();
            break;
        default:
            continue;
        }
    }
    return;
}
void Level7_1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
        //ks = KEY_J_PRESSED;
        this->Fire(calculation(tank), -tank->getRotation() + 90.0f, 1000,1);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_P:
        Pausemenu();
        break;
    defalut:
        auto rotateBy = RotateBy::create(delta, 0.0f);
        tank->runAction(rotateBy);
        break;
    }
}
void Level7_1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
void Level7_1::update(float delta) {

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
    ContactBullet();
    tank->update(delta, staticflag);
    godupdate();
    willContactOther(Vec2(0, 0));
    Rect rect = tank->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();
    Vec2 Position;
    // 计算坦克的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

  
    if (chaser!=nullptr && MinY >= physicsbody[10][0]->getPositionY() && MaxY <= physicsbody[5][0]->getPositionY() &&
        MinX>=physicsbody[0][17]->getPositionX()&&MaxX<=physicsbody[0][24]->getPositionX())
    {
        
        float playx = tank->getPositionX();
        float playy = tank->getPositionY();
        float chaserx = chaser->getPositionX();
        float chasery = chaser->getPositionY();
        float distancex = playx - chaserx;
        float distancey = playy - chasery;
        float l = sqrt(distancex * distancex + distancey * distancey);
        chaser->setPosition(chaserx + 1.5f * distancex / l, chasery + 1.5f * distancey / l);
        if (fabs(chaserx - playx) <= tank->getContentSize().width / 2 &&
            fabs(chasery - playy) <= tank->getContentSize().height / 2)
        {
            again();
        }
        
    }
    else if (chaser!=nullptr&&(MinY < physicsbody[10][0]->getPositionY() || MaxY > physicsbody[5][0]->getPositionY() ||
        MinX < physicsbody[0][17]->getPositionX() || MaxX > physicsbody[0][24]->getPositionX()))
    {
        chaser->removeFromParent();  // 假设这是销毁对象的正确方法
        chaser = nullptr;
    }
    
}
bool Level7_1::init()
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
    if (stoi(ss) < 7)
        file2 << "7";
    else
        file2 << ss;
    file2.close();
    auto background1 = cocos2d::AudioEngine::play2d("Dreams.mp3", true, 1.0f);
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

    auto sprite = Sprite::create("background_seven.png");
    sprite->setScale(visibleSize.width / sprite->getContentSize().width, visibleSize.height / sprite->getContentSize().height);
    if (sprite == nullptr)
    {
        problemLoading("'background.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite);
    }
   
    for (int y = 0; y < mapy; ++y)
    {
        for (int x = 0; x < mapx; ++x)
        {
            physicsbody[y][x] = NULL;
            if (map[y][x] == 1) {
               
            }
            else if (map[y][x] == 2) {
                physicsbody[y][x] = Sprite::create("2.png");
            }
            else if (map[y][x] == 3) {
                physicsbody[y][x] = Sprite::create("3.png");
            }
            else if (map[y][x] == 4) {
                physicsbody[y][x] = Sprite::create("4.png");
            }
            else if (map[y][x] == 5||map[y][x]==25) {
                physicsbody[y][x] = Sprite::create("5.png");
            }
            else if (map[y][x] == 6) {
                physicsbody[y][x] = Sprite::create("6.png");
            }
            else if (map[y][x] == 7||map[y][x]==17 || map[y][x] == 27 || map[y][x] == 47 || map[y][x] == 57 || map[y][x] == 67) {
                physicsbody[y][x] = Sprite::create("7.png");
            }
            else if (map[y][x] == 8) {
                physicsbody[y][x] = Sprite::create("8.png");
            }
            else if (map[y][x] == 9||map[y][x]==19||map[y][x] == 39) {
                physicsbody[y][x] = Sprite::create("9.png");
            }
            else if (map[y][x] == 29) {
                Sprite* s = Sprite::create("9.png");
                s->setVisible(false);
                physicsbody[y][x] = s;
            }
            else if (map[y][x] == 10) {
                physicsbody[y][x] = Sprite::create("10.png");
            }
            else if (map[y][x] == 11) {
                physicsbody[y][x] = Sprite::create("11.png");
            }
            else if (map[y][x] == 12|| map[y][x] == 112 || map[y][x] == 212 || map[y][x] == 312 || map[y][x] == 412) {
                Sprite* s = Sprite::create("12.png");
                s->setOpacity(100);
                physicsbody[y][x] = s;
            }
            else if (map[y][x] == 13) {
                physicsbody[y][x] = Sprite::create("water.png");
            }
            else if (map[y][x] == 15) {
                Sprite* s = Sprite::create("14.png");
                s->setVisible(false);
                physicsbody[y][x] = s;
            }
            else if (map[y][x] == 14|| map[y][x] == 114|| map[y][x] == 214||map[y][x] == 314) {
                Sprite* s = Sprite::create("15.png");
                s->setVisible(false);
                physicsbody[y][x] = s;
            }
            else if (map[y][x] == 13) {
                physicsbody[y][x] = Sprite::create("13.png");
            }
            else if (map[y][x] == 106) {
                physicsbody[y][x] = Sprite::create("106.png");
            }
            else if (map[y][x] == 107) {
                physicsbody[y][x] = Sprite::create("107.png");
            }
            else if (map[y][x] == 108) {
                physicsbody[y][x] = Sprite::create("21.png");
            }
            else if (map[y][x] == 109 ) {
                physicsbody[y][x] = Sprite::create("109.png");
            }
            else if (map[y][x] == 31||map[y][x]==32 || map[y][x] == 33 || map[y][x] == 34 || map[y][x] == 35 || map[y][x] == 36 || map[y][x] == 37 || map[y][x] == 38) {
                physicsbody[y][x] = Sprite::create("4.png");
            }
            
            else if (map[y][x] == 21) {
                physicsbody[y][x] = Sprite::create("108.png");
            }
          

            if (physicsbody[y][x])
            {
               
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

        tank->setScale(scale * 32 / 50);
        //add the sprite as a child to this layer
        this->addChild(tank, 0);
        Rect rect = tank->getBoundingBox();
        tankWidth = rect.size.width;
        tankHeight = rect.size.height;
        tank->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 18) * tileSize * scale + offsetY + tankHeight / 2));
    }

        //chaser = Tank::create("chaser.png");
        //if (chaser != nullptr)
        //{
        //    //position the sprite on the center of the screen
        //    chaser->setScale(scale * 32 / 700);
        //    //add the sprite as a child to this layer
        //    this->addChild(chaser, 0);
        //    chaser->setPosition(Vec2(17 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 6) * tileSize * scale + offsetY + tankHeight / 2));
        //}
    
    //add chase below
    //add keyboard listenser below
    listener->onKeyPressed = CC_CALLBACK_2(Level7_1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level7_1::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    Level7_1::scheduleUpdate();
    return true;
}