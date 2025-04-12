#pragma once

#include <glm/glm.hpp>

namespace Object {

    struct Vector {
        float x, y, z;

        Vector(float x, float y, float z);

        float* RawArray();
        glm::vec3 AsGlmVec();
    };
    
}
