#pragma once

#include <engine/shader.hpp>
#include <engine/shader_program.hpp>
#include <engine/texture.hpp>
#include <engine/vertex.hpp>

#include <GLFW/glfw3.h>

#include <iostream>

namespace OpenGl {

    static void init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
            std::abort();
        }
        glEnable(GL_DEPTH_TEST);
    }

    static void clear() {
        glClearColor(0.1f, 0.2f, 0.3f, 0.4f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    static void draw_cube() {
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    
}
