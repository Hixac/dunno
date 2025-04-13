#pragma once

#include <glm/gtc/matrix_transform.hpp>

using vec2 = glm::vec2;
using vec3 = glm::vec3;
using vec4 = glm::vec4;
using mat4 = glm::mat4;

namespace Object {

    using namespace glm;
    
    class Transform {
    public:
        Transform(float p);
        Transform(const Transform& t);
        Transform(Transform&& t);

        Transform& operator=(const Transform& t);
        Transform& operator=(Transform&& t);
        
        Transform& operator+=(const Transform& t);
        Transform& operator*=(const Transform& t);
        
        friend Transform operator+(Transform s, const Transform& t) {
            s += t;
            return s;
        }
        friend Transform operator*(Transform s, const Transform& t) {
            s *= t;
            return s;
        }
        
        Transform Rotate(float angle, vec3 whence);
        Transform Scale(vec3 size);
        Transform Translate(vec3 whence);

        Transform LookAt(vec3 eye, vec3 center, vec3 up);
        Transform Ortho(float left, float right, float bottom, float top, float z_near, float z_far);
        Transform Perspective(float fovy, float aspect, float z_near, float z_far);

        Transform Reset();
        
        mat4 Get();
        
    private:
        mat4 m_trans;
    };
    
}
