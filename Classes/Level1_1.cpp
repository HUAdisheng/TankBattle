#include "Level1_1.h"
USING_NS_CC;

Scene* Level1_1::createScene()
{
    return Level1_1::create();
}

Vec2 Level1_1::calculation(Tank* tank)
{
    auto newPosition = tank->getPosition();
    auto r = tank->getRotation();
    auto size = tank->getContentSize();
    auto offset = tank->getScale() * size.height / 2 + 15*scale;
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

bool Level1_1::ContactEnemyTank()
{
    for (int i = 0; i < enemyTank.size(); i++) {
        if (enemyTank[i]->isVisible()) {
            if (enemyTank[i]->getBoundingBox().intersectsRect(tank->getBoundingBox())) {
                tank->deletetank();
                setTankPos(tank, 19, 25);
                event_gameover();
                return true;
            }
        }
    }
    if (sprintTank && sprintTank->getBoundingBox().intersectsRect(tank->getBoundingBox())) {
        tank->deletetank();
        setTankPos(tank, 19, 25);
        event_gameover();
        return true;
    }
    if (sprintTank1 && sprintTank1->getBoundingBox().intersectsRect(tank->getBoundingBox())) {
        tank->deletetank();
        setTankPos(tank, 19, 25);
        event_gameover();
        return true;
    }
    if (sprintTank1 && sprintTank1->getBoundingBox().intersectsRect(tank->getBoundingBox())) {
        tank->deletetank();
        setTankPos(tank, 19, 25);
        event_gameover();
        return true;
    }
    return false;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void Level1_1::Pausemenu()
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
    
    buttoncontinue->addTouchEventListener(CC_CALLBACK_2(Level1_1::buttoncontinueCallback, this));
    
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
    
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(Level1_1::buttonselectLCallback, this));
    
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
    
    buttonBack->addTouchEventListener(CC_CALLBACK_2(Level1_1::buttonbackCallback, this));
    
    this->addChild(buttonBack, 0, 6);



}

//去选择关卡界面
void Level1_1::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED) 
    {
        AudioEngine::stopAll();
        auto hello = LevelSelected::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}

//游戏继续
void Level1_1::buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level1_1::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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

void Level1_1::Fire(cocos2d::Vec2 origin, float angle, float speed) 
{
    if (cocos2d::Director::getInstance()->getTotalFrames() / 60 - lastFireTime >= 0.0f) 
    {
        auto abullet = Bullet::create("bullet.png");
        abullet->setScale(scale*0.75*0.8);
        m_bullet.push_back(abullet);
        
        this->addChild(m_bullet[m_bullet.size() - 1]);

        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    lastFireTime = cocos2d::Director::getInstance()->getTotalFrames() / 60;
}

int Level1_1::getType(Vec2 pos)
{
    float x = (pos.x - offsetX) / tileSize / scale;
    float y = (mapy - 1) - (pos.y - offsetY) / tileSize / scale;
    if (y < 0)
        y--;
    if (x < 0)
        x--;
    ix = (int)x;
    iy = (int)y;

    if (ix < 0 || iy + 1 < 0 || ix >= mapx || iy >= mapy - 1)
    {
        ix = 0;
        iy = 0;
        return 1;
    }

    switch (map[iy + 1][ix]) 
    {
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
    default:
        return 0;
    }
}

bool Level1_1::willContact(Vec2 vec)
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
    
    for (int i = 0; i < 4; i++) 
    {
        switch (getType(point[i])) 
        {
        case 1:
            return true;
        case 2:
            return true;
        case 3:
            return true;
        case 4:
            return true;
    
        default:
            continue;
        }
    }
    return false;
}

bool Level1_1::willContactTrap(Vec2 vec)
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
    
    for (int i = 0; i < 4; i++) 
    {
        getType(point[i]);
        switch (map[iy+1][ix]) 
        {
        case 7:
            tank->deletetank();
            tank->setPosition(Vec2(20 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 25) * tileSize * scale + offsetY + tankHeight / 2));
            event_gameover();
            return true;
        case 57:
            tank->deletetank();
            tank->setPosition(Vec2(20 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 25) * tileSize * scale + offsetY + tankHeight / 2));
            thorn->setVisible(true);
            event_gameover();
            return true;
        default:
            continue;
        }
    }
    return false;
}

bool Level1_1::willContactBullet(Bullet* bullet)
{
    // 获取子弹位置信息与尺寸
    Rect rect = bullet->getBoundingBox();


    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

    Vec2 point[4];
    point[0] = Vec2(MinX , MinY);
    point[1] = Vec2(MinX , MaxY);
    point[2] = Vec2(MaxX , MinY);
    point[3] = Vec2(MaxX , MaxY);
    
    for (int i = 0; i < 4; i++) 
    {
        switch (getType(point[i])) 
        {
        case 1:
            return true;
        case 2:
            return true;
        case 3:
            return true;
        case 4:
            return true;
        default:
            continue;
        }
    }
    return false;
}

void Level1_1::willContactOther(Vec2 vec)
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
    
    for (int i = 0; i < 4; i++) 
    {
        getType(point[i]);
        switch (map[iy+1][ix])
        {
        case 6:
            physicsbody[iy + 1][ix]->setVisible(false);
            map[iy + 1][ix] = 30;
            target++;
            return;
        case 28:
            if (true)
            {
                
             
                AudioEngine::stopAll();
                auto hello = Level2_1::createScene();
                TransitionFade* trs = TransitionFade::create(1.0f, hello);
                Director::getInstance()->replaceScene(trs);
            }
            return;
        case 9:
            closeThorn();
            return;
        default:
            continue;
        }
    }
    return;
}

void Level1_1::ContactBullet()
{
    for (int i = 0; i < m_bullet.size(); i++) 
    {
        if (willContactBullet( m_bullet[i])) 
        {
            Vec2 pos = m_bullet[i]->getPosition();
            destroyMap(m_bullet[i]);
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
        }
        else 
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
        }

        //else if (tank->getBoundingBox().intersectsRect(m_bullet[i]->getBoundingBox())) {
        //    m_bullet[i]->deletebullet();
        //    m_bullet.erase(m_bullet.begin() + i);
        //    tank->deletetank();
        //}
    }
}
void Level1_1::destroyMap(Bullet* bullet)
{
    Rect rect = bullet->getBoundingBox();

    //将坦克Y坐标转换为地图上的Y坐标
    float MinY = rect.getMinY();
    float MaxY = rect.getMaxY();

    // 计算坦克的四顶点坐标
    float MinX = rect.getMinX();
    float MaxX = rect.getMaxX();

    Vec2 point[4];
    point[0] = Vec2(MinX, MinY);
    point[1] = Vec2(MinX, MaxY);
    point[2] = Vec2(MaxX, MinY);
    point[3] = Vec2(MaxX, MaxY);
    
    for (int i = 0; i < 4; i++) 
    {
        getType(point[i]);
        switch (map[iy + 1][ix]) 
        {
        // 此处根据方块类型执行方块摧毁的操作
        case 1:
            physicsbody[iy][ix]->setVisible(false);
            map[iy][ix] = 0;
            break;
        case 3:
            
        case 4:
            

        default:
            continue;
        }
    }
}

void Level1_1::setTankPos(Tank* atank, int x, int y)
{
    Rect rect = atank->getBoundingBox();
    tankWidth = rect.size.width;
    tankHeight = rect.size.height;
    atank->setPosition(Vec2(x * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - y) * tileSize * scale + offsetY + tankHeight / 2));
}

void Level1_1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) 
{
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

void Level1_1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) 
{
    Keystate[keyCode] = false;
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_A]) 
    {
        tank->setRotation(-90.0f);
        ks = KEY_A_PRESSED;
    }
    else if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_S]) 
    {
        tank->setRotation(180.0f);
        ks = KEY_S_PRESSED;
    }
    else if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_D]) 
    {
        tank->setRotation(90.0f);
        ks = KEY_D_PRESSED;
    }
    else if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_W]) 
    {
        tank->setRotation(0.0f);
        ks = KEY_W_PRESSED;
    }
}

void Level1_1::update(float delta) 
{
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
    else 
    {
        switch (ks) 
        {
        case KEY_A_PRESSED:
            staticflag = willContact(Vec2( -2.5f, 0));
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

    willContactOther(Vec2::ZERO);
    ContactBullet();
    ContactEnemyTank();
    enemyTankLogic();
    tank->update(delta,staticflag);
    tank->stopmoving();
    tank->update(delta, staticflag2);
}

bool Level1_1::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto background1=cocos2d::AudioEngine::play2d("DreamSpace.mp3", true,0.5f);
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
            if (map[y][x] == 1) {
                physicsbody[y][x] = Sprite::create("wall.png");
            }
            else if (map[y][x] == 2) {
                physicsbody[y][x] = Sprite::create("wall.png");
            }
            else if (map[y][x] == 3) {
                physicsbody[y][x] = Sprite::create("steel.png");
            }
            else if (map[y][x] == 4) {
                physicsbody[y][x] = Sprite::create("grass.png");
            }
            else if (map[y][x] == 5) {
                physicsbody[y][x] = Sprite::create("road_earth.png");
            }
            else if (map[y][x] == 6) {
                physicsbody[y][x] = Sprite::create("gold.png");
            }
            else if (map[y][x] == 7) {
                physicsbody[y][x] = Sprite::create("thorn.png");
            }
            else if (map[y][x] == 8) {
                physicsbody[y][x] = Sprite::create("thorn.png");
            }
            else if (map[y][x] == 17) {
                physicsbody[y][x] = Sprite::create("road_earth.png");
            }
            else if (map[y][x] == 27) {
                physicsbody[y][x] = Sprite::create("road_earth.png");
            }
            else if (map[y][x] == 28) {
                physicsbody[y][x] = Sprite::create("road_earth.png");
            }
            else if (map[y][x] == 37) {
                physicsbody[y][x] = Sprite::create("home.png");
            }
            else if (map[y][x] == 47) {
                physicsbody[y][x] = Sprite::create("road_earth.png");
            }
            else if (map[y][x] == 57) {
                physicsbody[y][x] = Sprite::create("road_earth.png");
            }
            else {
                continue;
            }

            if (physicsbody[y][x] && map[y][x] != 8)
            {
                physicsbody[y][x]->setScale(scale);
                physicsbody[y][x]->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy-1 - y) * tileSize * scale+offsetY));
                physicsbody[y][x]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(physicsbody[y][x]);
            }
            if (map[y][x] == 17) 
            {
                sprintTank = Tank::create("chaser.png");
                sprintTank->setScale(scale * 28 / 600);
                setTankPos(sprintTank, x, y);
                sprintTank->setRotation(-90);
            }
            else if (map[y][x] == 27) 
            {
                Tank* atank = Tank::create("enemyTank.png");
                atank->setScale(32 / 28);
                atank->setScale(scale*28/28);
                setTankPos(atank, x, y);
                enemyTank.push_back(atank);
            }
            else if (map[y][x] == 28) 
            {
                Sprite* flag = Sprite::create("passflag.png");
                flag->setScale(scale * 28 / 32);
                flag->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                flag->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(flag);
            }
            else if (map[y][x] == 47)
            {
                if (!sprintTank1) {
                    sprintTank1 = Tank::create("missile.png");
                    sprintTank1->setScale(scale * 28 / 266);
                    sprintTank1->setRotation(-90);
                    // setTankPos(sprintTank1, x, y);
                    setTankPos(sprintTank1, x, y);                    
                }
                else 
                {
                    sprintTank2 = Tank::create("missile.png");
                    sprintTank2->setScale(scale * 28 / 266);
                    sprintTank2->setRotation(-90);
                    setTankPos(sprintTank2, x, y);
                }
            }
            else if (map[y][x] == 57) 
            {
                thorn = Sprite::create("thorn.png");
                thorn->setScale(scale);
                thorn->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                thorn->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(thorn);
                thorn->setVisible(false);
            }

            else if (map[y][x] == 8) 
            {
                auto road = Sprite::create("road_earth.png");
                road->setScale(scale);
                road->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                road->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(road);
                physicsbody[y][x]->setScale(scale);
                physicsbody[y][x]->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                physicsbody[y][x]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(physicsbody[y][x]);
                physicsbody[y][x]->setVisible(false);
            } 
        }
    }

    sw = Sprite::create("sw.png");
    sw->setPosition(Vec2(34* tileSize* scale + offsetX, (mapy - 1 - 17)* tileSize* scale + offsetY));
    sw->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    this->addChild(sw);
    sw->setVisible(false);
    
    //add tank below
    tank = Tank::create("tank.png");
    
    if (tank != nullptr)
    {
         //position the sprite on the center of the screen
        tank->setScale(32 / 28);
        tank->setScale(scale * 0.8);
         //add the sprite as a child to this layer
        this->addChild(tank, 0);
        Rect rect = tank->getBoundingBox();
        tankWidth = rect.size.width;
        tankHeight = rect.size.height;
        tank->setPosition(Vec2(19 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 26) * tileSize * scale + offsetY + tankHeight / 2));

    }

    for (int i = 0; i < enemyTank.size(); i++) 
    {
        this->addChild(enemyTank[i]);
    }
    this->addChild(sprintTank);
    this->addChild(sprintTank1, 0);
    this->addChild(sprintTank2, 0);

    //add keyboard listenser below
    listener->onKeyPressed = CC_CALLBACK_2(Level1_1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level1_1::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  

    Level1_1::scheduleUpdate();
    return true;
}

void Level1_1::enemyTankLogic()
{
    for (int i = 0; i < enemyTank.size(); i++)
    {
        for (int j = 0; j < m_bullet.size(); j++) 
        {
            if (enemyTank[i]->getBoundingBox().intersectsRect(m_bullet[j]->getBoundingBox())) 
            {
                if (enemyTank[i]->isVisible()) 
                {
                    m_bullet[j]->deletebullet();
                    m_bullet.erase(m_bullet.begin() + j); 
                    enemyTank[i]->deletetank();
                    enemyTank[i]->setVisible(false);
                    
                }
            }
        }
    }

    if (sprintTankLogic1) {
        if (tank->getBoundingBox().getMaxY() > sprintTank->getBoundingBox().getMinY()) 
        {
            sprintTank->moveleft();
            sprintTank->speedup(10);
        }
        if (sprintTank->getBoundingBox().getMinX() < 12 * tileSize * scale) 
        {
            sprintTankLogic1 = false;
            sprintTankLogic2 = true;
            sprintTank->speedup(0);
        }
     }
    if (sprintTankLogic2) 
    {
        if (sprintTank)
        {
            if (tank->getBoundingBox().getMaxX() > 25 * tileSize * scale && tank->getBoundingBox().getMinY() < sprintTank->getBoundingBox().getMaxY())
            {
                sprintTank->moveright();
                sprintTank->speedup(5);

            }
            if (sprintTank->getBoundingBox().getMinX() > 38 * tileSize * scale - 12) 
            {
                sprintTankLogic2 = false;
                sprintTank->speedup(0);

            }
        }
    }
    openThorn();
   
    if (sprintTank) 
    {
        Rect rect = sprintTank->getBoundingBox();
        float MinY = rect.getMinY();
        float MaxY = rect.getMaxY();
        float MinX = rect.getMinX();
        float MaxX = rect.getMaxX();
        Vec2 point[4];
        point[0] = Vec2(MinX, MinY);
        point[1] = Vec2(MinX, MaxY);
        point[2] = Vec2(MaxX, MinY);
        point[3] = Vec2(MaxX, MaxY);
        
        for (int i = 0; i < 4; i++) 
        {
            int type;
            float x = (point[i].x - offsetX) / tileSize / scale;
            float y = (mapy - 1) - (point[i].y - offsetY) / tileSize / scale;
            if (y < 0)
                y--;
            if (x < 0)
                x--;
            ix = (int)x;
            iy = (int)y;
            getType(point[i]);
            switch (map[iy + 1][ix]) 
            {
            case 7:
                if (sprintTank) 
                {
                    sprintTank->deletetank();
                    sprintTank->removeFromParentAndCleanup(true);
                    sprintTank = NULL;
                }
                physicsbody[iy + 1][ix]->setVisible(false);
                map[iy + 1][ix] = 5;
                break;
            default:
                continue;
            }
        }
    }
    sprintTank1->moveleft();
    sprintTank1->speedup(1.80);
    sprintTank2->moveleft();
    sprintTank2->speedup(1.80);
    
    if (sprintTank) 
    {
        sprintTank->update(delta, false);
    }
    sprintTank1->update(delta, false);
    sprintTank2->update(delta, false);
    
    if (sprintTank1->getBoundingBox().getMinX() < tileSize * scale && sprintTankLogic3) 
    {
        setTankPos(sprintTank1, 34, 14);
        setTankPos(sprintTank2, 34, 15);
        sprintTankLogic3 = false;
    }
    else if (sprintTank1->getBoundingBox().getMinX() < 11 * tileSize * scale && !sprintTankLogic3) 
    {
        setTankPos(sprintTank1, 12, 10);
        setTankPos(sprintTank2, 12, 11);
        sprintTankLogic3 = true;
    }
    if (tank->getBoundingBox().getMaxX() < 36.6 * tileSize * scale && tank->getBoundingBox().getMinX() > 34.6 * tileSize * scale && tank->getBoundingBox().getMinY() > 13 * tileSize * scale && tank->getBoundingBox().getMaxY() < 16 * tileSize * scale) {
        setTankPos(tank, 1, 10);
    }
}

void Level1_1::openThorn()
{
    if (tank->getBoundingBox().getMaxX() > 38 * tileSize * scale - 22) 
    {
        for (int i = 0; i < mapy; i++) 
        {
            for (int j = 0; j < mapx; j++) 
            {
                if (map[i][j] == 8) 
                {
                    physicsbody[i][j]->setVisible(true);
                    map[i][j] = 7;
                }
            }
        }
        sw->setVisible(true);
        map[17][34] = 9;
    }
    
}

void Level1_1::closeThorn()
{
    physicsbody[18][37]->setVisible(false);
    map[18][37] = 5;
    physicsbody[17][37]->setVisible(false);
    map[17][37] = 5;
    physicsbody[17][36]->setVisible(false);
    map[17][36] = 5;
    physicsbody[18][35]->setVisible(false);
    map[18][35] = 5;
}

void Level1_1::event_gameover()
{
    AudioEngine::stopAll();
    Level1_1::unscheduleUpdate();
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
    
    buttontry->addTouchEventListener(CC_CALLBACK_2(Level1_1::buttontryCallback, this));
    
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
    
    buttonback->addTouchEventListener(CC_CALLBACK_2(Level1_1::buttonbackCallback, this));
    
    this->addChild(buttonback);

}



void Level1_1::buttontryCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        auto tryagain = Level1_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}



