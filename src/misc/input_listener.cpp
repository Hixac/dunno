#include <misc/input_listener.hpp>

#include <GLFW/glfw3.h>

namespace Misc {

    Status Input::operator()(std::string_view v) {
        if (!statuses.contains(v.data())) {
            return Status::None;
        }
               
        return statuses.at(v.data());
    }

    void Input::Clear() {
        statuses.clear();
    }
    
    void _key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        auto& ref = Keys::Get();
        std::string key_str;
        
        if (key == GLFW_KEY_SPACE) {
            key_str = " ";
        }
        else if (key == GLFW_KEY_APOSTROPHE) {
            key_str = "'";
        }
        else if (key == GLFW_KEY_COMMA) {
            key_str = ",";
        }
        else if (key == GLFW_KEY_MINUS) {
            key_str = "-";
        }
        else if (key == GLFW_KEY_PERIOD) {
            key_str = ".";
        }
        else if (key == GLFW_KEY_SLASH) {
            key_str = "/";
        }
        else if (key == GLFW_KEY_0) {
            key_str = "0";
        }
        else if (key == GLFW_KEY_1) {
            key_str = "1";
        }
        else if (key == GLFW_KEY_2) {
            key_str = "2";
        }
        else if (key == GLFW_KEY_3) {
            key_str = "3";
        }
        else if (key == GLFW_KEY_4) {
            key_str = "4";
        }
        else if (key == GLFW_KEY_5) {
            key_str = "5";
        }
        else if (key == GLFW_KEY_6) {
            key_str = "6";
        }
        else if (key == GLFW_KEY_7) {
            key_str = "7";
        }
        else if (key == GLFW_KEY_8) {
            key_str = "8";
        }
        else if (key == GLFW_KEY_9) {
            key_str = "9";
        }
        else if (key == GLFW_KEY_SEMICOLON) {
            key_str = ";";
        }
        else if (key == GLFW_KEY_EQUAL) {
            key_str = "=";
        }
        else if (key == GLFW_KEY_A) {
            key_str = "a";
        }
        else if (key == GLFW_KEY_B) {
            key_str = "b";
        }
        else if (key == GLFW_KEY_C) {
            key_str = "c";
        }
        else if (key == GLFW_KEY_D) {
            key_str = "d";
        }
        else if (key == GLFW_KEY_E) {
            key_str = "e";
        }
        else if (key == GLFW_KEY_F) {
            key_str = "f";
        }
        else if (key == GLFW_KEY_G) {
            key_str = "g";
        }
        else if (key == GLFW_KEY_H) {
            key_str = "h";
        }
        else if (key == GLFW_KEY_I) {
            key_str = "i";
        }
        else if (key == GLFW_KEY_J) {
            key_str = "j";
        }
        else if (key == GLFW_KEY_K) {
            key_str = "k";
        }
        else if (key == GLFW_KEY_L) {
            key_str = "l";
        }
        else if (key == GLFW_KEY_M) {
            key_str = "m";
        }
        else if (key == GLFW_KEY_N) {
            key_str = "n";
        }
        else if (key == GLFW_KEY_O) {
            key_str = "o";
        }
        else if (key == GLFW_KEY_P) {
            key_str = "p";
        }
        else if (key == GLFW_KEY_Q) {
            key_str = "q";
        }
        else if (key == GLFW_KEY_R) {
            key_str = "r";
        }
        else if (key == GLFW_KEY_S) {
            key_str = "s";
        }
        else if (key == GLFW_KEY_T) {
            key_str = "t";
        }
        else if (key == GLFW_KEY_U) {
            key_str = "u";
        }
        else if (key == GLFW_KEY_V) {
            key_str = "v";
        }
        else if (key == GLFW_KEY_W) {
            key_str = "w";
        }
        else if (key == GLFW_KEY_X) {
            key_str = "x";
        }
        else if (key == GLFW_KEY_Y) {
            key_str = "y";
        }
        else if (key == GLFW_KEY_Z) {
            key_str = "z";
        }
        else if (key == GLFW_KEY_LEFT_BRACKET) {
            key_str = "[";
        }
        else if (key == GLFW_KEY_BACKSLASH) {
            key_str = "\\";
        }
        else if (key == GLFW_KEY_RIGHT_BRACKET) {
            key_str = "]";
        }
        else if (key == GLFW_KEY_GRAVE_ACCENT) {
            key_str = "`";
        }

        if (key_str.empty()) {
            return;
        }
        
        ref.statuses[key_str] = static_cast<Status>(action + 1);
    }

    void _mouse_callback(GLFWwindow* window, int button, int action, int mods) {
        auto& ref = Mouse::Get();
        std::string key_str;

        switch (button) {
        case GLFW_MOUSE_BUTTON_4:
            key_str = "4";
            break;
        case GLFW_MOUSE_BUTTON_5:
            key_str = "5";
            break;
        case GLFW_MOUSE_BUTTON_6:
            key_str = "6";
            break;
        case GLFW_MOUSE_BUTTON_7:
            key_str = "7";
            break;
        case GLFW_MOUSE_BUTTON_LAST:
            key_str = "last";
            break;
        case GLFW_MOUSE_BUTTON_LEFT:
            key_str = "left";
            break;
        case GLFW_MOUSE_BUTTON_RIGHT:
            key_str = "right";
            break;
        case GLFW_MOUSE_BUTTON_MIDDLE:
            key_str = "middle";
            break;
        default:
            return;
        }

        ref.statuses[key_str] = static_cast<Status>(action + 1);
    }
    
    void _cursor_callback(GLFWwindow* window, double xpos, double ypos) {
        auto& ref = Misc::Mouse::Get();

        ref.pos.x = xpos;
        ref.pos.y = ypos;
    }
}
