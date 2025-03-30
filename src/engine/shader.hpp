#pragma once

#include <glad/glad.h>
#include <filesystem>
#include <vector>

#include <engine/shader_program.hpp>

namespace My {

    enum class ShaderType : unsigned int {
        FRAGMENT = 0x8B30,
        VERTEX = 0x8B31
    };
    
    class Shader {
    public:
        Shader(ShaderType type);
        ~Shader();

        void Source(const std::vector<std::filesystem::path> v_path);
        void Compile();
        void LinkTo(Program& pr);
        
    private:
        uint32_t m_randid;
    };
    
}
