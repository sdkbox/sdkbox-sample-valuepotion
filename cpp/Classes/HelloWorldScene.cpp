
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginValuePotion::setTest(true);
    sdkbox::PluginValuePotion::setListener(this);
    sdkbox::PluginValuePotion::cacheInterstitial("default");

    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("open interstitial", "sans", 24), [](Ref*){
        CCLOG("open interstitial");
        sdkbox::PluginValuePotion::openInterstitial("default");
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("track event", "sans", 24), [](Ref*){
        CCLOG("track event");
        sdkbox::PluginValuePotion::trackEvent("test event");
        sdkbox::PluginValuePotion::trackEvent("test event with value 23", 23);
        sdkbox::PluginValuePotion::trackEvent("category", "event name", "label", 45);
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("track purchase event", "sans", 24), [](Ref*){
        CCLOG("track purchase event");
        sdkbox::PluginValuePotion::trackPurchaseEvent("test event", 56, "RMB", "order id", "product id");
        sdkbox::PluginValuePotion::trackPurchaseEvent("test event", 67, "USD", "order id", "product id", "campaign id", "content id");
        sdkbox::PluginValuePotion::trackPurchaseEvent("categroy", "event name", "label", 78, "ILY", "order id", "product id", "campaign id", "content id");
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("set user info", "sans", 24), [](Ref*){
        CCLOG("set user info");
        sdkbox::PluginValuePotion::userinfo("id", "user id");
        sdkbox::PluginValuePotion::userinfo("serverid", "server id");
        sdkbox::PluginValuePotion::userinfo("birth", "19991111"); //YYYYMMDD
        sdkbox::PluginValuePotion::userinfo("gender", "M");
        sdkbox::PluginValuePotion::userinfo("level", "9");
        sdkbox::PluginValuePotion::userinfo("friends", "3");
        sdkbox::PluginValuePotion::userinfo("accounttype", "facebook");
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}


void HelloWorld::onCacheInterstitial(const char *placement)
{
    CCLOG("onCacheInterstitial: %s", placement);
}

void HelloWorld::onFailToCacheInterstitial(const char *placement, const char *errorMessage)
{
    CCLOG("onFailToCacheInterstitial: %s, %s", placement, errorMessage);
}

void HelloWorld::onOpenInterstitial(const char *placement)
{
    CCLOG("onOpenInterstitial: %s", placement);
}

void HelloWorld::onFailToOpenInterstitial(const char *placement, const char *errorMessage)
{
    CCLOG("onFailToOpenInterstitial: %s, %s", placement, errorMessage);
}

void HelloWorld::onCloseInterstitial(const char *placement)
{
    CCLOG("onCloseInterstitial: %s", placement);
}

void HelloWorld::onRequestOpenURL(const char *placement, const char *URL)
{
    CCLOG("onRequestOpenURL: %s, %s", placement, URL);
}

void HelloWorld::onRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId)
{
    CCLOG("onRequestPurchase: %s, name: %s, productId: %s, quantity: %d, campaignId: %s, contentId: %s", placement, name, productId, quantity, campaignId, contentId);
}

void HelloWorld::onRequestRewards(const char *placement, std::vector<sdkbox::ValuePotionReward> rewards)
{
    CCLOG("onRequestRewards: %s", placement);
}
