#include "Level3_1.h"
USING_NS_CC;

MagneticTrap* MagneticTrap::create(const Vec2& position, float radius, float force)
{
    MagneticTrap* pRet = new(std::nothrow) MagneticTrap();
    if (pRet && pRet->init(position, radius, force))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        return nullptr;
    }
}

bool MagneticTrap::init(const Vec2& position, float radius, float force)
{
    if (!Node::init())
    {
        return false;
    }

    _position = position;
    _radius = radius;
    _force = force;

    this->setPosition(position);

    // Set a schedule to update the trap every frame
    this->schedule(CC_SCHEDULE_SELECTOR(MagneticTrap::update));

    return true;
}

void MagneticTrap::update(float dt)
{
    attractTanks(dt);
}

void MagneticTrap::attractTanks(float dt)
{
    // Get all tanks in the scene (assuming tanks are added to the same parent)
    auto parent = this->getParent();
    if (parent)
    {
        for (auto& child : parent->getChildren())
        {
            Tank* tank = dynamic_cast<Tank*>(child);
            if (tank && tank->isAlive())
            {
                Vec2 tankPos = tank->getPosition();
                float distance = tankPos.distance(_position);

                if (distance < _radius)
                {
                    Vec2 direction = _position - tankPos;
                    direction.normalize();
                    Vec2 forceVec = direction * _force * (1 - distance / _radius); // Reduce force based on distance

                    tank->setPosition(tankPos + forceVec * dt);
                }
            }
        }
    }
}

void Level4_1::teleportPlayer(Node* player, const Vec2& targetPosition)
{
    player->setPosition(targetPosition);
}

Scene* Level4_1::createScene()
{
    return Level4_1::create();
}
Vec2 Level4_1::calculation(Tank* tank) {
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
void Level4_1::Pausemenu()
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
    buttoncontinue->addTouchEventListener(CC_CALLBACK_2(Level4_1::buttoncontinueCallback, this));
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
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(Level4_1::buttonselectLCallback, this));
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
    buttonBack->addTouchEventListener(CC_CALLBACK_2(Level4_1::buttonbackCallback, this));
    this->addChild(buttonBack, 0, 6);



}
//去选择关卡界面
void Level4_1::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level4_1::buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level4_1::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
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
void Level4_1::Fire(cocos2d::Vec2 origin, float angle, float speed) {
    if (cocos2d::Director::getInstance()->getTotalFrames() / 60 - lastFireTime >= 1.0f) {
        m_bullet.push_back(Bullet::create("bullet.png"));

        this->addChild(m_bullet[m_bullet.size() - 1]);
        m_bullet[m_bullet.size() - 1]->setScale(0.1);
        m_bullet[m_bullet.size() - 1]->shootFrom(origin, angle, speed);
    }
    lastFireTime = cocos2d::Director::getInstance()->getTotalFrames() / 60;
}
int Level4_1::getType(Vec2 pos)
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
    case 16:
        return 16;
    case 17:
        return 17;
    case 18:
        return 18;
    default:
        return 0;
    }
}
void Level4_1::destroyMap(Bullet* bullet)
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
    for (int i = 0; i < 4; i++) {
        float x = (point[i].x - offsetX) / tileSize / scale;
        float y = (mapy - 1) - (point[i].y - offsetY) / tileSize / scale;
        if (y > 0)
            y++;
        int ix = (int)x;
        int iy = (int)y;
        switch (map[iy][ix]) {
            // 此处根据方块类型执行方块摧毁的操作
        case 11:
            physicsbody[iy][ix]->setVisible(false);
            map[iy][ix] = 0;
            break;
        case 4:


        default:
            continue;
        }
    }
}

bool Level4_1::willContact(Vec2 vec, Sprite* sprite)
{
    // 获取坦克/子弹位置信息与尺寸
    Rect rect = sprite->getBoundingBox();

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
        case 1:
            return true;

        case 3:
            return true;
        case 4:
            return true;
        case 11:
            return true;

        default:
            continue;
        }
    }
    return false;
}
bool Level4_1::willContactTrap(Vec2 vec)
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
            tank->deletetank();
            tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 4) * tileSize * scale + offsetY + tankHeight / 2));
            return true;
        default:
            continue;
        }
    }
    return false;
}

void Level4_1::willContactBullet()
{
    for (int i = 0; i < m_bullet.size(); i++) {
        if (willContact(Vec2::ZERO, m_bullet[i])) {
            Vec2 pos = m_bullet[i]->getPosition();
            destroyMap(m_bullet[i]);
            m_bullet[i]->deletebullet();
            m_bullet.erase(m_bullet.begin() + i);
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

void Level4_1::willContactOther(Vec2 vec)
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
        case 6:
            physicsbody[iy + 1][ix]->setVisible(false);
            map[iy + 1][ix] = 30;
            target++;
            return;
        case 7:
            if (target == 13)
            {
                AudioEngine::stopAll();
                auto hello = Level1_1::createScene();
                TransitionFade* trs = TransitionFade::create(1.0f, hello);
                Director::getInstance()->replaceScene(trs);
            }
            return;
        case 8:
            if (times == 1)
            {
                tank->deletetank();
                tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + tankHeight / 2));
            }
            else
            {
                tank->setPosition(Vec2(17 * tileSize * scale + offsetX + tankWidth *0.9, (mapy - 36) * tileSize * scale + offsetY + tankHeight / 2));
            }
            return;
        case 9:
            physicsbody[iy + 1][ix]->setVisible(false);
            map[iy + 1][ix] = 30;
            physicsbody[9][9]->setVisible(true);
            target++;
            return;
        case 10:
            physicsbody[iy + 1][ix]->setVisible(true);
            tank->deletetank();
            tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + tankHeight / 2));
            for (int y = 0; y < mapy; ++y)
            {
                for (int x = 0; x < mapx; ++x)
                {
                    if (map[y][x] == 30)
                    {
                        physicsbody[y][x]->setVisible(true);
                        map[y][x] = 6;
                        target--;
                    }
                }
            }
            return;
        case 12:
            tank->setPosition(Vec2(portalPositions[13].x,portalPositions[13].y+tileSize*scale/2+tankHeight*0.7));
            return;
        case 13:
            tank->setPosition(Vec2(portalPositions[12].x-tankWidth*0.7-tileSize*scale/2, portalPositions[12].y));
            return;
        case 14:
            tank->setPosition(Vec2(7* tileSize * scale + offsetX + tankWidth/2, (mapy - 29) * tileSize * scale + offsetY + tankHeight / 2));
            return;
        case 15:
            if (frequency == 0)
            {
                tank->setPosition(Vec2(31 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 27) * tileSize * scale + offsetY + tankHeight / 2));
                frequency++;
                times++;
            }
            else
            {
                tank->setPosition(Vec2(portalPositions[16].x + tankWidth*0.7 +tileSize*scale/2  , portalPositions[16].y + tankHeight*0.2));
                frequency--;
                times++;
            }
            return;
        case 16:
            tank->setPosition(Vec2(portalPositions[15].x - tankWidth*0.7 -tileSize*scale/2, portalPositions[15].y - tankHeight*0.2));
            return;
        case 17:
            tank->setPosition(Vec2(35 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 33) * tileSize * scale + offsetY + tankHeight / 2));
            return;
        case 18:
            tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + tankHeight / 2));
            return;
        default:
            continue;
        }
    }
    return;
}
void Level4_1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
void Level4_1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
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
void Level4_1::update(float delta) 
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
            staticflag = willContact(Vec2(-2.5f, 0), tank);
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->moveleft();
            break;
        case KEY_S_PRESSED:
            staticflag = willContact(Vec2(0, -2.5f), tank);
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->movedown();
            break;
        case KEY_D_PRESSED:

            staticflag = willContact(Vec2(2.5f, 0), tank);
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->moveright();
            break;
        case KEY_W_PRESSED:

            staticflag = willContact(Vec2(0, 2.5f), tank);
            staticflag2 = willContactTrap(Vec2(0, 0));
            tank->moveup();
            break;
        case KEY_P_PRESSED:
            tank->stopmoving();
            break;
        }
    }
    willContactBullet();
    willContactOther(Vec2(0, 0));
    tank->update(delta, staticflag);
    tank->stopmoving();
    tank->update(delta, staticflag2);
   
    //chaser
    if (target == 13)
    {
        chaser->setVisible(true);
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
            tank->deletetank();
            tank->setPosition(Vec2(2 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 4) * tileSize * scale + offsetY + tankHeight / 2));
            chaser->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 20) * tileSize * scale + offsetY + tankHeight / 2));
            for (int y = 0; y < mapy; ++y)
            {
                for (int x = 0; x < mapx; ++x)
                {
                    if (map[y][x] == 30)
                    {
                        physicsbody[y][x]->setVisible(true);
                        map[y][x] = 6;
                        target--;
                    }
                }
            }
        }
    }
}


bool Level4_1::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto background1 = cocos2d::AudioEngine::play2d("run.mp3", true, 1.0f);
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
                physicsbody[y][x] = Sprite::create("space.png");
                break;
            case 2:
                physicsbody[y][x] = Sprite::create("steel.png");
                break;
            case 3:
                physicsbody[y][x] = Sprite::create("water.png");
                break;
            case 4:
                physicsbody[y][x] = Sprite::create("grass.png");
                break;
            case 5:
                physicsbody[y][x] = Sprite::create("road_earth.png");
                break;
            case 6:
                physicsbody[y][x] = Sprite::create("gold.png");
                break;
            case 7:
                physicsbody[y][x] = Sprite::create("passflag.png");
                break;
            case 8:
                physicsbody[y][x] = Sprite::create("thorn.png");
                break;
            case 9:
                physicsbody[y][x] = Sprite::create("gold.png");
                break;
            case 10:
                physicsbody[y][x] = Sprite::create("fireearth.png");
                break;
            case 11:
                physicsbody[y][x] = Sprite::create("fakespace.png");
                break;
            case 12:
                physicsbody[y][x] = Sprite::create("portal.png");
                break;
            case 13:
                physicsbody[y][x] = Sprite::create("portal.png");
                break;
            case 14:
                physicsbody[y][x] = Sprite::create("portal.png");
                break;
            case 15:
                physicsbody[y][x] = Sprite::create("portal.png");
                break;
            case 16:
                physicsbody[y][x] = Sprite::create("portal.png");
                break;
            case 17:
                physicsbody[y][x] = Sprite::create("portal.png");
                break;
            case 18:
                physicsbody[y][x] = Sprite::create("thorn.png");
                break;
            case 19:
                physicsbody[y][x] = Sprite::create("thorn.png");
                break;
            default:
                break;
            }
            if (physicsbody[y][x])
            {
                if (map[y][x] == 6 || map[y][x] == 7 || map[y][x] == 8 || map[y][x] == 10)
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
                else if (map[y][x] == 12)
                {
                    auto portal = Sprite::create("portal.png");
                    portal->setScale(scale);
                    portal->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                    portal->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                    this->addChild(portal);
                    portalPositions[12] = Vec2(portal->getBoundingBox().getMidX(), portal->getBoundingBox().getMidY());
                }
                else if (map[y][x] == 13)
                {
                    auto portal = Sprite::create("portal.png");
                    portal->setScale(scale);
                    portal->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                    portal->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                    this->addChild(portal);
                    portalPositions[13] = Vec2(portal->getBoundingBox().getMidX(), portal->getBoundingBox().getMidY());
                }
                else if (map[y][x] == 15)
                {
                    auto portal = Sprite::create("portal.png");
                    portal->setScale(scale);
                    portal->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                    portal->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                    this->addChild(portal);
                    portalPositions[15] = Vec2(portal->getBoundingBox().getMidX(), portal->getBoundingBox().getMidY());
                }
                else if (map[y][x] == 16)
                {
                    auto portal = Sprite::create("portal.png");
                    portal->setScale(scale);
                    portal->setPosition(Vec2(x * tileSize * scale + offsetX, (mapy - 1 - y) * tileSize * scale + offsetY));
                    portal->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                    this->addChild(portal);
                    portalPositions[16] = Vec2(portal->getBoundingBox().getMidX(), portal->getBoundingBox().getMidY());
                }
                else if (map[y][x] == 17)
                {
                    physicsbody[y][x]->setVisible(false);
                    portalPositions[17] = Vec2(physicsbody[y][x]->getBoundingBox().getMidX(), physicsbody[y][x]->getBoundingBox().getMidY());
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
    tank->setName("tank");
    if (tank != nullptr)
    {
        //position the sprite on the center of the screen

        tank->setScale(scale * 32 / 50);
        //add the sprite as a child to this layer
        this->addChild(tank, 0);
        Rect rect = tank->getBoundingBox();
        tankWidth = rect.size.width;
        tankHeight = rect.size.height;
        tank->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1 - 1) * tileSize * scale + offsetY + tankHeight / 2));
    }

    //add chase below
    if (chaser==nullptr)
    {
        chaser = Tank::create("chaser.png");
        //position the sprite on the center of the screen
        chaser->setScale(scale * 32 / 400);
        //add the sprite as a child to this layer
        chaser->setVisible(false);
        this->addChild(chaser, 0);
        chaser->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2, (mapy - 1-17)* tileSize* scale + offsetY + tankHeight / 2));
    }



    //add keyboard listenser below
    listener->onKeyPressed = CC_CALLBACK_2(Level4_1::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Level4_1::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    Level4_1::scheduleUpdate();
    return true;
}