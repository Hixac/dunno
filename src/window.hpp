#pragma once

#include <misc/input_listener.hpp>

#include <GLFW/glfw3.h>
#include <string>

namespace My {

    using Misc::Status;
    struct Input {
        inline Input(std::string_view v)
            : m_v(v) {}

        inline bool operator==(Status s) {
            auto ks = Misc::Input::Get()(m_v);
            
            if (s == Status::Press_Or_Repeat) {
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
        Window(uint32_t x_size, uint32_t y_size, const std::string& name);
        ~Window();

        vec2 GetSize();
        
        void NewFrame();
        void Render();
        
        void SwapBuffers();
        bool CheckHealth();

        void EnableCursor(bool);
        
    private:
        std::string m_name;
        GLFWwindow *m_window;
    };
    
}
