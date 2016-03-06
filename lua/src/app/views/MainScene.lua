
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    local menu = cc.Menu:create()

    sdkbox.PluginValuePotion:setTest(true)
    sdkbox.PluginValuePotion:setListener(function(data)
        local event = args.event
        print("receive event:", event)
        dump(args, "value potion listener info:")
    end)
    sdkbox.PluginValuePotion:cacheInterstitial("default")

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("open interstitial", "sans", 24)):onClicked(function()
        printf("open interstitial")
        sdkbox.PluginValuePotion:openInterstitial("default")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("track event", "sans", 24)):onClicked(function()
        printf("track event")
        sdkbox.PluginValuePotion:trackEvent("test event")
        sdkbox.PluginValuePotion:trackEvent("test event with value 23", 23)
        sdkbox.PluginValuePotion:trackEvent("category", "event name", "label", 45)
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("track purchase event", "sans", 24)):onClicked(function()
        printf("track purchase event")
        sdkbox.PluginValuePotion:trackPurchaseEvent("test event", 56, "RMB", "order id", "product id")
        sdkbox.PluginValuePotion:trackPurchaseEvent("test event", 67, "USD", "order id", "product id", "campaign id", "content id")
        sdkbox.PluginValuePotion:trackPurchaseEvent("categroy", "event name", "label", 78, "ILY", "order id", "product id", "campaign id", "content id")
    end))

    menu:addChild(cc.MenuItemLabel:create(cc.Label:createWithSystemFont("set user info", "sans", 24)):onClicked(function()
        printf("set user info")
        sdkbox.PluginValuePotion:userinfo("id", "user id")
        sdkbox.PluginValuePotion:userinfo("serverid", "server id")
        sdkbox.PluginValuePotion:userinfo("birth", "19991111") -- YYYYMMDD
        sdkbox.PluginValuePotion:userinfo("gender", "M")
        sdkbox.PluginValuePotion:userinfo("level", "9")
        sdkbox.PluginValuePotion:userinfo("friends", "3")
        sdkbox.PluginValuePotion:userinfo("accounttype", "facebook")
    end))

    menu:alignItemsVerticallyWithPadding(10)
    self:addChild(menu)
end

return MainScene
