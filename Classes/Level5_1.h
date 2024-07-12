#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
#include<fstream>
#include<string>
extern enum KeyState;

class Level5_1 :
    public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void Pausemenu();
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttontryCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonnextCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void Fire(cocos2d::Vec2 origin, float angle, float speed,int type);
    bool willContact(Vec2 vec);
    bool willContactBullet(Bullet* bullet);
    void ContactBullet();
    int getType(Vec2 pos);
    void destroyMap(Bullet* bullet);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void boss_skill();
    void boss_skill_1();
    void boss_skill_2();
    void boss_skill_3();
    void boss_skill_4();
    void godmodecancel();
    void update(float delta);
    void event_gameover();
    void event_win();
    Vec2 calculation(Tank* tank);
    void willContactOther(Vec2 vec);
    CREATE_FUNC(Level5_1);
    float elapsedTime = 0.0f;
private:
    int mapy = 20;
    int mapx = 26;
    int ix = 0;
    int iy = 0;
    int target = 0;
    int lifepoint;
    bool godtype = false;
    Vec2 birthpos;
    Vec2 targetpos;
    bool bossmove=false;
    int boss_lp = 250;
    int applespeed = 200;
    std::vector<Bullet*> m_bullet;
    EventListenerKeyboard* listener = EventListenerKeyboard::create();
    float lastFireTime = 0.0f;
    Tank* tank;
    Tank* apple_boss;
    float delta;
    KeyState ks;
    std::map<cocos2d::EventKeyboard::KeyCode, bool>Keystate;
    float offsetX;
    float offsetY;
    int tileSize;
    float scale;
    float tankWidth;
    float tankHeight;
    Sprite* physicsbody[20][26];
    /*1,wall 2.steel 3.road_earth*/
    int map[20][26] = {
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
};

