#pragma once

#include <transforms/transform.hpp>
#include <array>

namespace Object {

    class Ray {
    public:
        Ray(vec3 origin, vec3 direction);

        vec3 origin, direction;
        vec3 inverted_direction;
        std::array<bool, 3> sign;
    };
    
}
