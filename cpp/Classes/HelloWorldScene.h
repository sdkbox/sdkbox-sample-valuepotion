#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginValuePotion/PluginValuePotion.h"

class HelloWorld : public cocos2d::Layer, public sdkbox::ValuePotionListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

private:
    void createTestMenu();

    virtual void onCacheInterstitial(const char *placement);
    virtual void onFailToCacheInterstitial(const char *placement, const char *errorMessage);
    virtual void onOpenInterstitial(const char *placement);
    virtual void onFailToOpenInterstitial(const char *placement, const char *errorMessage);
    virtual void onCloseInterstitial(const char *placement);
    virtual void onRequestOpenURL(const char *placement, const char *URL);
    virtual void onRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId);
    virtual void onRequestRewards(const char *placement, std::vector<sdkbox::ValuePotionReward> rewards);
};

#endif // __HELLOWORLD_SCENE_H__
