#include "Level2_1.h"
USING_NS_CC;
Scene* Level2_1::createScene()
{
    return Level2_1::create();
}
Vec2 Level2_1::calculation(Tank* tank) {
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
void Level2_1::Pausemenu()
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
    buttoncontinue->addTouchEventListener(CC_CALLBACK_2(Level2_1::buttoncontinueCallback, this));
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
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(Level2_1::buttonselectLCallback, this));
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
    buttonBack->addTouchEventListener(CC_CALLBACK_2(Level2_1::buttonbackCallback, this));
    this->addChild(buttonBack, 0, 6);



}
//去选择关卡界面
void Level2_1::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level2_1::buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level2_1::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level2_1::Fire(cocos2d::Vec2 origin, float angle, float speed) {
    if (cocos2d::Director::getInstance()->getTotalFrames() / 60 - lastFireTime >= 1.0f||m_bullet.size()<=2) {
        m_bullet.push_back(Bullet::create("bullet.png"));

        this->addChild(m_bullet[m_bullet.size() - 1]);

        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    lastFireTime = cocos2d::Director::getInstance()->getTotalFrames() / 60;
}
int Level2_1::getType(Vec2 pos)
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
    case 11:return 11;
    case 12: return 12;
    case 13:return 13;
    default:
        return 0;
    }
}
bool Level2_1::willContact(Vec2 vec)
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
        case 6:
            return true;
        case 9:
            return true;
        default:
            continue;
        }
    }
    return false;
}
void Level2_1::willContactTrap(Vec2 vec)
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
            sprite = Sprite::create("thorn.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy+1][ix] = sprite;
            this->addChild(sprite);
            again();
            if (!physicsbody[12][2]->isVisible()) {
                dategold();
            }
            return ;
        case 2:
            again();
            if (!physicsbody[12][2]->isVisible()) {
                dategold();
            }
            return ;
        case 3:
            again();
            if (!physicsbody[12][2]->isVisible()) {
                dategold();
            }
            physicsbody[iy + 1][ix]->setVisible(true);
            return ;
        case 7:
            physicsbody[iy + 1][ix]->setVisible(false);
            map[iy + 1][ix] = 30;
            target++;
            if (target == 4) {
                physicsbody[1][13]->setVisible(true);
            }
            return ;
        case 8:
            if (physicsbody[1][13]->isVisible())
            {
                setbirth(Vec2(13 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + tankHeight / 2));
                physicsbody[12][2]->setVisible(true);
                physicsbody[1][13]->setVisible(false);
            }
            return ;
        case 4:
            ison = true;
            return ;
        case 11:if (physicsbody[12][2]->isVisible()) {
            AudioEngine::stopAll();
            auto hello = Level3_1::createScene();
            TransitionFade* trs = TransitionFade::create(1.0, hello);
            Director::getInstance()->replaceScene(trs);
        }
            return ;
        case 12:
            if (!physicsbody[12][2]->isVisible()) {
                again();
                dategold();
                physicsbody[iy + 1][ix]->setVisible(true);
            }
            return ;
        case 13:
            if (physicsbody[12][2]->isVisible()) {
                again();
                physicsbody[iy + 1][ix]->setVisible(true);
            }
            return ;
        default:
            continue;
        }
    }
    return ;
}
void Level2_1::ContactBullet()
{
    for (int i = 0; i < m_bullet.size(); i++) {
        if (willContactBullet( m_bullet[i])) {
            Vec2 pos = m_bullet[i]->getPosition();
            destroyMap(m_bullet[i]);
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
        }
        else if (tank->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox())) {
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
            again();
            if (!physicsbody[12][2]->isVisible()) {
                dategold();
            }
        }
        /*else {
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
        }*/
    }
}
bool Level2_1::willContactBullet(Bullet* bullet)
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
        case 6:
            return true;
        case 9:
            return true;
        case 10:
            return true;
        default:
            continue;
        }
    }
    return false;
}
void Level2_1::destroyMap(Bullet* bullet)
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
       

        case 2:
            Position = physicsbody[iy][ix]->getPosition();
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            sprite = Sprite::create("gold.png");
            sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
            sprite->setScale(scale);
            sprite->setPosition(Position);
            physicsbody[iy][ix] = sprite;
            this->addChild(sprite);
            map[iy][ix] = 7;
            break;
        case 9:
            physicsbody[iy][ix]->removeFromParentAndCleanup(true);
            map[iy][ix] = 0;
            break;
        case 10:
            again();
            if (!physicsbody[12][2]->isVisible()) {
                dategold();
            }
            break;
        default:
            continue;
        }
    }
}
void Level2_1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
        this->Fire(calculation(tank), -tank->getRotation() + 90.0f, 1000);
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
void Level2_1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
void Level2_1::update(float delta) {
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
    willContactTrap(Vec2(0,0));
    
    if (ison) {
        elapsedTime += delta;
        if (elapsedTime >= 1.0f) {
            elapsedTime = 0.0f;
            this->Fire(Vec2(physicsbody[0][11]->getBoundingBox().getMidX(), physicsbody[0][11]->getPosition().y - 30), -90.0f, 1000);
        }
    }
}
bool Level2_1::init()
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
        if (stoi(ss) < 2)
            file2 << "2";
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
        for (int y = 0; y < mapy; ++y)
        {
            for (int x = 0; x < mapx; ++x)
            {
                physicsbody[y][x] = NULL;
                switch (map[y][x])
                {
                case 1:
                    physicsbody[y][x] = Sprite::create("gold.png");
                    break;
                case 2:
                    physicsbody[y][x] = Sprite::create("thorn.png");
                  
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
                case 7:
                    physicsbody[y][x] = Sprite::create("gold.png");
                    break;
                case 8:
                    physicsbody[y][x] = Sprite::create("passflag.png");
                    physicsbody[y][x]->setVisible(false);
                    break;
                case 9:
                    physicsbody[y][x] = Sprite::create("wall.png");
                  
                    break;
                case 10:
                    physicsbody[y][x] = Sprite::create("thorn.png");
                    break;
                case 11:
                    physicsbody[y][x] = Sprite::create("passflag.png");
                    physicsbody[y][x]->setVisible(false);
                    break;
                case 12:
                    physicsbody[y][x] = Sprite::create("fireearth.png");
                    physicsbody[y][x]->setVisible(false);
                    break;
                case 13:
                    physicsbody[y][x] = Sprite::create("fireearth.png");
                    physicsbody[y][x]->setVisible(false);
                    break;
                default:
                    break;
                }
                if (physicsbody[y][x])
                {
                    if (map[y][x]==12||map[y][x]==13||map[y][x]==11||map[y][x]==9||map[y][x] == 1||map[y][x] == 2 || map[y][x] == 3|| map[y][x] == 7 || map[y][x] == 8||map[y][x]==10)
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
    if (tank != nullptr)
    {
        //position the sprite on the center of the screen
        tank->setScale(32 / 28);
       
        tank->setScale(scale);
        //add the sprite as a child to this layer
        this->addChild(tank, 0);
        Rect rect = tank->getBoundingBox();
        tankWidth = rect.size.width;
        tankHeight = rect.size.height;
        tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 12) * tileSize * scale + offsetY + tankHeight / 2));
        setbirth(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 12) * tileSize * scale + offsetY + tankHeight / 2));
    }
        
    //add keyboard listenser below
    listener->onKeyPressed = CC_CALLBACK_2(Level2_1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level2_1::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    Level2_1::scheduleUpdate();
    return true;
}