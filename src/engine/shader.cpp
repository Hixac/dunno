
#include <shader.hpp>

#include <fstream>
#include <iostream>
#include <string.h>

namespace My {

    Shader::Shader(ShaderType type) {       
        m_randid = glCreateShader(static_cast<uint32_t>(type));
    }

    Shader::~Shader() {
        glDeleteShader(m_randid);
    }

    void Shader::Source(const std::vector<std::filesystem::path> v_path) {
        std::vector<char*> v_s;
        
        for (auto p : v_path) {
            std::ifstream file_shader(p);
            if (!file_shader.is_open()) {
                std::cerr << "FATAL: no file named " << p << " has been found" << std::endl;
                std::abort();
            }
            
            std::stringstream ss; ss << file_shader.rdbuf();
            v_s.emplace_back(strdup(ss.str().c_str()));

            file_shader.close();
        }
        
        glShaderSource(m_randid, v_path.size(), &v_s[0], 0);

        for (size_t i = 0; i < v_s.size(); ++i) {
            free(v_s[i]);
        }
    }
    
    void Shader::Compile() {
        glCompileShader(m_randid);
        
        int success; char infoLog[512];
        glGetShaderiv(m_randid, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(m_randid, 512, NULL, infoLog);
            std::cerr << "FATAL: shader error log: " << infoLog << std::endl;
            std::abort();
        }
    }

    void Shader::LinkTo(Program &pr) {
        pr.Attach(m_randid);
    }
    
}
