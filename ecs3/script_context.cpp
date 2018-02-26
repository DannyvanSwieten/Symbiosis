//
//  script_context.cpp
//  ecs3
//
//  Created by Danny van Swieten on 21/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "script_context.hpp"

namespace symbiosis
{
    ScriptContext::ScriptContext() {
        state = luaL_newstate();
        assert(state);
    }
    
    luabridge::Namespace ScriptContext::getGlobalNamespace() {
        return luabridge::getGlobalNamespace(state);
    }
}
