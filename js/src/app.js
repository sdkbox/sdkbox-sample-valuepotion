
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        var menu = cc.Menu.create();

        sdkbox.PluginValuePotion.init();
        sdkbox.PluginValuePotion.setTest(true);
        sdkbox.PluginValuePotion.setListener({
            onCacheInterstitial: function(placement) {
                cc.log("onCacheInterstitial ");
            },
            onFailToCacheInterstitial: function(placement, errorMessage) {
                cc.log("onFailToCacheInterstitial " + placement + ", error: " + errorMessage);
            },
            onOpenInterstitial: function(placement) {
                cc.log("onOpenInterstitial " + placement);
            },
            onFailToOpenInterstitial: function(placement, errorMessage) {
                cc.log("onFailToOpenInterstitial " + placement + ", error: " + errorMessage);
            },
            onCloseInterstitial: function(placement) {
                cc.log("onCloseInterstitial " + placement);
            },
            onRequestOpenURL: function(placement, URL) {
                cc.log("onRequestOpenURL " + placement + ", URL: " + URL);
            },
            onRequestPurchase: function(placement, name, productId, quantity, campaignId, contentId) {
                cc.log("onRequestPurchase " + placement);
                cc.log("  name: " + name);
                cc.log("  productId: " + productId);
                cc.log("  quantity: " + quantity.toString());
                cc.log("  campaignId: " + campaignId);
                cc.log("  contentId: " + contentId);
            },
            onRequestRewards: function(placement, rewards) {
                cc.log("onRequestRewards ");
                for (var i = rewards.length - 1; i >= 0; i--) {
                    var r = rewards[i];
                    cc.log("%d name:%s, q:%d", i, r.name, r.quantity);
                }
            }
        });

        sdkbox.PluginValuePotion.cacheInterstitial("default");

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("open interstitial", "sans", 24), function() {
            cc.log("open interstitial");
            sdkbox.PluginValuePotion.openInterstitial("default");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("track event", "sans", 24), function() {
            cc.log("track event");
            sdkbox.PluginValuePotion.trackEvent("test event");
            sdkbox.PluginValuePotion.trackEvent("test event with value 23", 23);
            sdkbox.PluginValuePotion.trackEvent("category", "event name", "label", 45);
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("track purchase event", "sans", 24), function() {
            cc.log("track purchase event");
            sdkbox.PluginValuePotion.trackPurchaseEvent("test event", 56, "RMB", "order id", "product id");
            sdkbox.PluginValuePotion.trackPurchaseEvent("test event", 67, "USD", "order id", "product id", "campaign id", "content id");
            sdkbox.PluginValuePotion.trackPurchaseEvent("categroy", "event name", "label", 78, "ILY", "order id", "product id", "campaign id", "content id");
        }));

        menu.addChild(new cc.MenuItemLabel(new cc.LabelTTF("set user info", "sans", 24), function() {
            cc.log("set user info");
            sdkbox.PluginValuePotion.userinfo("id", "user id");
            sdkbox.PluginValuePotion.userinfo("serverid", "server id");
            sdkbox.PluginValuePotion.userinfo("birth", "19991111"); // YYYYMMDD
            sdkbox.PluginValuePotion.userinfo("gender", "M");
            sdkbox.PluginValuePotion.userinfo("level", "9");
            sdkbox.PluginValuePotion.userinfo("friends", "3");
            sdkbox.PluginValuePotion.userinfo("accounttype", "facebook");
        }));

        menu.alignItemsVerticallyWithPadding(10);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

