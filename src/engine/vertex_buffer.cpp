#include <vertex_buffer.hpp>

#include <glad/glad.h>

namespace My {

    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_randid);
    }

    void VertexBuffer::Bind(const std::vector<float>& v_f, DrawingType type) {
        glBindBuffer(GL_ARRAY_BUFFER, m_randid);
        glBufferData(GL_ARRAY_BUFFER, v_f.size() * sizeof(float), &v_f[0], static_cast<unsigned int>(type));
    }
    
}
