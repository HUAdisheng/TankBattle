#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include"AudioEngine.h"
#include"LevelSelect.h"
#include<iostream>
#include<fstream>
#include<string>
enum KeyState {
    KEY_A_PRESSED,
    KEY_S_PRESSED,
    KEY_D_PRESSED,
    KEY_W_PRESSED,
    KEY_J_PRESSED,
    KEY_P_PRESSED
};
class FirstScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // a selector callback
    void event_gameover();
    void replace1(Ref* psender);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void button1Callback(cocos2d::Ref *ref,cocos2d::ui::Widget::TouchEventType type);
    void button2Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button3Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttoncontinueCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonhelpCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void Pausemenu();
    // implement the "static create()" method manually
    CREATE_FUNC(FirstScene);
};

