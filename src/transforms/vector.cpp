#include <transforms/vector.hpp>

namespace Object {

    Vector::Vector(float x, float y, float z)
        : x(x), y(y), z() {}

    float* Vector::RawArray() {
        return &x;
    }

    glm::vec3 Vector::AsGlmVec() {
        glm::vec3 r = {x, y, z};

        return r;
    }
    
}
