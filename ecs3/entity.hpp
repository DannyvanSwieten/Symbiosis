//
//  entity.hpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <vector>

#include "component.hpp"

namespace symbiosis
{
    
    class Entity {
    public:
        void addComponent(size_t c);
        
        void update();
        
    private:
        
        std::vector<size_t> components;
    };

}
