#ifndef __PluginValuePotionJS_h__
#define __PluginValuePotionJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginValuePotion_class;
extern JSObject *jsb_sdkbox_PluginValuePotion_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JS::HandleObject global);
void register_all_PluginValuePotionJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JSObject* global);
void register_all_PluginValuePotionJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginValuePotionJS_PluginValuePotion_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginValuePotionJS_PluginValuePotion_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_openInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_openInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_userinfo(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_userinfo(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_trackEvent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_trackEvent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_setTest(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_setTest(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

