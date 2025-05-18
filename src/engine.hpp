#pragma once

#include <engine/shader.hpp>
#include <engine/shader_program.hpp>
#include <engine/texture.hpp>
#include <engine/vertex_array.hpp>

#include <GLFW/glfw3.h>

#include <iostream>

namespace OpenGl {

    void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
    
    static void init() {
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
            std::abort();
        }
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(MessageCallback, 0);
    }

    static void clear() {
        glClearColor(0.1f, 0.2f, 0.3f, 0.4f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    static void draw_vertices(size_t count) {
        glDrawArrays(GL_TRIANGLES, 0, count);
    }

    static void draw_elems(size_t indices_size) {
        glDrawElements(GL_TRIANGLES, indices_size, GL_UNSIGNED_INT, 0);
    }
}
