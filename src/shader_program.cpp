#include <shader_program.hpp>

#include <glad/glad.h>

namespace My {

    Program::Program() {
        m_randid = glCreateProgram();
    }

    Program::~Program() {
        glDeleteProgram(m_randid);
    }

    void Program::Attach(uint32_t shader_id) {
        glAttachShader(m_randid, shader_id);
    }

    void Program::LinkAll() {
        glLinkProgram(m_randid);
    }

    void Program::Use() {
        glUseProgram(m_randid);
    }
}
