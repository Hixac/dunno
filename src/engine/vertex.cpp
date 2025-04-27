#include <engine/vertex.hpp>

namespace My {

    Vertex::Vertex(size_t size_of_array, void* ref_to_first_el, size_t stride, DrawingType type)
        : m_objinfo_stride(stride)
        , m_vertarr()
        , m_vertbuff() {
        
        m_vertarr.Bind();
        m_vertbuff.Bind(size_of_array, ref_to_first_el, type);
    }

    void Vertex::BindVertArr() {
        m_vertarr.Bind();
    }

    void Vertex::UnbindVertArr() {
        m_vertarr.Unbind();
    }
    
    void Vertex::AddAttribute(unsigned int size) {
        m_vertarr.AddAttribute(size, m_objinfo_stride);
    }
    
}
