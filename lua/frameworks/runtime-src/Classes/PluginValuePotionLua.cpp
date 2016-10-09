#include "PluginValuePotionLua.hpp"
#include "PluginValuePotion/PluginValuePotion.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginValuePotionLua_PluginValuePotion_trackPurchaseEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 7)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginValuePotion:trackPurchaseEvent");
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            const char* arg3;
            std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg3 = arg3_tmp.c_str();
            if (!ok) { break; }
            const char* arg4;
            std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg4 = arg4_tmp.c_str();
            if (!ok) { break; }
            const char* arg5;
            std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg5 = arg5_tmp.c_str();
            if (!ok) { break; }
            const char* arg6;
            std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg6 = arg6_tmp.c_str();
            if (!ok) { break; }
            sdkbox::PluginValuePotion::trackPurchaseEvent(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginValuePotion:trackPurchaseEvent");
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            const char* arg3;
            std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg3 = arg3_tmp.c_str();
            if (!ok) { break; }
            const char* arg4;
            std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg4 = arg4_tmp.c_str();
            if (!ok) { break; }
            sdkbox::PluginValuePotion::trackPurchaseEvent(arg0, arg1, arg2, arg3, arg4);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 9)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "sdkbox.PluginValuePotion:trackPurchaseEvent");
            if (!ok) { break; }
            const char* arg4;
            std::string arg4_tmp; ok &= luaval_to_std_string(tolua_S, 6, &arg4_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg4 = arg4_tmp.c_str();
            if (!ok) { break; }
            const char* arg5;
            std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg5 = arg5_tmp.c_str();
            if (!ok) { break; }
            const char* arg6;
            std::string arg6_tmp; ok &= luaval_to_std_string(tolua_S, 8, &arg6_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg6 = arg6_tmp.c_str();
            if (!ok) { break; }
            const char* arg7;
            std::string arg7_tmp; ok &= luaval_to_std_string(tolua_S, 9, &arg7_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg7 = arg7_tmp.c_str();
            if (!ok) { break; }
            const char* arg8;
            std::string arg8_tmp; ok &= luaval_to_std_string(tolua_S, 10, &arg8_tmp, "sdkbox.PluginValuePotion:trackPurchaseEvent"); arg8 = arg8_tmp.c_str();
            if (!ok) { break; }
            sdkbox::PluginValuePotion::trackPurchaseEvent(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginValuePotion:trackPurchaseEvent",argc, 9);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_trackPurchaseEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_openInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:openInterstitial"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginValuePotionLua_PluginValuePotion_openInterstitial'", nullptr);
            return 0;
        }
        sdkbox::PluginValuePotion::openInterstitial(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion:openInterstitial",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_openInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_hasCachedInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:hasCachedInterstitial"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginValuePotionLua_PluginValuePotion_hasCachedInterstitial'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginValuePotion::hasCachedInterstitial(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion:hasCachedInterstitial",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_hasCachedInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_userinfo(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:userinfo"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "sdkbox.PluginValuePotion:userinfo"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginValuePotionLua_PluginValuePotion_userinfo'", nullptr);
            return 0;
        }
        sdkbox::PluginValuePotion::userinfo(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion:userinfo",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_userinfo'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_trackEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:trackEvent"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginValuePotion:trackEvent");
            if (!ok) { break; }
            sdkbox::PluginValuePotion::trackEvent(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:trackEvent"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            sdkbox::PluginValuePotion::trackEvent(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:trackEvent"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "sdkbox.PluginValuePotion:trackEvent"); arg1 = arg1_tmp.c_str();
            if (!ok) { break; }
            const char* arg2;
            std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "sdkbox.PluginValuePotion:trackEvent"); arg2 = arg2_tmp.c_str();
            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "sdkbox.PluginValuePotion:trackEvent");
            if (!ok) { break; }
            sdkbox::PluginValuePotion::trackEvent(arg0, arg1, arg2, arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginValuePotion:trackEvent",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_trackEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginValuePotionLua_PluginValuePotion_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginValuePotion::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_cacheInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginValuePotion:cacheInterstitial"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginValuePotionLua_PluginValuePotion_cacheInterstitial'", nullptr);
            return 0;
        }
        sdkbox::PluginValuePotion::cacheInterstitial(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion:cacheInterstitial",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_cacheInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginValuePotionLua_PluginValuePotion_setTest(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginValuePotion:setTest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginValuePotionLua_PluginValuePotion_setTest'", nullptr);
            return 0;
        }
        sdkbox::PluginValuePotion::setTest(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion:setTest",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_setTest'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginValuePotionLua_PluginValuePotion_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginValuePotion)");
    return 0;
}

int lua_register_PluginValuePotionLua_PluginValuePotion(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginValuePotion");
    tolua_cclass(tolua_S,"PluginValuePotion","sdkbox.PluginValuePotion","",nullptr);

    tolua_beginmodule(tolua_S,"PluginValuePotion");
        tolua_function(tolua_S,"trackPurchaseEvent", lua_PluginValuePotionLua_PluginValuePotion_trackPurchaseEvent);
        tolua_function(tolua_S,"openInterstitial", lua_PluginValuePotionLua_PluginValuePotion_openInterstitial);
        tolua_function(tolua_S,"hasCachedInterstitial", lua_PluginValuePotionLua_PluginValuePotion_hasCachedInterstitial);
        tolua_function(tolua_S,"userinfo", lua_PluginValuePotionLua_PluginValuePotion_userinfo);
        tolua_function(tolua_S,"trackEvent", lua_PluginValuePotionLua_PluginValuePotion_trackEvent);
        tolua_function(tolua_S,"init", lua_PluginValuePotionLua_PluginValuePotion_init);
        tolua_function(tolua_S,"cacheInterstitial", lua_PluginValuePotionLua_PluginValuePotion_cacheInterstitial);
        tolua_function(tolua_S,"setTest", lua_PluginValuePotionLua_PluginValuePotion_setTest);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginValuePotion).name();
    g_luaType[typeName] = "sdkbox.PluginValuePotion";
    g_typeCast["PluginValuePotion"] = "sdkbox.PluginValuePotion";
    return 1;
}
TOLUA_API int register_all_PluginValuePotionLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginValuePotionLua_PluginValuePotion(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

