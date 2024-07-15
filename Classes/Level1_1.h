#pragma once
#include"cocos2d.h"
#include"FirstScene.h"
#include "Bullet.h"
#include"Tank.h"
#include <vector>
extern enum KeyState;
const int mapy = 30;
const int mapx = 39;
class Level1_1 :
     public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();
    void Pausemenu();
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttontryCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void Fire(cocos2d::Vec2 origin, float angle, float speed);
    bool willContact(Vec2 vec);
    int  getType(Vec2 pos);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void update(float delta);
    Vec2 calculation(Tank* tank);
    bool ContactEnemyTank();
    bool willContactTrap(Vec2 vec);
    void willContactOther(Vec2 vec);
    bool willContactBullet(Bullet* bullet);
    void ContactBullet();
    void destroyMap(Bullet* bullet);
    void setTankPos(Tank* atank,int x,int y);
    void enemyTankLogic();
    void openThorn();
    void closeThorn();
    void event_gameover();
    CREATE_FUNC(Level1_1);
private:
    Sprite* thorn;
    Sprite* sw;
    bool sprintTankLogic1 = true;
    bool sprintTankLogic2 = false;
    bool sprintTankLogic3 = true;
    std::vector<Tank*> enemyTank;
    Tank* sprintTank;
    Tank* sprintTank1 = NULL;
    Tank* sprintTank2 = NULL;
    int iy = 0;
    int ix = 0;
    int target = 0;
    Sprite* physicsbody[mapy][mapx];
    std::vector<Bullet*> m_bullet;
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
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3, 2, 2, 2, 2, 2, 5, 5, 2, 5, 5, 5, 2,5,5,5,2,5,2,5,5,2,5,2,2,2,2,5,2,2,2,2,5,2,5,5,5,5,3},
        {3, 5, 5, 2, 5, 5, 5, 2, 5, 2, 5, 5, 2,2,5,5,2,5,2,5,2,5,5,5,5,5,2,5,5,5,5,2,5,2,5,2,5,2,3},
        {3, 5, 5, 2, 5, 5, 2, 5, 5, 5, 2, 5, 2,5,2,5,2,5,2,2,5,5,5,5,2,2,2,5,5,2,2,2,5,2,5,5,2,5,3},
        {3, 5, 5, 2, 5, 5, 2, 5, 2, 5, 2, 5, 2,5,5,2,2,5,2,5,2,5,5,5,5,5,5,5,5,5,5,5,5,2,5,2,5,2,3},
        {3, 5, 5, 2, 5, 5, 2, 5, 5, 5, 2, 5, 2,5,5,5,2,5,2,5,5,2,5,5,2,5,5,5,5,2,5,5,5,2,5,5,5,5,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,5,5,5,5,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,2,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,28,5,5,5,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 47, 5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,2,2,2,2,2,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 47, 5,5,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,5,5,5,5,5,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,5,5,5,5,5,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,2,2,5,57,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,5,2,2,5,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,5,5,7,5,5,5,5,7,5,5,5,5,5,7,5,5,5,2,5,5,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,7,5,5,5,7,7,5,5,5,7,5,7,5,5,5,5,5,2,5,5,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,5,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2,8,8,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,17,5,5,5,5,5,5,5,8,5,8,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,27,27,27,27,27,27,27,27,27,27,27,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,27,27,27,27,27,27,27,27,27,27,27,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,27,27,27,27,27,27,27,27,27,27,27,3},
        {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,2,2,2,2,2,5,5,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
        {3, 5, 2, 5, 2, 5, 5, 5, 5, 2, 2, 5, 5,2,2,5,5,5,5,5,5,5,5,5,2,2,5,5,2,2,5,5,5,5,2,5,2,5,3},
        {3, 5, 2, 5, 2, 5, 5, 5, 5, 2, 2, 5, 5,2,2,5,5,5,5,5,5,5,5,5,2,2,5,5,2,2,5,5,5,5,2,5,2,5,3},
        {3, 5, 2, 5, 2, 5, 5, 5, 5, 2, 2, 5, 5,2,2,5,5,5,5,5,5,5,5,5,2,2,5,5,2,2,5,5,5,5,2,5,2,5,3},
        {3, 5, 2, 5, 2, 5, 5, 5, 5, 2, 2, 5, 5,2,2,5,5,5,2,2,2,5,5,5,2,2,5,5,2,2,5,5,5,5,2,5,2,5,3},
        {3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5,5,5,5,5,2,37,2,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3},
        {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        
        

    };
};

