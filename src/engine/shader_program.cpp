#include <engine/shader_program.hpp>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

#include <engine/shader.hpp>

#include <iostream>

namespace My {

    Program::Program()
        : m_vars() {
        m_randid = glCreateProgram();
    }

    Program::~Program() {
        glDeleteProgram(m_randid);
    }

    void Program::Source(std::vector<std::filesystem::path> vert_path, std::vector<std::filesystem::path> frag_path) {
        My::Shader vert(My::ShaderType::VERTEX);
        vert.Source(vert_path);
        vert.Compile();
        vert.LinkTo(*this);

        My::Shader frag(My::ShaderType::FRAGMENT);
        frag.Source(frag_path);
        frag.Compile();
        frag.LinkTo(*this);
    }
    
    void Program::Attach(uint32_t shader_id) {
        glAttachShader(m_randid, shader_id);
    }

    void Program::LinkAll() {
        glLinkProgram(m_randid);

        GLint success;
        glGetProgramiv(m_randid, GL_LINK_STATUS, &success);
        if (!success) {
            char log[512];
            glGetProgramInfoLog(m_randid, 512, nullptr, log);
            std::cerr << "FATAL: link program error log: " << log << std::endl;
        }
    }

    void Program::Use() const {
        glUseProgram(m_randid);
    }
    
    void Program::DetectVarLocation(std::string_view name) {
        if (m_vars.contains(name.data())) {
            return;
        }

        int ret = glGetUniformLocation(m_randid, name.data());
        if (ret == -1) {
            std::cerr << "FATAL: var doesn't exist or it is 'gl_' prefixed!" << std::endl;
            std::abort();
        }
        
        m_vars.emplace(name, ret);
    }
    
    void Program::SetVarFloat(const std::string& v, float f) {
        Use();
        DetectVarLocation(v.data());
        
        glUniform1f(m_vars[v], f);
    }

    void Program::SetVarMat4(const std::string& v, const glm::mat4& m) {
        Use();
        DetectVarLocation(v.data());

        glUniformMatrix4fv(m_vars[v], 1, GL_FALSE, glm::value_ptr(m));
    }
    
    void Program::SetVarInt(const std::string& v, int i) {
        Use();
        DetectVarLocation(v.data());

        glUniform1i(m_vars[v], i);
    }
}
