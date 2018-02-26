//
//  editor_context.cpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#include "editor_context.hpp"

EditorContext::EditorContext(Engine& engine): engine(engine) {
	
}

void EditorContext::createComponent(const std::string& name, Entity& entity) {
	ctors[name](entity);
}

void EditorContext::printReflectedComponents() {
	for(const auto& s: ctors)
		std::cout << s.first << '\n';
}
