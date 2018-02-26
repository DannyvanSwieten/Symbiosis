//
//  rigid_body.cpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "rigid_body.hpp"

#include "script_context.hpp"

namespace symbiosis
{
    const size_t RigidBody::hash_value;

    void RigidBody::reflect(ScriptContext& context) {
        context.getGlobalNamespace().beginNamespace("symbiosis").
        beginClass<RigidBody>("RigidBody").endClass().
        endNamespace();
    }
}
