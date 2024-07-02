#include "FirstScene.h"
#include"HelloWorldScene.h"
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
void FirstScene::replace1(Ref* psender)
{
    auto hello = HelloWorld::createScene();
    TransitionFade* trs = TransitionFade::create(1.0, hello);
    Director::getInstance()->replaceScene(trs);
    return;
}
void FirstScene::button1Callback(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        replace1(ref);
    }
    return;
}
// on "init" you need to initialize your instance
bool FirstScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto label1 = Label::createWithTTF("new adventure:)", "fonts/Marker Felt.ttf", 24);
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
        this->addChild(label1, 1);
    }

    auto button1 = ui::Button::create("defaultbutton_normal.png", "defaultbutton_normal.png", "disabled_image.png");
    button1->setPosition(Vec2(origin.x + (visibleSize.width / 2) - (label1->getContentSize().width / 2) - 30,
        origin.y + (visibleSize.height) / 2 - label1->getContentSize().height));
    button1->setPressedActionEnabled(true);
    button1->addTouchEventListener(CC_CALLBACK_2(FirstScene::button1Callback, this));
    this->addChild(button1, 1);
    ///////////////////////////////
    //// 2. add a menu item with "X" image, which is clicked to quit the program
    ////    you may modify it.

    //// add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create( "CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(FirstScene::menuCloseCallback, this));

    //if (closeItem == nullptr ||
    //    closeItem->getContentSize().width <= 0 ||
    //    closeItem->getContentSize().height <= 0)
    //{
    //    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    //}
    //else
    //{
    //    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    //    float y = origin.y + closeItem->getContentSize().height / 2;
    //    closeItem->setPosition(Vec2(x, y));
    //}

    //// create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...





    // create and initialize a label




    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}
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

