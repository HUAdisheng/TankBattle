#pragma once

#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__

#include "cocos2d.h"


class MapLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(MapLayer);
 
private:
    float offsetX;
    float offsetY;
    float scaleX;
    float scaleY;
    float scale;
    int tileSize;
    int map;
    void loadMap();
  
};

#endif // __MAP_LAYER_H__
