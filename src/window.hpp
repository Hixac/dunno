#pragma once

#include <misc/key_listener.hpp>

#include <GLFW/glfw3.h>
#include <string_view>

namespace My {

    using Key_Status = Misc::Status;
    struct Keys {
        inline Keys(std::string_view v)
            : m_v(v) {}

        inline bool operator==(Key_Status s) {
            auto ks = Misc::Keys::Get()(m_v);
            
            if (s == Key_Status::Press_Or_Release) {
                return ks == Key_Status::Press || ks == Key_Status::Repeat;
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
