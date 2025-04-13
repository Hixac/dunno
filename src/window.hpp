#pragma once

#include <misc/input_listener.hpp>

#include <GLFW/glfw3.h>
#include <string_view>

namespace My {

    using Misc::Mouse;
    using Misc::Status;
    struct Keys {
        inline Keys(std::string_view v)
            : m_v(v) {}

        inline bool operator==(Status s) {
            auto ks = Misc::Keys::Get()(m_v);
            
            if (s == Status::Press_Or_Release) {
                return ks == Status::Press || ks == Status::Repeat;
            }
            return ks == s;
        }
        
    private:
        std::string_view m_v;
    };
    
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
