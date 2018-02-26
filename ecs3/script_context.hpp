//
//  script_context.hpp
//  ecs3
//
//  Created by Danny van Swieten on 21/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

namespace symbiosis
{
    class ScriptContext {
    public:
        
        ScriptContext();
        
        luabridge::Namespace getGlobalNamespace();
        
    private:
        
        lua_State* state = nullptr;
    };
}
