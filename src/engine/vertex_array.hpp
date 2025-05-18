#pragma once

#include <engine/buffer.hpp>
#include <memory>

namespace My {

    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;

        void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vbuff);
        void SetElementBuffer(const std::shared_ptr<ElementBuffer>& ebuff);

    private:
        std::shared_ptr<VertexBuffer> m_vbuff;
        std::shared_ptr<ElementBuffer> m_ebuff;
        int m_last_id;
        unsigned int m_randid;
    };

    static auto create_vertex_array() {
        return std::make_shared<VertexArray>();
    }
    
}
