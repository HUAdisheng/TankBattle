#include "FirstScene.h"
#include"HelloWorldScene.h"
#include"LevelSelect.h"
USING_NS_CC;
Scene* FirstScene::createScene()
{
    return FirstScene::create();
}
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
void FirstScene::buttontryCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        auto tryagain = FirstScene::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;

}
void FirstScene::buttonbackCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        auto tryagain = FirstScene::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, tryagain);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void FirstScene::event_gameover()//游戏失败
{
    this->removeAllChildren();
    AudioEngine::stopAll();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label1 = Label::createWithTTF("Game over:(", "fonts/Marker Felt.ttf", 60);
    if (label1 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 ));

        // add the label as a child to this layer
        this->addChild(label1);
    }
   
    auto label2 = Label::createWithTTF("try again!", "fonts/Marker Felt.ttf", 60);
    if (label2 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height ));

        // add the label as a child to this layer
        this->addChild(label2);
    }

    auto label3 = Label::createWithTTF("go back to the start menu", "fonts/Marker Felt.ttf", 60);
    if (label3 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label3->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label2->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label3);
    }
    auto buttontry = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    buttontry->setScale(visibleSize.width / buttontry->getContentSize().width / 21, visibleSize.height / buttontry->getContentSize().height / 16);
    buttontry->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label2->getContentSize().width / 2) - buttontry->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));
    buttontry->setPressedActionEnabled(true);
    buttontry->addTouchEventListener(CC_CALLBACK_2(FirstScene::buttontryCallback, this));
    this->addChild(buttontry);

    auto buttonback = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");
    buttonback->setScale(visibleSize.width / buttonback->getContentSize().width / 21, visibleSize.height / buttonback->getContentSize().height / 16);
    buttonback->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label3->getContentSize().width / 2) - buttonback->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height-label2->getContentSize().height));
    buttonback->setPressedActionEnabled(true);
    buttonback->addTouchEventListener(CC_CALLBACK_2(FirstScene::buttonbackCallback, this));
    this->addChild(buttonback);
};
void FirstScene::replace1(Ref *psender)//跳转到第一个map
{
    auto hello = HelloWorld::createScene();
    TransitionFade* trs = TransitionFade::create(1.0, hello);
    Director::getInstance()->replaceScene(trs);
    return;
}
void FirstScene::buttonselectLCallback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
        AudioEngine::stopAll();
        auto hello = LevelSelected::createScene();
        TransitionFade* trs = TransitionFade::create(1.0, hello);
        Director::getInstance()->replaceScene(trs);
    }
    return;
}
void FirstScene::button1Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        AudioEngine::stopAll();
        replace1(ref);
    }
    return;
}
void FirstScene::button2Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->end();
    }
    return;
}
void FirstScene::button3Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        std::fstream file;
        file.open("level.txt");
        file << "2";
        file.close();
        event_gameover();
    }
    return;
}
// on "init" you need to initialize your instance
bool FirstScene::init()
{

    if (!Scene::init())
    {
        return false;
    }
    auto background1=cocos2d::AudioEngine::play2d("normal_happy.mp3",true,10.0f);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("background_first.png");
    sprite->setScale(visibleSize.width / sprite->getContentSize().width, visibleSize.height / sprite->getContentSize().height);
    if (sprite == nullptr)
    {
        problemLoading("'background_first.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite);
    }
    auto labeltitle = Label::createWithTTF("Tank Battle!...?", "fonts/Marker Felt.ttf", 60);
    if (labeltitle == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        labeltitle->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + 3 * ((visibleSize.height) / 4)));

        // add the label as a child to this layer
        this->addChild(labeltitle);
    }
    auto label1 = Label::createWithTTF("new adventure:)", "fonts/Marker Felt.ttf", 60);
    if (label1 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label1->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label1);
    }
    
    auto label3 = Label::createWithTTF("Select level", "fonts/Marker Felt.ttf", 60);
    if (label3 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label3->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label1->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label3);
    }
    auto label2 = Label::createWithTTF("exit(QAQ)", "fonts/Marker Felt.ttf", 60);
    if (label2 == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label1->getContentSize().height- label1->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label2);
    }
    auto button1 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//NEW GAME
    button1->setScale(visibleSize.width / button1->getContentSize().width / 21, visibleSize.height / button1->getContentSize().height / 16);
    button1->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label1->getContentSize().width / 2) - button1->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));
    button1->setPressedActionEnabled(true);
    button1->addTouchEventListener(CC_CALLBACK_2(FirstScene::button1Callback, this));
    this->addChild(button1);

    auto button2 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//EXIT
    button2->setScale(visibleSize.width / button2->getContentSize().width / 21, visibleSize.height / button2->getContentSize().height / 16);
    button2->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label1->getContentSize().width / 2) - button2->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height-label2->getContentSize().height- label3->getContentSize().height));
    button2->setPressedActionEnabled(true);
    button2->addTouchEventListener(CC_CALLBACK_2(FirstScene::button2Callback, this));
    this->addChild(button2);

    auto button3 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//TEST
    button3->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label1->getContentSize().width / 2) - button3->getContentSize().width,
        origin.y ));
    button3->setScale(visibleSize.width / button3->getContentSize().width / 21, visibleSize.height / button3->getContentSize().height / 16);
    button3->setPressedActionEnabled(true);
    button3->addTouchEventListener(CC_CALLBACK_2(FirstScene::button3Callback, this));
    this->addChild(button3);

    auto buttonselectL = ui::Button::create("defaultbutton_normal.png", "defaultbutton_seleted.png", "disabled_image.png");//SelecLevel
    buttonselectL->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label1->getContentSize().width / 2) - buttonselectL->getContentSize().width,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height - label2->getContentSize().height));
    buttonselectL->setScale(visibleSize.width / buttonselectL->getContentSize().width / 21, visibleSize.height / buttonselectL->getContentSize().height / 16);
    buttonselectL->setPressedActionEnabled(true);
    buttonselectL->addTouchEventListener(CC_CALLBACK_2(FirstScene::buttonselectLCallback, this));
    this->addChild(buttonselectL);
    return true;

}


void FirstScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

