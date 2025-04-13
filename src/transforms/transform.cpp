#include <transforms/transform.hpp>

namespace Object {

    Transform::Transform(float p)
        : m_trans(p) {}

    Transform::Transform(const Transform& t)
        : m_trans(t.m_trans) {}
    
    Transform::Transform(Transform&& t)
        : m_trans(std::move(t.m_trans)) {}

    Transform& Transform::operator=(const Transform& t) {
        if (this == &t) {
            return *this;
        }

        this->m_trans = t.m_trans;
        return *this;
    }

    Transform& Transform::operator=(Transform&& t) {
        if (this == &t) {
            return *this;
        }

        this->m_trans = t.m_trans;
        return *this;
    }
    
    Transform& Transform::operator+=(const Transform& t) {
        this->m_trans += t.m_trans;

        return *this;
    }
    
    Transform& Transform::operator*=(const Transform& t) {
        this->m_trans *= t.m_trans;

        return *this;
    }
    
    Transform Transform::Rotate(float angle, vec3 whence) {
        m_trans = glm::rotate(m_trans, glm::radians(angle), whence);

        return *this;
    }

    Transform Transform::Scale(vec3 size) {
        m_trans = glm::scale(m_trans, size);

        return *this;
    }

    Transform Transform::Translate(vec3 whence) {
        m_trans = glm::translate(m_trans, whence);
        
        return *this;
    }

    Transform Transform::LookAt(vec3 eye, vec3 center, vec3 up) {
        m_trans = glm::lookAt(eye, center, up);

        return *this;
    }
    
    Transform Transform::Ortho(float left, float right, float bottom, float top, float z_near, float z_far) {
        m_trans = glm::ortho(left, right, bottom, top, z_near, z_far);

        return *this;
    }
    
    Transform Transform::Perspective(float fovy, float aspect, float z_near, float z_far) {
        m_trans = glm::perspective(glm::radians(fovy), aspect, z_near, z_far);

        return *this;
    }

    Transform Transform::Reset() {
        m_trans = mat4(1.f);

        return *this;
    }
    
    mat4 Transform::Get() {
        return m_trans;
    }
    
}
