// MapLayer.cpp
#include "MapLayer.h"


USING_NS_CC;
Scene* MapLayer::createScene()
{
    return MapLayer::create();
}
bool MapLayer::init()
{
    if (!Scene::init() || !Scene::initWithPhysics())
    {
        return false;
    }
    Sprite* physicsbody[13][13];
    // 地图砖块的大小
    tileSize = 32;
    // 获取窗口大小
    auto winSize = Director::getInstance()->getVisibleSize();
    // 计算地图总大小
    int mapWidth = sizeof(map[0]) / sizeof(int) * tileSize;
    int mapHeight = sizeof(map) / sizeof(map[0]) * tileSize;
    // 计算地图的缩放比例
    float scaleX = winSize.width / mapWidth;
    float scaleY = winSize.height / mapHeight;
    scale = MIN(scaleX, scaleY);
    // 计算地图在窗口的中心位置
    offsetX = (winSize.width - mapWidth * scale) / 2;
    offsetY = (winSize.height - mapHeight * scale) / 2;
    // 渲染地图
    for (int y = 0; y < 13; ++y)
    {
        for (int x = 0; x < 13; ++x)
        {
            physicsbody[y][x] = NULL;
            if (map[y][x] == 1)
            {
                physicsbody[y][x] = Sprite::create("wall.png");
                
            }
            else if (map[y][x] == 2)
            {
                physicsbody[y][x] = Sprite::create("steel.png");
                
            }
            else if (map[y][x] == 3)
            {
                physicsbody[y][x] = Sprite::create("water.png");
                
            }
            else if (map[y][x] == 4)
            {
                physicsbody[y][x] = Sprite::create("grass.png");
                
            }
            else if (map[y][x] == 5)
            {
                physicsbody[y][x] = Sprite::create("trap.png");
                
            }
            else if (map[y][x] == 6)
            {
                physicsbody[y][x] = Sprite::create("blacktrap.png");
                
            }
            else {
                continue;
            }
            if (physicsbody[y][x])
            {
                physicsbody[y][x]->setScale(scale);
                physicsbody[y][x]->setPosition(Vec2(x * tileSize * scale + offsetX, (12 - y) * tileSize * scale + offsetY));
                physicsbody[y][x]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(physicsbody[y][x]);
                int x = 0;
            }
        }
    }
    //creat player tank
    tank = Tank::create("1.png");
    if (tank != nullptr)
    {
        // position the sprite on the center of the screen
        tank->setScale(32 / 25);
        tank->setScale(scale);
        // add the sprite as a child to this layer
        this->addChild(tank, 0);
        Rect rect = tank->getBoundingBox();
        int tankWidth = rect.size.width;
        int tankHeight = rect.size.height;
        tank->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2, (12 - 12) * tileSize * scale + offsetY + tankHeight / 2));
    }
    //add listenser
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MapLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MapLayer::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    MapLayer::scheduleUpdate();
    return true;
}
void MapLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    Keystate[keyCode] = true;
    auto rotateTo = RotateTo::create(delta, 0.0f);
    switch (keyCode) {
    case cocos2d::EventKeyboard::KeyCode::KEY_A:
        rotateTo = RotateTo::create(delta, -90.0f);
        tank->runAction(rotateTo);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_S:
        rotateTo = RotateTo::create(delta, 180.0f);
        tank->runAction(rotateTo);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_D:
        rotateTo = RotateTo::create(delta, 90.0f);
        tank->runAction(rotateTo);
        break;
    case cocos2d::EventKeyboard::KeyCode::KEY_W:
        rotateTo = RotateTo::create(delta, 0.0f);
        tank->runAction(rotateTo);
        break;
    defalut:
        auto rotateBy = RotateBy::create(delta, 0.0f);
        tank->runAction(rotateBy);
        break;
    }
}
void MapLayer::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    Keystate[keyCode] = false;
}
void MapLayer::update(float delta) {
    this->delta = delta;
    bool staticFlag = false;
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_A]) {
        staticFlag = willContact(Vec2(-10.0f, 0));
        tank->moveleft();
    }
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_S]) {
        staticFlag = willContact(Vec2(0, -10.0f));
        tank->movedown();
    }
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_D]) {
        staticFlag = willContact(Vec2(10.0f, 0));
        tank->moveright();
    }
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_W]) {
        staticFlag = willContact(Vec2(0, 10.0f));
        tank->moveup();
    }
    if (Keystate[cocos2d::EventKeyboard::KeyCode::KEY_A] == false &&
        Keystate[cocos2d::EventKeyboard::KeyCode::KEY_S] == false &&
        Keystate[cocos2d::EventKeyboard::KeyCode::KEY_D] == false &&
        Keystate[cocos2d::EventKeyboard::KeyCode::KEY_W] == false) {
        tank->stopmoving();
    }

    tank->update(delta,staticFlag);

}
bool MapLayer::willContact(Vec2 vec)
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
        case 1:
            return true;
        case 2:
            return true;
        case 3:
            return true;
        case 4:
            return true;
        case 5:
            return true;
        case 6:
            return true;
        default:
            continue;
        }
    }
    return false;
}
int MapLayer::getType(Vec2 pos)
{
     float x = (pos.x - offsetX) / tileSize / scale;
     float y = 12 - (pos.y - offsetY) / tileSize / scale;
     int ix = (int)x;
     int iy = (int)y;


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
        default:
            return 0;
    }
}