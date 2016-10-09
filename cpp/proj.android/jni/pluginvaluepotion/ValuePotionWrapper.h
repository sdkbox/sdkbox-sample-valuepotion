
#ifndef _PLUGIN_VALUEPOTION_WRAPPER_H_
#define _PLUGIN_VALUEPOTION_WRAPPER_H_

#include "PluginValuePotion.h"
#include "CocosMacros.h"

#define TAG             "ValuePotion"
#define VERSION         "1.0.7"
#define IOS_VERSION_VP          "ios: 1.0.7"
#define ANDROID_VERSION_VP      "android: 1.0.27"

NS_COCOS_BEGIN

    class ValuePotionWrapper {
    public:
        static ValuePotionWrapper* getInstance();
        
        virtual bool init()=0;
        virtual void setListener(ValuePotionListener* listener)=0;
        virtual ValuePotionListener* getListener()=0;
        virtual void removeListener()=0;
        
        virtual void setTest(bool isTest)=0;
        
        virtual bool hasCachedInterstitial(const char *placement)=0;
        virtual void cacheInterstitial(const char *placement)=0;
        virtual void openInterstitial(const char *placement)=0;
        
        virtual void trackEvent(const char *eventName)=0;
        virtual void trackEvent(const char *eventName, double eventValue)=0;
        virtual void trackEvent(const char *category, const char *eventName, const char *label, double eventValue)=0;
        virtual void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId)=0;
        virtual void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)=0;
        virtual void trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId)=0;
        
        virtual void setUserId(const char *userId)=0;
        virtual void setUserServerId(const char *serverId)=0;
        virtual void setUserBirth(const char *birth)=0;
        virtual void setUserGender(const char *gender)=0;
        virtual void setUserLevel(double level)=0;
        virtual void setUserFriends(double friends)=0;
        virtual void setUserAccountType(const char *accountType)=0;
    };

    class ValuePotionWrapperDisabled : public ValuePotionWrapper {
    public:
        
        bool init() { return false; }
        void setListener(ValuePotionListener* listener) {}
        ValuePotionListener* getListener() { return NULL; }
        void removeListener() {}
        
        void setTest(bool isTest) {}
        
        bool hasCachedInterstitial(const char *placement) { return false; }
        void cacheInterstitial(const char *placement) {}
        void openInterstitial(const char *placement) {}
        
        void trackEvent(const char *eventName) {}
        void trackEvent(const char *eventName, double eventValue) {}
        void trackEvent(const char *category, const char *eventName, const char *label, double eventValue) {}
        void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId) {}
        void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId) {}
        void trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId) {}
        
        void setUserId(const char *userId) {}
        void setUserServerId(const char *serverId) {}
        void setUserBirth(const char *birth) {}
        void setUserGender(const char *gender) {}
        void setUserLevel(double level) {}
        void setUserFriends(double friends) {}
        void setUserAccountType(const char *accountType) {}
    };

    class ValuePotionWrapperEnabled : public ValuePotionWrapper {
    public:

        bool init();
        void setListener(ValuePotionListener* listener);
        ValuePotionListener* getListener();
        void removeListener();

        void setTest(bool isTest);
            
        bool hasCachedInterstitial(const char *placement);
        void cacheInterstitial(const char *placement);
        void openInterstitial(const char *placement);
        
        void trackEvent(const char *eventName);
        void trackEvent(const char *eventName, double eventValue);
        void trackEvent(const char *category, const char *eventName, const char *label, double eventValue);
        void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId);
        void trackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);
        void trackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);
        
        void setUserId(const char *userId);
        void setUserServerId(const char *serverId);
        void setUserBirth(const char *birth);
        void setUserGender(const char *gender);
        void setUserLevel(double level);
        void setUserFriends(double friends);
        void setUserAccountType(const char *accountType);

    protected:
        bool nativeInit(const std::string& clientId, const std::string& secretKey, const std::string& senderId);
        const char* nativeSDKVersion();

        void nativeSetTest(bool isTest);
        bool nativeHasCachedInterstitial(const char *placement);
        void nativeCacheInterstitial(const char *placement);
        void nativeOpenInterstitial(const char *placement);    
        void nativeTrackEvent(const char *eventName);
        void nativeTrackEvent(const char *eventName, double eventValue);
        void nativeTrackEvent(const char *category, const char *eventName, const char *label, double eventValue);
        void nativeTrackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId);
        void nativeTrackPurchaseEvent(const char *eventName, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);
        void nativeTrackPurchaseEvent(const char *category, const char *eventName, const char *label, double revenueAmount, const char *currency, const char *orderId, const char *productId, const char *campaignId, const char *contentId);
        void nativeSetUserId(const char *userId);
        void nativeSetUserServerId(const char *serverId);
        void nativeSetUserBirth(const char *birth);
        void nativeSetUserGender(const char *gender);
        void nativeSetUserLevel(double level);
        void nativeSetUserFriends(double friends);
        void nativeSetUserAccountType(const char *accountType);

        ValuePotionListener* _listener = nullptr;
        std::string _appID = "";
        std::string _devKey = "";
        
        static ValuePotionWrapper* _instance;
    };

NS_COCOS_END

#endif
