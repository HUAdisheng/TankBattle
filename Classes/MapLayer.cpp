// MapLayer.cpp
#include "MapLayer.h"

USING_NS_CC;


bool MapLayer::init()
{
    if (!Layer::init())
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
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 0, 4, 0, 1, 0, 3, 0, 1, 0, 4, 0, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
        {1, 3, 3, 3, 6, 2, 2, 2, 6, 3, 3, 3, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 5, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 0, 4, 0, 1, 0, 3, 0, 1, 0, 4, 0, 1},
        {1, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // ��ͼש��Ĵ�С
    int tileSize = 32;

    // ��ȡ���ڴ�С
    Size winSize = Director::getInstance()->getWinSize();

    // �����ͼ�ܴ�С
    int mapWidth = sizeof(map[0]) / sizeof(int) * tileSize;
    int mapHeight = sizeof(map) / sizeof(map[0]) * tileSize;

    // �����ͼ�����ű���
    float scaleX = winSize.width / mapWidth;
    float scaleY = winSize.height / mapHeight;
    float scale = MIN(scaleX, scaleY);

    //�����ͼ�ڴ��ڵ�����λ��
    float offsetX = (winSize.width - (mapWidth * scale)) / 2;
    float offsetY = (winSize.height - (mapHeight * scale)) / 2;

    // ��Ⱦ��ͼ
    for (int y = 0; y < 13; ++y)
    {
        for (int x = 0; x < 13; ++x)
        {
            Sprite* tile = nullptr;
            switch (map[y][x])
            {
            case 1:
                tile = Sprite::create("wall.png");
                break;
            case 2:
                tile = Sprite::create("steel.png");
                break;
            case 3:
                tile = Sprite::create("river.png");
                break;
            case 4:
                tile = Sprite::create("grass.png");
                break;
            case 5:
                tile = Sprite::create("trap.png");
                break;
            case 6:
                tile = Sprite::create("blacktrap.png");
                break;
            default:
                continue;
            }

            if (tile)
            {
                tile->setScale(scale);
                tile->setPosition(Vec2(x * tileSize * scale+offsetX, (12 - y) * tileSize * scale+offsetY));
                tile->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
                this->addChild(tile);
               
               
            }
        }
    }
}

