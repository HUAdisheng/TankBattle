#pragma once

#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__


#include "cocos2d.h"

class MapLayer : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MapLayer);

private:
    void loadMap();
};

#endif // __MAP_LAYER_H__
