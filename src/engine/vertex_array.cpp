#include <engine/vertex_array.hpp>

#include <iostream>

#include <glad/glad.h>

namespace My {

    VertexArray::VertexArray()
        : m_last_id(0)
        , m_sum_sizes(0) {
        glGenVertexArrays(1, &m_randid);
    }

    void VertexArray::Bind() {
        glBindVertexArray(m_randid);
    }

    void VertexArray::Unbind() {
        glBindVertexArray(0);
    }
    
    void VertexArray::AddAttribute(unsigned int size, unsigned int stride) {
        m_sum_sizes += size;

        if (m_sum_sizes > stride) {
            std::cerr << "FATAL: sum of all size added in attributes is more than stride!" << std::endl;
            std::abort();
        }
        
        glVertexAttribPointer(
            m_last_id,
            size,
            GL_FLOAT,
            GL_FALSE,
            stride * sizeof(float),
            (void*)((m_sum_sizes - size) * sizeof(float)) 
            );
        glEnableVertexAttribArray(m_last_id);

        m_last_id += 1;
    }
    
}
