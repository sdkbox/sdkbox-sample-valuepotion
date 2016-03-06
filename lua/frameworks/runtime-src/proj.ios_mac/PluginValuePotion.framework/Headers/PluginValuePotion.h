/****************************************************************************

 Copyright (c) 2014-2015 SDKBOX Inc

 ****************************************************************************/

#ifndef _PLUGIN_VALUEPOTION_H_
#define _PLUGIN_VALUEPOTION_H_

#include <string>
#include <vector>

namespace sdkbox
{
    struct ValuePotionReward {
        std::string name;
        int quantity;
    };

    class ValuePotionListener {
    public:
        virtual void onCacheInterstitial(const char *placement) {}
        virtual void onFailToCacheInterstitial(const char *placement, const char *errorMessage) {}
        virtual void onOpenInterstitial(const char *placement) {}
        virtual void onFailToOpenInterstitial(const char *placement, const char *errorMessage) {}
        virtual void onCloseInterstitial(const char *placement) {}
        virtual void onRequestOpenURL(const char *placement, const char *URL) {}
        virtual void onRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId) {}
        virtual void onRequestRewards(const char *placement, std::vector<ValuePotionReward> rewards) {}
    };

    class PluginValuePotion {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(ValuePotionListener* listener);

        /**
         * Get the listener
         */
        static ValuePotionListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * for intergation test
         */
        static void setTest(bool isTest);

        /**
         * check if ad is cached
         */
        static bool hasCachedInterstitial(const char *placement);

        /**
         * cached ad
         */
        static void cacheInterstitial(const char *placement);

        /**
         * show ad
         */
        static void openInterstitial(const char *placement);

        /**
         * track game event
         */
        static void trackEvent(const char *eventName);
        static void trackEvent(const char *eventName,
                               double eventValue);
        static void trackEvent(const char *category,
                               const char *eventName,
                               const char *label,
                               double eventValue);

        /**
         * track purchase event
         */
        static void trackPurchaseEvent(const char *eventName,
                                       double revenueAmount,
                                       const char *currency,
                                       const char *orderId,
                                       const char *productId);
        static void trackPurchaseEvent(const char *eventName,
                                       double revenueAmount,
                                       const char *currency,
                                       const char *orderId,
                                       const char *productId,
                                       const char *campaignId,
                                       const char *contentId);
        static void trackPurchaseEvent(const char *category,
                                       const char *eventName,
                                       const char *label,
                                       double revenueAmount,
                                       const char *currency,
                                       const char *orderId,
                                       const char *productId,
                                       const char *campaignId,
                                       const char *contentId);

        /**
         * set user info
         *
         * Field              Description
         * userId             User account id used in game
         * serverId           If you need to distinguish users by server which they belong to, you should set serverId. Then you can get statistics based on serverId.
         * birth              Date of birth in YYYYMMDD. If you know only year of birth, fill last four digits with "0" like "19840000". If you know only date of birth(but not year), fill first four digits with "0" like "00001109".
         * gender             "M" for male, "F" for female.
         * level              Level of user in game.
         * friends            Number of user's friends.
         * accountType        Type of user's account type. (facebook, google, guest, etc)
         *
         * @param attribute "id", "serverid", "birth", "gender", "level", "friends" or "accounttype"
         * @param value value of attribute
         */
        static void userinfo(const char* attribute, const char* value);
    };
}

#endif
