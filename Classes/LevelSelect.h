#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include"AudioEngine.h"
#include"HelloWorldScene.h"
#include"Level1_1.h"
#include"Level2_1.h"
#include"Level3_1.h"
#include"Level5_1.h"
#include"Level4_1.h"
#include"Level6_1.h"
#include"Level7_1.h"
#include<iostream>
#include<fstream>
#include<string>

class LevelSelected : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void button1Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button2Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button3Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button4Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button5Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button6Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button7Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button8Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button9Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void button10Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    void buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(LevelSelected);
};
