#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

#include <transforms/transform.hpp>

struct GLFWwindow;

namespace Misc {

    enum class Status {
        None,
        Release,
        Press,
        Repeat,
        Press_Or_Release
    };

    class Input {
    private:
        friend class Mouse;
        friend class Keys;

        Input() = default;
        
    public:
        Status operator()(std::string_view);
        void Clear();
        
        std::unordered_map<std::string, Status> statuses;
    };
    
    class Mouse : public Input {
    public:
        static Mouse& Get() {
            static Mouse m;

            return m;
        }

        vec2 pos = {};
    private:
        Mouse() = default;    
    };
    
    class Keys : public Input {
    public:
        static Keys& Get() {
            static Keys k;

            return k;
        }
    private:
        Keys() = default;
    };


    void _key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void _mouse_callback(GLFWwindow* window, int button, int action, int mods);
    void _cursor_callback(GLFWwindow* window, double xpos, double ypos);
    
}
