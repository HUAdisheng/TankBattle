#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
extern enum KeyState;
const int mapy = 20;
const int mapx = 26;
class Level1_1 :
     public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();
    void Pausemenu();
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void Fire(cocos2d::Vec2 origin, float angle, float speed);
    bool willContact(Vec2 vec);
    int getType(Vec2 pos);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void update(float delta);
    Vec2 calculation(Tank* tank);
    bool willContactTrap(Vec2 vec);
    CREATE_FUNC(Level1_1);
private:
    Bullet* m_bullet;
    EventListenerKeyboard* listener = EventListenerKeyboard::create();
    float lastFireTime = 0.0f;
    Tank* tank;
    float delta;
    KeyState ks;
    std::map<cocos2d::EventKeyboard::KeyCode, bool>Keystate;
    float offsetX;
    float offsetY;
    int tileSize;
    float scale;
    float tankWidth;
    float tankHeight;
    int map[mapy][mapx] = {
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1,1,2},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2,5,5,5,5,5,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 2, 2, 2, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 1, 5, 1, 5, 5, 3, 3, 3, 3, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 4, 4, 4, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {2, 5, 5, 5, 5, 5, 4, 4, 4, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 4, 4, 4, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,1,1,1,1,1,5,5,5,5,5,5,5,1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,1,1,1,1,1,5,5,5,5,5,5,5,1}
        
        

    };
};

