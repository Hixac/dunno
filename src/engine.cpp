#include <engine.hpp>

#include <objects/line.hpp>
#include <memory>

namespace OpenGl {

    void GLAPIENTRY MessageCallback( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam ) {
        fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n", ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ), type, severity, message);
    }

    void draw_ray(const Object::Ray &ray, float len) {
        auto line = std::make_unique<Object::Line>(Object::Line(ray.origin, ray.origin + len * ray.direction, {0.5f, 0.5f, 0.5f}));
        line->Draw();
    }
    
}
