#include "PluginValuePotionJS.hpp"
#include "PluginValuePotion/PluginValuePotion.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

#if (SDKBOX_COCOS_JSB_VERSION >= 2)
        JS::RootedObject proto(cx, typeClass->proto.ref());
        JS::RootedObject parent(cx, typeClass->parentProto.ref());
#else
        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
#endif
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));

        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginValuePotion_class;
JSObject *jsb_sdkbox_PluginValuePotion_prototype;

bool js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 7) {
            const char* arg0;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            double arg1;
            ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            const char* arg2;
            std::string arg2_tmp; ok &= jsval_to_std_string(cx, args.get(2), &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg3;
            std::string arg3_tmp; ok &= jsval_to_std_string(cx, args.get(3), &arg3_tmp); arg3 = arg3_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg4;
            std::string arg4_tmp; ok &= jsval_to_std_string(cx, args.get(4), &arg4_tmp); arg4 = arg4_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg5;
            std::string arg5_tmp; ok &= jsval_to_std_string(cx, args.get(5), &arg5_tmp); arg5 = arg5_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg6;
            std::string arg6_tmp; ok &= jsval_to_std_string(cx, args.get(6), &arg6_tmp); arg6 = arg6_tmp.c_str();
            if (!ok) { ok = true; break; }
            sdkbox::PluginValuePotion::trackPurchaseEvent(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 5) {
            const char* arg0;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            double arg1;
            ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            const char* arg2;
            std::string arg2_tmp; ok &= jsval_to_std_string(cx, args.get(2), &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg3;
            std::string arg3_tmp; ok &= jsval_to_std_string(cx, args.get(3), &arg3_tmp); arg3 = arg3_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg4;
            std::string arg4_tmp; ok &= jsval_to_std_string(cx, args.get(4), &arg4_tmp); arg4 = arg4_tmp.c_str();
            if (!ok) { ok = true; break; }
            sdkbox::PluginValuePotion::trackPurchaseEvent(arg0, arg1, arg2, arg3, arg4);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 9) {
            const char* arg0;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg1;
            std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg2;
            std::string arg2_tmp; ok &= jsval_to_std_string(cx, args.get(2), &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { ok = true; break; }
            double arg3;
            ok &= sdkbox::js_to_number(cx, args.get(3), &arg3);
            if (!ok) { ok = true; break; }
            const char* arg4;
            std::string arg4_tmp; ok &= jsval_to_std_string(cx, args.get(4), &arg4_tmp); arg4 = arg4_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg5;
            std::string arg5_tmp; ok &= jsval_to_std_string(cx, args.get(5), &arg5_tmp); arg5 = arg5_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg6;
            std::string arg6_tmp; ok &= jsval_to_std_string(cx, args.get(6), &arg6_tmp); arg6 = arg6_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg7;
            std::string arg7_tmp; ok &= jsval_to_std_string(cx, args.get(7), &arg7_tmp); arg7 = arg7_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg8;
            std::string arg8_tmp; ok &= jsval_to_std_string(cx, args.get(8), &arg8_tmp); arg8 = arg8_tmp.c_str();
            if (!ok) { ok = true; break; }
            sdkbox::PluginValuePotion::trackPurchaseEvent(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent : wrong number of arguments");
    return false;
}
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_openInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        const char* arg0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_PluginValuePotionJS_PluginValuePotion_openInterstitial : Error processing arguments");
        sdkbox::PluginValuePotion::openInterstitial(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_openInterstitial : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_openInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        const char* arg0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginValuePotion::openInterstitial(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        const char* arg0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial : Error processing arguments");
        bool ret = sdkbox::PluginValuePotion::hasCachedInterstitial(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        const char* arg0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginValuePotion::hasCachedInterstitial(arg0);
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_userinfo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_PluginValuePotionJS_PluginValuePotion_userinfo : Error processing arguments");
        sdkbox::PluginValuePotion::userinfo(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_userinfo : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_userinfo(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginValuePotion::userinfo(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
bool js_PluginValuePotionJS_PluginValuePotion_trackEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            double arg1;
            ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginValuePotion::trackEvent(arg0, arg1);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            sdkbox::PluginValuePotion::trackEvent(arg0);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 4) {
            const char* arg0;
            std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg1;
            std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
            if (!ok) { ok = true; break; }
            const char* arg2;
            std::string arg2_tmp; ok &= jsval_to_std_string(cx, args.get(2), &arg2_tmp); arg2 = arg2_tmp.c_str();
            if (!ok) { ok = true; break; }
            double arg3;
            ok &= sdkbox::js_to_number(cx, args.get(3), &arg3);
            if (!ok) { ok = true; break; }
            sdkbox::PluginValuePotion::trackEvent(arg0, arg1, arg2, arg3);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_trackEvent : wrong number of arguments");
    return false;
}
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginValuePotion::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginValuePotion::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        const char* arg0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial : Error processing arguments");
        sdkbox::PluginValuePotion::cacheInterstitial(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        const char* arg0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginValuePotion::cacheInterstitial(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginValuePotionJS_PluginValuePotion_setTest(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginValuePotionJS_PluginValuePotion_setTest : Error processing arguments");
        sdkbox::PluginValuePotion::setTest(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginValuePotionJS_PluginValuePotion_setTest : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginValuePotionJS_PluginValuePotion_setTest(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginValuePotion::setTest(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginValuePotionJS_PluginValuePotion_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginValuePotion)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;

#if (SDKBOX_COCOS_JSB_VERSION >= 2)
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
#else
    jsproxy = jsb_get_js_proxy(obj);
#endif

    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginValuePotion *nobj = static_cast<sdkbox::PluginValuePotion *>(nproxy->ptr);
        if (nobj)
            delete nobj;

        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginValuePotion_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginValuePotion_class->name = "PluginValuePotion";
    jsb_sdkbox_PluginValuePotion_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginValuePotion_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginValuePotion_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginValuePotion_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginValuePotion_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginValuePotion_class->finalize = js_PluginValuePotionJS_PluginValuePotion_finalize;
    jsb_sdkbox_PluginValuePotion_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("trackPurchaseEvent", js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openInterstitial", js_PluginValuePotionJS_PluginValuePotion_openInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hasCachedInterstitial", js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("userinfo", js_PluginValuePotionJS_PluginValuePotion_userinfo, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("trackEvent", js_PluginValuePotionJS_PluginValuePotion_trackEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginValuePotionJS_PluginValuePotion_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheInterstitial", js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTest", js_PluginValuePotionJS_PluginValuePotion_setTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginValuePotion_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginValuePotion_class,
        dummy_constructor<sdkbox::PluginValuePotion>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginValuePotion", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
    JS::RootedObject proto(cx, jsb_sdkbox_PluginValuePotion_prototype);
    jsb_register_class<sdkbox::PluginValuePotion>(cx, jsb_sdkbox_PluginValuePotion_class, proto, JS::NullPtr());
#else
    TypeTest<sdkbox::PluginValuePotion> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginValuePotion_class;
        p->proto = jsb_sdkbox_PluginValuePotion_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif
}
#else
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginValuePotion_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginValuePotion_class->name = "PluginValuePotion";
    jsb_sdkbox_PluginValuePotion_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginValuePotion_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginValuePotion_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginValuePotion_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginValuePotion_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginValuePotion_class->finalize = js_PluginValuePotionJS_PluginValuePotion_finalize;
    jsb_sdkbox_PluginValuePotion_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("trackPurchaseEvent", js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openInterstitial", js_PluginValuePotionJS_PluginValuePotion_openInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hasCachedInterstitial", js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("userinfo", js_PluginValuePotionJS_PluginValuePotion_userinfo, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("trackEvent", js_PluginValuePotionJS_PluginValuePotion_trackEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginValuePotionJS_PluginValuePotion_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheInterstitial", js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTest", js_PluginValuePotionJS_PluginValuePotion_setTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginValuePotion_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginValuePotion_class,
        dummy_constructor<sdkbox::PluginValuePotion>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginValuePotion", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginValuePotion> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginValuePotion_class;
        p->proto = jsb_sdkbox_PluginValuePotion_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginValuePotionJS_PluginValuePotion(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginValuePotion_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginValuePotion_class->name = "PluginValuePotion";
    jsb_sdkbox_PluginValuePotion_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginValuePotion_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginValuePotion_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginValuePotion_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginValuePotion_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginValuePotion_class->finalize = js_PluginValuePotionJS_PluginValuePotion_finalize;
    jsb_sdkbox_PluginValuePotion_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("trackPurchaseEvent", js_PluginValuePotionJS_PluginValuePotion_trackPurchaseEvent, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openInterstitial", js_PluginValuePotionJS_PluginValuePotion_openInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hasCachedInterstitial", js_PluginValuePotionJS_PluginValuePotion_hasCachedInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("userinfo", js_PluginValuePotionJS_PluginValuePotion_userinfo, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("trackEvent", js_PluginValuePotionJS_PluginValuePotion_trackEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginValuePotionJS_PluginValuePotion_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cacheInterstitial", js_PluginValuePotionJS_PluginValuePotion_cacheInterstitial, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTest", js_PluginValuePotionJS_PluginValuePotion_setTest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginValuePotion_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginValuePotion_class,
        dummy_constructor<sdkbox::PluginValuePotion>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginValuePotion", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginValuePotion> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginValuePotion_class;
        p->proto = jsb_sdkbox_PluginValuePotion_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginValuePotionJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginValuePotionJS_PluginValuePotion(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginValuePotionJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginValuePotionJS_PluginValuePotion(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginValuePotionJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginValuePotionJS_PluginValuePotion(cx, obj);

    sdkbox::setProjectType("js");
}
#endif