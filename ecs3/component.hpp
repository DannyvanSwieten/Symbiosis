//
//  component.hpp
//  ecs3
//
//  Created by Danny on 19/02/2018.
//  Copyright © 2018 Danny. All rights reserved.
//

#pragma once

#include <cstddef>

namespace symbiosis
{
    #define COMPONENT_HASH(name) static const size_t hash_value = hash(#name); static constexpr char* id = #name;

    // FNV-1a constants
    static constexpr unsigned long long basis = 14695981039346656037ULL;
    static constexpr unsigned long long prime = 1099511628211ULL;

    // compile-time hash helper function
    constexpr size_t hashOne(char c, const char* const remain, unsigned long long value)
    {
        return c == 0 ? value : hashOne(remain[0], remain + 1, (value ^ c) * prime);
    }

    // compile-time hash
    constexpr size_t hash(const char* const str)
    {
        return hashOne(str[0], str + 1, basis);
    }
}
