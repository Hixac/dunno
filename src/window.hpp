#pragma once

#include <GLFW/glfw3.h>
#include <string_view>

namespace My {

    class Window {
    public:
        Window() = delete;
        Window(uint32_t x_size, uint32_t y_size, std::string_view name);
        ~Window();

        void NewFrame();
        void Render();
        
        void SwapBuffers();
        bool CheckHealth();
        
    private:
        std::string_view m_name;
        uint32_t m_x_size, m_y_size;
        GLFWwindow *m_window;
    };
    
}
