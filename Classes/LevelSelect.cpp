#include "LevelSelect.h"
USING_NS_CC;
Scene* LevelSelected::createScene()
{
    return LevelSelected::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
//去1-10关
void LevelSelected::button1Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level1_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button2Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button3Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button4Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level4_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button5Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level5_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button6Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button7Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button8Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button9Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void LevelSelected::button10Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = Level2_1::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
//返回主菜单
void LevelSelected::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        auto hello = FirstScene::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
bool LevelSelected::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto background1 = cocos2d::AudioEngine::play2d("tense.mp3", true, 10.0f);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto sprite = Sprite::create("SelectLbg.PNG");
    sprite->setScale(visibleSize.width / sprite->getContentSize().width, visibleSize.height / sprite->getContentSize().height);
    if (sprite == nullptr)
    {
        problemLoading("'SelectLbg.PNG'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite);
    }
    auto labeltitle = Label::createWithTTF("Select Level", "fonts/Marker Felt.ttf", 60);
    labeltitle->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (labeltitle == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        labeltitle->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + 5* ((visibleSize.height) / 6)));

        // add the label as a child to this layer
        this->addChild(labeltitle);
    }
    auto label1 = Label::createWithTTF("Level 1", "fonts/Marker Felt.ttf", 60);
    label1->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label1 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label1->setPosition(Vec2(origin.x + (visibleSize.width / 10),
            origin.y + (visibleSize.height / 2) + label1->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label1);
    }
    std::ifstream file;
    file.open("level.txt");
    std::string s = "0";
    getline(file, s);
        auto button1 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
        button1->setScale(visibleSize.width / button1->getContentSize().width / 21, visibleSize.height / button1->getContentSize().height / 16);
        button1->setPosition(Vec2(origin.x + (visibleSize.width / 10),
            origin.y + (visibleSize.height) / 2));
        button1->setPressedActionEnabled(true);
        button1->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button1Callback, this));
        this->addChild(button1);
    
    
    auto label2 = Label::createWithTTF("Level 2", "fonts/Marker Felt.ttf", 60);
    label2->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label2 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label2->setPosition(Vec2(origin.x + 3*(visibleSize.width / 10),
            origin.y + (visibleSize.height / 2) + label2->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label2);
    }
    
        auto button2 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
        button2->setScale(visibleSize.width / button2->getContentSize().width / 21, visibleSize.height / button2->getContentSize().height / 16);
        button2->setPosition(Vec2(origin.x + 3 * (visibleSize.width / 10),
            origin.y + (visibleSize.height) / 2));
        button2->setPressedActionEnabled(true);
        button2->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button2Callback, this));
        if (stoi(s) < 2) { button2->setBright(false); button2->setEnabled(false); }
        this->addChild(button2);
 
    auto label3 = Label::createWithTTF("Level 3", "fonts/Marker Felt.ttf", 60);
    label3->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label3 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label3->setPosition(Vec2(origin.x + 5 * (visibleSize.width / 10),
            origin.y + (visibleSize.height / 2) + label3->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label3);
    }
        auto button3 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
        button3->setScale(visibleSize.width / button3->getContentSize().width / 21, visibleSize.height / button3->getContentSize().height / 16);
        button3->setPosition(Vec2(origin.x + 5 * (visibleSize.width / 10),
            origin.y + (visibleSize.height) / 2));
        button3->setPressedActionEnabled(true);
        if (stoi(s) <3) { button3->setBright(false); button3->setEnabled(false); }
        button3->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button3Callback, this));
        this->addChild(button3);
    
    auto label4 = Label::createWithTTF("Level 4", "fonts/Marker Felt.ttf", 60);
    label4->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label4 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label4->setPosition(Vec2(origin.x + 7 * (visibleSize.width / 10),
            origin.y + (visibleSize.height / 2) + label4->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label4);
    }
   
        auto button4 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
        button4->setScale(visibleSize.width / button4->getContentSize().width / 21, visibleSize.height / button4->getContentSize().height / 16);
        button4->setPosition(Vec2(origin.x + 7 * (visibleSize.width / 10),
            origin.y + (visibleSize.height) / 2));
        button4->setPressedActionEnabled(true);
        if (stoi(s) <4) { button4->setBright(false); button4->setEnabled(false); }
        button4->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button4Callback, this));
        this->addChild(button4);
    

    auto label5 = Label::createWithTTF("Level 5", "fonts/Marker Felt.ttf", 60);
    label5->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label5 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label5->setPosition(Vec2(origin.x + 9 * (visibleSize.width / 10),
            origin.y + (visibleSize.height / 2) + label5->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label5);
    }

    auto button5 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    button5->setScale(visibleSize.width / button5->getContentSize().width / 21, visibleSize.height / button5->getContentSize().height / 16);
    button5->setPosition(Vec2(origin.x + 9 * (visibleSize.width / 10),
            origin.y + (visibleSize.height) / 2));
    button5->setPressedActionEnabled(true);
    button5->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button5Callback, this));
    if (stoi(s) <5) { button5->setBright(false); button5->setEnabled(false); }
    this->addChild(button5);
    
    auto label6 = Label::createWithTTF("Level 6", "fonts/Marker Felt.ttf", 60);
    label6->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label6 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label6->setPosition(Vec2(origin.x +  (visibleSize.width / 10),
            origin.y  + 2 * button5->getContentSize().height+ label6->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label6);
    }

    auto button6 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    button6->setScale(visibleSize.width / button6->getContentSize().width / 21, visibleSize.height / button6->getContentSize().height / 16);
    button6->setPosition(Vec2(origin.x + (visibleSize.width / 10),
        origin.y  + 2*button6->getContentSize().height));
    button6->setPressedActionEnabled(true);
    button6->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button6Callback, this));
    if (stoi(s) <6) { button6->setBright(false); button6->setEnabled(false); }
    this->addChild(button6);

    auto label7 = Label::createWithTTF("Level 7", "fonts/Marker Felt.ttf", 60);
    label7->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label7 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label7->setPosition(Vec2(origin.x + 3 * (visibleSize.width / 10),
            origin.y + 2*(button5->getContentSize().height ) + label7->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label7);
    }

    auto button7 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    button7->setScale(visibleSize.width / button7->getContentSize().width / 21, visibleSize.height / button7->getContentSize().height / 16);
    button7->setPosition(Vec2(origin.x + 3*(visibleSize.width / 10),
        origin.y  + 2*button7->getContentSize().height));
    button7->setPressedActionEnabled(true);
    button7->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button7Callback, this));
    if (stoi(s) <7) { button7->setBright(false); button7->setEnabled(false); }
    this->addChild(button7);

    auto label8 = Label::createWithTTF("Level 8", "fonts/Marker Felt.ttf", 60);
    label8->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label8 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label8->setPosition(Vec2(origin.x + 5 * (visibleSize.width / 10),
            origin.y + 2 * (button5->getContentSize().height) + label8->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label8);
    }

    auto button8 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    button8->setScale(visibleSize.width / button8->getContentSize().width / 21, visibleSize.height / button8->getContentSize().height / 16);
    button8->setPosition(Vec2(origin.x + 5*(visibleSize.width / 10),
        origin.y + 2*button8->getContentSize().height));
    button8->setPressedActionEnabled(true);
    button8->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button8Callback, this));
    if (stoi(s) < 8) { button8->setBright(false); button8->setEnabled(false); }
    this->addChild(button8);

    auto label9 = Label::createWithTTF("Level 9", "fonts/Marker Felt.ttf", 60);
    label9->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label9 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label9->setPosition(Vec2(origin.x + 7 * (visibleSize.width / 10),
            origin.y + 2 * (button5->getContentSize().height) + label9->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label9);
    }

    auto button9 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    button9->setScale(visibleSize.width / button9->getContentSize().width / 21, visibleSize.height / button9->getContentSize().height / 16);
    button9->setPosition(Vec2(origin.x + 7*(visibleSize.width / 10),
        origin.y  + 2*button9->getContentSize().height));
    button9->setPressedActionEnabled(true);
    button9->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button9Callback, this));
    if (stoi(s) < 9) { button9->setBright(false); button9->setEnabled(false); }
    this->addChild(button9);

    auto label10 = Label::createWithTTF("Level 10", "fonts/Marker Felt.ttf", 60);
    label10->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (label10 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label10->setPosition(Vec2(origin.x + 9* (visibleSize.width / 10),
            origin.y + 2 * (button5->getContentSize().height) + label10->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label10);
    }

    auto button10 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    button10->setScale(visibleSize.width / button10->getContentSize().width / 21, visibleSize.height / button10->getContentSize().height / 16);
    button10->setPosition(Vec2(origin.x + 9*(visibleSize.width / 10),
        origin.y  + 2*button10->getContentSize().height));
    button10->setPressedActionEnabled(true);
    button10->addTouchEventListener(CC_CALLBACK_2(LevelSelected::button10Callback, this));
    if (stoi(s) < 10) { button10->setBright(false); button10->setEnabled(false); }
    this->addChild(button10);
    file.close();

    auto labelback = Label::createWithTTF("back", "fonts/Marker Felt.ttf", 60);
    labelback->setTextColor(Color4B(Color3B(255, 255, 128)));
    if (labelback == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        labelback->setPosition(Vec2(origin.x + (visibleSize.width / 5),
            origin.y + visibleSize.height - labelback->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(labelback);
    }

    auto buttonback = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    buttonback->setScale(visibleSize.width / buttonback->getContentSize().width / 21, visibleSize.height / buttonback->getContentSize().height / 16);
    buttonback->setPosition(Vec2(origin.x + (visibleSize.width / 5)-labelback->getContentSize().width,
        origin.y + visibleSize.height - labelback->getContentSize().height));
    buttonback->setPressedActionEnabled(true);
    buttonback->addTouchEventListener(CC_CALLBACK_2(LevelSelected::buttonbackCallback, this));
    this->addChild(buttonback);
    
    
}