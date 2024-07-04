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
    // �����ͼ��0: �հ�, 1: ��ͨש��, 2: ����ש��, 3: ˮ��, 4: �ݴԣ�
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

    // ��ͼש��Ĵ�С
    int tileSize = 32;

    // ��ȡ���ڴ�С
    auto winSize = Director::getInstance()->getVisibleSize();

    // �����ͼ�ܴ�С
    int mapWidth = sizeof(map[0]) / sizeof(int) * tileSize;
    int mapHeight = sizeof(map) / sizeof(map[0]) * tileSize;

    // �����ͼ�����ű���
    float scaleX = winSize.width / mapWidth;
    float scaleY = winSize.height / mapHeight;
    float scale = MIN(scaleX, scaleY);


    // ��Ⱦ��ͼ
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
