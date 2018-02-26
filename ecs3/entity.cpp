//
//  entity.cpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "entity.hpp"

namespace symbiosis
{

    void Entity::addComponent(size_t c) {
        components.emplace_back(c);
    }
    
}
