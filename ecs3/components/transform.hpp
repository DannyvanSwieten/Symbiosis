//
//  transform.h
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
    
    class Transform {
    public:
        COMPONENT_HASH(Transform)
        
        static void reflect(ScriptContext& context);
    };
    
}
