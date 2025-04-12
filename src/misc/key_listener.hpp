#pragma once

#include <string_view>
#include <unordered_map>

struct GLFWwindow;

namespace Misc {

    enum class Status {
        None,
        Release,
        Press,
        Repeat,
        Press_Or_Release
    };
    
    class Keys {
    public:
        static Keys& Get() {
            static Keys k;

            return k;
        }

        Status operator()(std::string_view);
            
        void Clear();

        std::unordered_map<std::string_view, Status> keys_statuses;
        
    private:
        
        Keys() = default;
    };


    void _key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
}
