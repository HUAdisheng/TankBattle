#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
class FirstScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void replace1(Ref* psender);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void button1Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(FirstScene);
};

