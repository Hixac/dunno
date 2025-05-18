#include <engine/vertex_array.hpp>

#include <glad/glad.h>

namespace My {

    VertexArray::VertexArray() {
        glCreateVertexArrays(1, &m_randid);
    }

    VertexArray::~VertexArray() {
        glDeleteVertexArrays(1, &m_randid);
    }
    
    void VertexArray::Bind() const {
        glBindVertexArray(m_randid);
    }

    void VertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void VertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vbuff) {
        size_t sum_sizes = 0;
        unsigned char last_id = 0;

        Bind();
        vbuff->Bind();
        
        for (size_t size : vbuff->GetLayers()) {
            sum_sizes += size;
            
            glEnableVertexAttribArray(last_id);
            glVertexAttribPointer(
                last_id,
                size,
                GL_FLOAT,
                GL_FALSE,
                vbuff->GetStride() * sizeof(float),
                (void*)((sum_sizes - size) * sizeof(float)) 
                );

            last_id += 1;
        }

        m_vbuff = vbuff;
    }

    void VertexArray::SetElementBuffer(const std::shared_ptr<ElementBuffer>& ebuff) {
        Bind();
        ebuff->Bind();

        m_ebuff = ebuff;
    }
    
}
