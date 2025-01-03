#include <vertex_array.hpp>

#include <glad/glad.h>

namespace My {

    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_randid);
    }

    void VertexArray::Bind() {
        glBindVertexArray(m_randid);
    }
    
}
