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

    template<typename... ComponentTypes>
    class Engine {
    public:
        
        using GameState = std::tuple<std::vector<ComponentTypes>...>;
        
        template<typename SystemType>
        void addSystem() {
            systems.emplace_back(std::make_unique<SystemType>(*this));
        }
        
        template<typename ComponentType, typename... ComponentArgs>
        void createComponent(Entity& e, ComponentArgs... args) {
            auto& v = std::get<std::vector<ComponentType>>(state);
            auto& c = v.emplace_back();
            e.addComponent(ComponentType::hash_value);
        }
        
        template<typename ComponentType>
        auto& getAll() {
            return std::get<std::vector<ComponentType>>(state);
        }
        
        void update() {
            state.update();
        }
        
    private:

        GameState state;
        std::vector<Entity> entities;
        std::vector<std::unique_ptr<SystemBase>> systems;
        
    private:
        
        ScriptContext scriptContext;
    };
    
}
