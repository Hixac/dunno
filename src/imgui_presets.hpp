#pragma once

#include <imgui.h>
#include <string_view>
#include <iostream>

namespace MyGui {

    class Frame {
    public:
        Frame(std::string_view name) {
            if (!ImGui::Begin(name.data())) {
                std::cerr << "FATAL: imgui begin gone wrong" << std::endl;
                std::abort();
            }
        }

        Frame checkbox(std::string_view name, bool& active) {
            ImGui::Checkbox(name.data(), &active);

            return *this;
        }
        
        Frame slider(std::string_view name, float& v, float v_min, float v_max) {
            ImGui::SliderFloat(name.data(), &v, v_min, v_max);
            return *this;
        }

        Frame sliders3(std::string_view name, float* arr, float v_min, float v_max) {
            ImGui::SliderFloat3(name.data(), arr, v_min, v_max);
            return *this;
        }
        
        void end() {
            ImGui::End();
        }
        
    private:
        Frame() = delete;
    };

    static Frame create(std::string_view name) {
        Frame f(name);
        
        return f;
    }
    
}
