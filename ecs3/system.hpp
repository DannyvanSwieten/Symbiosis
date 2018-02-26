//
//  system.hpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <array>

namespace symbiosis
{

    class SystemBase {
    public:
        virtual void update() = 0;
        
    };

    template<typename... SystemTypes>
    class SystemImplementation: public SystemBase {
    public:
        
        constexpr SystemImplementation() {
            size_t index = 0;
            (addComponentHash(index++, SystemTypes::hash_value), ...);
        }
        
        auto& getComponentHashes() const {
            return componentHashes;
        }
        
    private:
        constexpr void addComponentHash(size_t index, size_t componentHash) {
            componentHashes[index] = componentHash;
        }
        
    protected:
        
        // These are used to identify which entities this system operates on.
        std::array<size_t, sizeof...(SystemTypes)> componentHashes;
    };
}
