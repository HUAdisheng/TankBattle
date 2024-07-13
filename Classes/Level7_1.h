#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
#include<vector>
#include"LevelSelect.h"
extern enum KeyState;

class Level7_1 :
    public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();
    void Pausemenu();
    void buttontipCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void Fire(cocos2d::Vec2 origin, float angle, float speed, int type);
    bool willContact(Vec2 vec);
    int getType(Vec2 pos);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void update(float delta);
    Vec2 calculation(Tank* tank);
    void willContactOther(Vec2 vec);
    //判断子弹撞击物块
    bool willContactBullet(Bullet* bullet);
    //撞击后效果
    void ContactBullet();
    CREATE_FUNC(Level7_1);
    void destroyMap(Bullet* bullet);
    void event_win();
    void buttonnextCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);

    void again() {
        tank->deletetank();
        //1为数组mapx，17为mapy
        tank->setPosition(Vec2(1 * tileSize * scale + offsetX + tankWidth / 2+10, (mapy - 1-17) * tileSize * scale + offsetY + tankHeight / 2+10));
    }
private:

    std::vector<Bullet*> m_bullet;
    int mapy = 19;
    int mapx = 25;
    int ix = 0;
    int iy = 0;
    int target = 0;
    EventListenerKeyboard* listener = EventListenerKeyboard::create();
    float lastFireTime = 0.0f;
    Tank* tank;
    Tank*chaser;
    float delta;
    KeyState ks;
    std::map<cocos2d::EventKeyboard::KeyCode, bool>Keystate;
    float offsetX;
    float offsetY;
    int tileSize;
    float scale;
    float tankWidth;
    float tankHeight;
    Sprite* physicsbody[19][25];
    int map[19][25] = {
        {21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21},
        {21,10,10,10,3,29,1,1,15,3,1,47,3,1,1,1,1,1,10,11,1,1,1,4,21},
        {21,4,1,1,3,2,2,2,2,3,3,3,3,39,1,1,1,1,1,11,1,1,1,1,21},
        {21,1,1,7,3,14,1,1,15,3,12,11,11,3,3,3,3,108,108,108,1,1,1,1,21},
        {21,2,2,2,3,114,1,4,15,3,4,11,25,1,1,1,10,108,57,108,1,1,1,1,21},
        {21,12,212,212,3,214,1,1,15,3,12,11,25,1,1,1,10,3,3,3,3,3,3,3,21},
        {21,12,12,12,3,314,1,1,1,3,112,11,11,1,2,3,3,1,1,1,1,1,1,4,21},
        {21,5,4,5,3,3,3,3,3,3,3,3,3,1,1,3,3,1,1,1,1,1,1,1,21},
        {21,112,12,12,3,1,11,3,11,1,4,15,3,2,1,3,3,67,1,1,1,1,1,1,21},
        {21,6,11,11,3,2,11,3,3,3,3,3,3,1,1,3,3,1,1,1,1,1,1,1,21},
        {21,6,11,11,3,11,11,3,3,1,1,1,11,1,2,3,3,1,1,1,1,1,1,1,21},
        {21,6,11,11,3,2,37,3,3,1,27,1,11,1,1,3,3,11,11,11,11,11,11,11,21},
        {21,6,11,11,3,212,212,212,212,212,312,212,212,2,12,2,2,2,2,2,2,2,2,2,21},
        {21,3,1,1,6,13,13,13,13,13,13,13,13,31,12,2,109,1,1,109,1,1,109,2,21},
        {21,9,19,1,6,13,13,13,13,13,13,13,13,32,12,2,1,109,1,1,1,1,1,2,21},
        {21,5,5,5,112,13,13,13,13,13,13,13,13,33,112,2,109,1,1,109,1,1,109,2,21},
        {21,1,1,1,12,13,13,13,13,13,13,13,13,34,12,2,1,109,1,1,109,1,1,2,21},
        {21,1,6,6,2,2,2,2,2,2,2,2,2,2,12,2,2,2,2,2,2,2,2,2,21},
        {21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21} };
};