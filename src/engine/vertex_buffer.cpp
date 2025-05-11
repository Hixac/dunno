#include <engine/vertex_buffer.hpp>

#include <glad/glad.h>

namespace My {

    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_randid);
    }

    void VertexBuffer::Bind(size_t byte_size_of_array, void* ref_to_first_el, DrawingType type) {
        glBindBuffer(GL_ARRAY_BUFFER, m_randid);
        glBufferData(GL_ARRAY_BUFFER, byte_size_of_array, ref_to_first_el, static_cast<unsigned int>(type));
    }
    
}
