//
//  engine.h
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include "entity.hpp"
#include "script_context.hpp"
#include "system.hpp"

namespace symbiosis
{

    // The engine class is the starting point. It takes a parameter pack of all supported components.
    template<typename... ComponentTypes>
    class Engine {
    public:
        
        // A tuple of of vectors of all the component types this engine supports
        using GameState = std::tuple<std::vector<ComponentTypes>...>;
        
        // Create a system of type SystemType and pass this to the ctor
        template<typename SystemType>
        void addSystem() {
            systems.emplace_back(std::make_unique<SystemType>(*this));
        }
        
        // Creates a component of type ComponentType with ComponentArgs as possible arguments.
        template<typename ComponentType, typename... ComponentArgs>
        void createComponent(Entity& e, ComponentArgs... args) {
            auto& v = std::get<std::vector<ComponentType>>(state);
            auto& c = v.emplace_back();
            e.addComponent(ComponentType::hash_value);
        }
        
        // Returns a reference to a vector with all instances of type ComponentType
        template<typename ComponentType>
        auto& getAll() {
            return std::get<std::vector<ComponentType>>(state);
        }
        
    private:

        GameState state;
        std::vector<Entity> entities;
        std::vector<std::unique_ptr<SystemBase>> systems;
        
    private:
        
        ScriptContext scriptContext;
    };
    
}
