#include <engine/buffer.hpp>

#include <glad/glad.h>

namespace My {

    VertexBuffer::VertexBuffer(size_t size)
        : m_layers(), m_size(size) {
        glCreateBuffers(1, &m_randid);
        glBindBuffer(GL_ARRAY_BUFFER, m_randid);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    VertexBuffer::VertexBuffer(size_t size, float *data)
    : m_layers(), m_size(size) {
        glCreateBuffers(1, &m_randid);
        glBindBuffer(GL_ARRAY_BUFFER, m_randid);
        glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &m_randid);
    }
    
    size_t VertexBuffer::GetStride() const {
        size_t s = 0;
        for (auto el : m_layers) {
            s += el;
        }
        return s;
    }
    
    void VertexBuffer::SetData(size_t size, float *data) {
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
        m_size = size;
    }
    
    void VertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_randid);
    }

    void VertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    ElementBuffer::ElementBuffer(size_t count, size_t *indices)
        : m_count(count) {
        glCreateBuffers(1, &m_randid);
        glBindBuffer(GL_ARRAY_BUFFER, m_randid);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(size_t), indices, GL_STATIC_DRAW);
    }

    ElementBuffer::~ElementBuffer() {
        glDeleteBuffers(1, &m_randid);
    }
    
    void ElementBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_randid);
    }
    
    void ElementBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
