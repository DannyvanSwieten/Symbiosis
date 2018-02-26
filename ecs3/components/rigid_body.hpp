//
//  rigid_body.hpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include "component.hpp"

namespace symbiosis
{
    class ScriptContext;
    class RigidBody {
    public:
        COMPONENT_HASH(RigidBody)
        
        static void reflect(ScriptContext& context);
    };
    
}
