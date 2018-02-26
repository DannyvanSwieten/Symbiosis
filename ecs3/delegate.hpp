//
//  delegate.hpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <functional>
#include <vector>

template<typename... Arguments>
class Delegate {
	
	using callback_t = std::function<void(Arguments...)>;
	class Signal {
	public:
		Signal(void* object, callback_t cb): object(object), function(cb) { }
		void operator ()(Arguments... args) {
			function(args...);
		}
	private:
		
		void* object;
		callback_t function;
	};
	
public:
	
	template<typename T>
	void connect(T& obj, void (T::*func) (Arguments...) ) {
		std::function < void (T, Arguments...) >  f = func;
		callback_t fun = [&obj, f](Arguments... params) { f(obj, params...); };
		signals.emplace_back(&obj, fun);
	}
	
	void operator()(Arguments... args) {
		for(auto& signal: signals)
			signal(args...);
	}
	
	std::vector<Signal> signals;
};
