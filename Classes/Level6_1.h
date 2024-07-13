#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
#include <vector>

extern enum KeyState;
const int mapy = 20;
const int mapx = 26;
class Level6_1 :
    public cocos2d::Scene
{
public:
    float times = 2;
    void godmodecancel();
    static cocos2d::Scene* createScene();
    virtual bool init();
    void Pausemenu();
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void Fire(cocos2d::Vec2 origin, float angle, float speed,int type);
    bool willContact(Vec2 vec);
    int  getType(Vec2 pos);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void update(float delta);
    Vec2 calculation(Tank* tank);
    bool willContactTrap(Vec2 vec);
    void ContactBullet();
    void destroyMap(Bullet* bullet);
    bool willContactBullet(Bullet* bullet);
    int target = 0;
    float j = 0.0f;
    
    bool ison = false;
    void dategold() {
        for (int y = 0; y < mapy; ++y)
        {
            for (int x = 0; x < mapx; ++x)
            {
                if (map[y][x] == 30)
                {
                    physicsbody[y][x]->setVisible(true);
                    map[y][x] = 7;
                    target--;
                }
            }
        }
        physicsbody[1][13]->setVisible(false);
    }
    void setbirth(Vec2 vec) {
        birthpos = vec;
    }
    void performAction1() {
        CCLOG("Action performed at: %s", getCurrentTime().c_str());
        isactionrunning1 = true;
        for (float angle = 0.0f; angle < 360.0f; angle += 15.0f) {
            this->Fire(Boss->getPosition(), angle, 100,2);
        }
        this->scheduleOnce([=](float dt) {
            isactionrunning1 = false;
            }, 1.0f, "perform_action_delay");
   }
    CREATE_FUNC(Level6_1);
    float elapsedTime = 0.0f;
    float time1 = 0.0f;
    float time2 = 2.0f;
    bool isactionrunning1 = false;
    int repeatcount = 0;
private:
    Tank* Boss;
   
    int ix = 0;
    int iy = 0;
    Sprite* physicsbody[mapy][mapx];
    std::vector<Bullet*> m_bullet;
    Vec2 birthpos;
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
    float BossWidth;
    float BossHeight;
    int lifes;
    int Bosslife;
    bool two = false;
    bool one = true;
    bool three = false;
    bool isBossChasing =false;
    float chaseDuration = 5.0f;
    float restDuration = 5.0f;
    float bossspeed=100.0f;
    bool existed = false;
   
    bool godtype = false;
    int map[mapy][mapx] = {
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,6,6,6,6,6,6,6,6,6,6,6,6,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
         {6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,6,5,5,5,6},
         {6, 5, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,6,6,6,5,5,5,6},
       {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
         {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
       {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
         {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
         {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
       {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
       {6, 5, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,6,6,6,5,5,6},
      {6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,6,5,5,6},
       {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,6},
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,6,6,6,6,6,6,6,6,6,6,6,6,6},

    };
};
