//
//  editor_context.hpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <boost/variant.hpp>
#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "engine.hpp"

using Property = boost::variant<float, size_t>;

struct ComponentProperty {
	template<typename T>
	ComponentProperty(const std::string& name, const T& defaultValue): name(name), property(defaultValue) {
		
	}
	
	std::string name;
	Property property;
};

class ComponentEditorClass {
public:
	template<typename T>
	ComponentEditorClass& addProperty(const std::string& name, const T& defaultValue) {
		fields.emplace_back(name, defaultValue);
		return *this;
	}
	
	std::vector<ComponentProperty> fields;
};

//class EditorContext {
//public:
//
//	EditorContext(Engine& engine);
//
//	template<typename T>
//	void registerComponent() {
//
//		auto ctor = [&](Entity& e) {
//			engine.createComponent<T>(e);
//		};
//
//		ctors.emplace(T::id, ctor);
//
//		T::reflect(*this);
//	}
//
//	template<typename T>
//	ComponentEditorClass& createClass(const std::string& name){
//		classes.emplace(T::hash_value, ComponentEditorClass());
//		return classes[T::hash_value];
//	}
//
//	void createComponent(const std::string& name, Entity& entity);
//	void printReflectedComponents();
//
//private:
//
//	Engine& engine;
//	std::map<std::string, std::function<void(Entity&)>> ctors;
//	std::map<std::size_t, ComponentEditorClass> classes;
//};

