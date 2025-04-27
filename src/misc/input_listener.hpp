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
        Press_Or_Repeat
    };

    class Input {
    private:
        Input() = default;
    public:
        static Input& Get() {
            static Input var;

            return var;
        }
        
        Status operator()(std::string_view);
        void Clear();
        
        std::unordered_map<std::string, Status> key_statuses;

        vec2 mouse_pos = {};
    };

    void _key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void _mouse_callback(GLFWwindow* window, int button, int action, int mods);
    void _cursor_callback(GLFWwindow* window, double xpos, double ypos);
    
}
