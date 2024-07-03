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
    loadMap();
    return true;
}

void MapLayer::loadMap()
{
    // 定义地图（0: 空白, 1: 普通砖块, 2: 钢铁砖块, 3: 水域, 4: 草丛）
    int map[13][13] = {
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 0, 4, 0, 1, 0, 3, 0, 1, 0, 4, 0, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 3, 3, 3, 0, 2, 2, 2, 0, 3, 3, 3, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 0, 4, 0, 1, 0, 3, 0, 1, 0, 4, 0, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1}
    };
    Sprite* physicsbody[13][13];

    // 地图砖块的大小
    int tileSize = 32;

    // 获取窗口大小
    auto winSize = Director::getInstance()->getVisibleSize();

    // 计算地图总大小
    int mapWidth = sizeof(map[0]) / sizeof(int) * tileSize;
    int mapHeight = sizeof(map) / sizeof(map[0]) * tileSize;

    // 计算地图的缩放比例
    float scaleX = winSize.width / mapWidth;
    float scaleY = winSize.height / mapHeight;
    float scale = MIN(scaleX, scaleY);


    // 渲染地图
    for (int y = 0; y < 13; ++y)
    {
        for (int x = 0; x < 13; ++x)
        {
            physicsbody[y][x] = NULL;
            if (map[y][x] == 1) {
                physicsbody[y][x] = Sprite::create("wall.png");
                auto physicsBody1 = PhysicsBody::createBox(physicsbody[y][x]->getContentSize());
                physicsbody[y][x]->setPhysicsBody(physicsBody1);
            }
            else if (map[y][x] == 2) {
                physicsbody[y][x] = Sprite::create("steel.png");
            }
            else if (map[y][x] == 3) {
                physicsbody[y][x] = Sprite::create("water.png");
            }
            else if (map[y][x] == 4) {
                physicsbody[y][x] = Sprite::create("grass.png");
            }
            else {
                continue;
            }

            if (physicsbody[y][x])
            {
                physicsbody[y][x]->setScale(scale);
                physicsbody[y][x]->setPosition(Vec2(x * tileSize * scale, (12 - y) * tileSize * scale));
                physicsbody[y][x]->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(physicsbody[y][x]);
            }
        }
    }
}
