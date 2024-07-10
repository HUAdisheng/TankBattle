#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
#include <vector>

extern enum KeyState;
const int mapy = 15;
const int mapx = 15;
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
    void again() {
        tank->deletetank();
        tank->setPosition(birthpos);
      
    }
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
    CREATE_FUNC(Level1_1);
    float elapsedTime = 0.0f;
private:
  
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
    int map[mapy][mapx] = {
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,6,6},
        {6, 5, 6, 5, 5, 5, 5, 5, 5, 5, 6, 4, 5,8,6},
        {6, 6, 5, 1, 5, 5, 6, 5, 6, 5, 6, 4, 13,12,6},
        {6, 5, 5, 5, 6, 5, 5, 6, 6, 5, 5, 4, 5,5,6},
        {6, 5, 6, 5, 5, 5, 6, 5, 10, 2,5,4, 5,12,6},
        {6, 5, 5, 6, 5, 6, 6, 5, 6, 10,5,4, 5,13,6},
        {6, 6, 5, 5, 6, 5, 5, 5, 6, 5, 5, 4, 5,5,6},
        {6, 7, 6, 5, 5, 5, 6, 5, 6, 5, 5, 4, 5,5,6},
        {6, 5, 5, 6, 5, 6, 5, 5, 6, 5, 5, 4, 5,2,6},
        {6, 6, 5, 5, 5, 6, 5, 6, 5, 5, 5, 4, 5,5,6},
        {6, 5, 6, 5, 5, 5, 5, 6, 5, 5, 5, 4, 5,5,6},
        {6, 5, 5, 5, 5, 5, 5, 5, 6, 5, 5, 4, 6,6,6},
        {6, 5, 11, 13, 13, 13, 6, 5, 5, 5, 4, 9, 7,5,6},
        {6, 5, 5, 6, 5, 6, 5, 13, 5, 5, 6, 5, 6,1,6},
        {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,6,6},
      


    };
};