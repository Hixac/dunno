#include <engine/vertex.hpp>

namespace My {

    Vertex::Vertex(size_t byte_size_of_array, void* ref_to_first_el, size_t stride, DrawingType type)
        : m_objinfo_stride(stride)
        , m_vertarr()
        , m_vertbuff()
        , m_elembuff() {
        
        m_vertarr.Bind();
        m_vertbuff.Bind(byte_size_of_array, ref_to_first_el, type);
    }

    Vertex::Vertex(size_t byte_size_of_array, void* ref_to_first_el, size_t byte_size_of_indices, void* ref_to_first_ind, size_t stride, DrawingType type)
        : m_objinfo_stride(stride)
        , m_vertarr()
        , m_vertbuff()
        , m_elembuff() {

        m_vertarr.Bind();
        m_vertbuff.Bind(byte_size_of_array, ref_to_first_el, type);
        m_elembuff.Bind(byte_size_of_indices, ref_to_first_ind, type);
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
