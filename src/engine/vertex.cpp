#include <vertex.hpp>

namespace My {

    Vertex::Vertex(const std::vector<float>& obj_info, size_t stride, DrawingType type)
        : m_objinfo_stride(stride)
        , m_vertarr()
        , m_vertbuff() {
        
        m_vertarr.Bind();
        m_vertbuff.Bind(obj_info, type);
    }

    void Vertex::BindVertArr() {
        m_vertarr.Bind();
    }
        
    void Vertex::AddAttribute(unsigned int size) {
        m_vertarr.AddAttribute(size, m_objinfo_stride);
    }
    
}
