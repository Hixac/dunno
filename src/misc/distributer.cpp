#include <misc/distributer.hpp>

#include <GLFW/glfw3.h>

namespace Misc {

    void Distributer::CalculateFrameTime() {
        current_frame = glfwGetTime();
        dt = current_frame - last_frame;
        last_frame = current_frame;
    }
}
