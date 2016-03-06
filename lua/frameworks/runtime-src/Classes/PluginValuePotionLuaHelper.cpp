
#include "PluginValuePotionLuaHelper.h"
#include "PluginValuePotion/PluginValuePotion.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class ValuePotionListenerLua : public sdkbox::ValuePotionListener {
public:
	ValuePotionListenerLua(): mLuaHandler(0) {
	}

	~ValuePotionListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (mLuaHandler == luaHandler) {
			return;
		}
		resetHandler();
		mLuaHandler = luaHandler;
	}

	void resetHandler() {
		if (0 == mLuaHandler) {
			return;
		}

        LUAENGINE->removeScriptHandler(mLuaHandler);
		mLuaHandler = 0;
	}

    void onCacheInterstitial(const char *placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onCacheInterstitial")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onFailToCacheInterstitial(const char *placement, const char *errorMessage) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onFailToCacheInterstitial")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));
        dict.insert(std::make_pair("errorMessage", LuaValue::stringValue(errorMessage)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onOpenInterstitial(const char *placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onOpenInterstitial")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onFailToOpenInterstitial(const char *placement, const char *errorMessage) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onFailToOpenInterstitial")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));
        dict.insert(std::make_pair("errorMessage", LuaValue::stringValue(errorMessage)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onCloseInterstitial(const char *placement) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onCloseInterstitial")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onRequestOpenURL(const char *placement, const char *URL) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onRequestOpenURL")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));
        dict.insert(std::make_pair("URL", LuaValue::stringValue(URL)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onRequestPurchase(const char *placement, const char *name, const char *productId, int quantity, const char *campaignId, const char *contentId) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onRequestPurchase")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("productId", LuaValue::stringValue(productId)));
        dict.insert(std::make_pair("quantity", LuaValue::intValue(quantity)));
        dict.insert(std::make_pair("campaignId", LuaValue::stringValue(campaignId)));
        dict.insert(std::make_pair("contentId", LuaValue::stringValue(contentId)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onRequestRewards(const char *placement, std::vector<sdkbox::ValuePotionReward> rewards) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueArray array;

        for (int i = 0; i < rewards.size(); i++) {
            LuaValueDict rewardDict;
            rewardDict.insert(std::make_pair("name", LuaValue::stringValue(rewards[i].name)));
            rewardDict.insert(std::make_pair("quantity", LuaValue::intValue(rewards[i].quantity)));
            array.push_back(LuaValue::dictValue(rewardDict));
        }

        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("onRequestRewards")));
        dict.insert(std::make_pair("placement", LuaValue::stringValue(placement)));
        dict.insert(std::make_pair("rewards", LuaValue::arrayValue(array)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
	int mLuaHandler;
};

int lua_PluginValuePotionLua_PluginValuePotion_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginValuePotion",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        ValuePotionListenerLua* lis = static_cast<ValuePotionListenerLua*> (sdkbox::PluginValuePotion::getListener());
        if (NULL == lis) {
            lis = new ValuePotionListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginValuePotion::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginValuePotion::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginValuePotionLua_PluginValuePotion_setListener'.",&tolua_err);
#endif
    return 0;
}


int extern_PluginValuePotion(lua_State* L) {
	if (NULL == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginValuePotion");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginValuePotionLua_PluginValuePotion_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginValuePotionLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginValuePotion(L);

	tolua_endmodule(L);
	return 1;
}


