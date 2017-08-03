#ifndef __PluginValuePotionJS_h__
#define __PluginValuePotionJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JS::HandleObject global);
void register_all_PluginValuePotionJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JSObject* global);
void register_all_PluginValuePotionJS(JSContext* cx, JSObject* obj);
#endif
#endif

