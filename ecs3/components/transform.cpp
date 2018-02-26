//
//  transform.cpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "transform.hpp"

#include "script_context.hpp"

namespace symbiosis
{
    
    const size_t Transform::hash_value;

    void Transform::reflect(ScriptContext& context) {
        
        context.getGlobalNamespace().beginNamespace("symbiosis").
        beginClass<Transform>("Transform").endClass().
        endNamespace();
    }
    
}
