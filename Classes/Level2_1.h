#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
extern enum KeyState;

class Level2_1 :
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
    void willContactOther(Vec2 vec);
    CREATE_FUNC(Level2_1);
private:
    int mapy = 30;
    int mapx = 39;
    int ix = 0;
    int iy = 0;
    int target = 0;
    Bullet* m_bullet;
    EventListenerKeyboard* listener = EventListenerKeyboard::create();
    float lastFireTime = 0.0f;
    Tank* tank;
    Tank* chaser;
    float delta;
    KeyState ks;
    std::map<cocos2d::EventKeyboard::KeyCode, bool>Keystate;
    float offsetX;
    float offsetY;
    int tileSize;
    float scale;
    float tankWidth;
    float tankHeight;
    Sprite* physicsbody[30][39];
    /*1,wall 2.steel 3.water 4.grass 5.road 6.gold 7.passflag 8.trap 9.fakegold 10.invisivletrap*/
    int map[30][39] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 10,1},
        {1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1},
        {1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 1},
        {1, 6, 6, 1, 1, 1, 1, 1, 1, 6, 1, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 6, 1, 6, 6, 1},
        {1, 6, 6, 6, 6, 6, 6, 6, 1, 6, 1, 6, 2, 2, 6, 1, 6, 6, 6, 6, 8, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 10,1, 6, 1, 6, 6, 1},
        {1, 6, 6, 6, 6, 1, 6, 6, 1, 6, 1, 6, 6, 6, 6, 1, 6, 2, 2, 2, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 1, 6, 1, 6, 6, 1},
        {1, 6, 6, 1, 6, 6, 1, 6, 6, 6, 1, 1, 1, 1, 1, 1, 6, 2, 2, 2, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 1},
        {1, 6, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 2, 6, 1, 6, 6, 2, 6, 6, 2, 6, 6, 6, 6, 1, 1, 1, 1, 1, 6, 1},
        {1, 6, 6, 6, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 1},
        {1, 6, 6, 6, 6, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 6, 2, 6, 1, 6, 6, 6, 6, 6, 1, 6, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 6, 6, 6, 1, 1, 1, 1, 1, 6, 1, 6, 6, 6, 1, 6, 6, 1, 6, 2, 6, 6, 6, 2, 6, 6, 6, 2, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 1, 6, 6, 1, 6, 2, 6, 6, 6, 2, 6, 6, 6, 2, 6, 6, 1, 1, 6, 1},
        {1, 6, 6, 2, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 1},
        {1, 6, 6, 2, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 1, 6, 1, 6, 1},
        {1, 6, 6, 2, 6, 6, 1, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 1},
        {1, 6, 6, 2, 6, 6, 6, 1, 6, 6, 1, 6, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 6, 6, 2, 6, 2, 6, 2, 6, 1, 6, 6, 6, 1},
        {1, 6, 6, 2, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 1, 6, 6, 6, 6, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 1, 6, 1},
        {1, 6, 6, 2, 6, 6, 6, 6, 6, 1, 1, 1, 1, 6, 6, 1, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 1},
        {1, 6, 6, 2, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 1},
        {1, 6, 6, 2, 6, 6, 1, 6, 2, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 2, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 5, 9, 5, 1},
        {1, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 2, 2, 6, 1},
        {1, 6, 6, 2, 6, 6, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 6, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 1, 9, 2, 2, 6, 1},
        {1, 9, 8, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 7, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
};
