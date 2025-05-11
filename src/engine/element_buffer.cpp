#include <engine/element_buffer.hpp>

#include <glad/glad.h>

namespace My {

    ElementBuffer::ElementBuffer() {
        glGenBuffers(1, &m_randid);
    }

    void ElementBuffer::Bind(size_t byte_size_of_array, void* ref_to_first_el, DrawingType type) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_randid);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, byte_size_of_array, ref_to_first_el, static_cast<unsigned int>(type));
    }

}
