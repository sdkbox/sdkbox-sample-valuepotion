#include "PluginValuePotionJSHelper.h"
#include "PluginValuePotion/PluginValuePotion.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginValuePotion_prototype;
static JSContext* s_cx = nullptr;

#if (COCOS2D_VERSION < 0x00030000)
#define Ref CCObject
#define Director CCDirector
#define getInstance sharedDirector
#define schedule scheduleSelector
#endif

class VPCallbackJS: public cocos2d::Ref {
public:
    void schedule();
    void notityJs(float dt);

    jsval _dataVal[6];
    int _dataLen;
    std::string _name;
};

class ValuePotionListenerJS : public sdkbox::ValuePotionListener, public sdkbox::JSListenerBase
{
public:
    ValuePotionListenerJS():sdkbox::JSListenerBase() {
    }

    void onCacheInterstitial(const char *placement) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataLen = 1;
        cb->_name = "onCacheInterstitial";

        cb->schedule();
        cb->autorelease();
    }

    void onFailToCacheInterstitial(const char *placement, const char *errorMessage) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataVal[1] = std_string_to_jsval(cx, errorMessage);
        cb->_dataLen = 2;
        cb->_name = "onFailToCacheInterstitial";

        cb->schedule();
        cb->autorelease();
    }

    void onOpenInterstitial(const char *placement) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataLen = 1;
        cb->_name = "onOpenInterstitial";

        cb->schedule();
        cb->autorelease();
    }

    void onFailToOpenInterstitial(const char *placement, const char *errorMessage) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataVal[1] = std_string_to_jsval(cx, errorMessage);
        cb->_dataLen = 2;
        cb->_name = "onFailToOpenInterstitial";

        cb->schedule();
        cb->autorelease();
    }

    void onCloseInterstitial(const char *placement) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataLen = 1;
        cb->_name = "onCloseInterstitial";

        cb->schedule();
        cb->autorelease();
    }

    void onRequestOpenURL(const char *placement, const char *URL) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataVal[1] = std_string_to_jsval(cx, URL);
        cb->_dataLen = 2;
        cb->_name = "onRequestOpenURL";

        cb->schedule();
        cb->autorelease();
    }

    void onRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataVal[1] = std_string_to_jsval(cx, name);
        cb->_dataVal[2] = std_string_to_jsval(cx, productId);
        cb->_dataVal[3] = INT_TO_JSVAL(quantity);
        cb->_dataVal[4] = std_string_to_jsval(cx, campaignId);
        cb->_dataVal[5] = std_string_to_jsval(cx, contentId);
        cb->_dataLen = 6;
        cb->_name = "onRequestPurchase";

        cb->schedule();
        cb->autorelease();
    }

    void onRequestRewards(const char *placement, std::vector<sdkbox::ValuePotionReward> rewards) {
        JSContext* cx = s_cx;

        VPCallbackJS* cb = new VPCallbackJS();
        cb->_dataVal[0] = std_string_to_jsval(cx, placement);
        cb->_dataVal[1] = OBJECT_TO_JSVAL(rewards_to_obj(s_cx, rewards));
        cb->_dataLen = 2;
        cb->_name = "onRequestRewards";

        cb->schedule();
        cb->autorelease();
    }

    void invokeJS(const char* func, jsval* pVals, int valueSize) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
#endif
        }
    }

    JSObject* reward_to_obj(JSContext* cx, const sdkbox::ValuePotionReward& reward) {
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        JS::RootedObject jsobj(cx, JS_NewObject(cx, NULL, JS::NullPtr(), JS::NullPtr()));

        JS::RootedValue name(cx);
        name = std_string_to_jsval(cx, reward.name);
        JS_SetProperty(cx, jsobj, "name", name);

        JS::RootedValue quantity(cx);
        quantity = INT_TO_JSVAL(reward.quantity);
        JS_SetProperty(cx, jsobj, "quantity", quantity);
#else
        JSObject* jsobj = JS_NewObject(cx, NULL, NULL, NULL);

        JS::RootedValue name(cx);
        name = std_string_to_jsval(cx, reward.name);
        JS_SetProperty(cx, jsobj, "name", name);

        JS::RootedValue quantity(cx);
        quantity = INT_TO_JSVAL(reward.quantity);
        JS_SetProperty(cx, jsobj, "quantity", quantity);
#endif
#elif defined(JS_VERSION)
        JSObject* jsobj = JS_NewObject(cx, NULL, NULL, NULL);

        jsval name;
        name = std_string_to_jsval(cx, reward.name);
        JS_SetProperty(cx, jsobj, "name", &name);

        jsval quantity;
        quantity = INT_TO_JSVAL(reward.quantity);
        JS_SetProperty(cx, jsobj, "quantity", &quantity);
#endif

        return jsobj;
    }

    JSObject* rewards_to_obj(JSContext* cx, const std::vector<sdkbox::ValuePotionReward>& rewards) {
        JS::RootedObject jsretArr(cx, JS_NewArrayObject(cx, 0));

        for (int i = 0; i < rewards.size(); ++i) {
            JSObject* element = reward_to_obj(cx, rewards[i]);
            JS::RootedValue arrElement(cx);
            arrElement = OBJECT_TO_JSVAL(element);

            if (!JS_SetElement(cx, jsretArr, i, arrElement)) {
                break;
            }
        }

        return jsretArr;
    }

};


void VPCallbackJS::schedule() {
    retain();
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(VPCallbackJS::notityJs), this, 0.1, 0, 0.0f, false);
}

void VPCallbackJS::notityJs(float dt) {
    sdkbox::ValuePotionListener* lis = sdkbox::PluginValuePotion::getListener();
    ValuePotionListenerJS* l = dynamic_cast<ValuePotionListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), _dataVal, _dataLen);
    }
    release();
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginValuePotionJS_PluginValuePotion_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
bool js_PluginValuePotionJS_PluginValuePotion_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }

        JSB_PRECONDITION2(ok, cx, false, "js_PluginValuePotionJS_PluginValuePotion_setIAPListener : Error processing arguments");
        ValuePotionListenerJS* wrapper = new ValuePotionListenerJS();
        wrapper->setJSDelegate(args.get(0));
        sdkbox::PluginValuePotion::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_setIAPListener : wrong number of arguments");
    return false;
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginValuePotionJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginValuePotion", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginValuePotionJS_PluginValuePotion_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_all_PluginValuePotionJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginValuePotion", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginValuePotionJS_PluginValuePotion_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginValuePotionJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginValuePotion", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginValuePotionJS_PluginValuePotion_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
