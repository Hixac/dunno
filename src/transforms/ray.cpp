#include <transforms/ray.hpp>

namespace Object {

    Ray::Ray(vec3 origin, vec3 direction)
        : origin(origin), direction(direction) {
        inverted_direction = { 1 / direction.x, 1 / direction.y, 1 / direction.z };
        
        sign = {
            inverted_direction.x < 0,
            inverted_direction.y < 0,
            inverted_direction.z < 0
        };
    }
    
}
