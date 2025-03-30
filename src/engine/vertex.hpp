#pragma once

#include <vector>
#include <engine/vertex_array.hpp>
#include <engine/vertex_buffer.hpp>

namespace My {

    class Vertex {
    public:
        Vertex(const std::vector<float>& obj_info, size_t stride, DrawingType type);

        void BindVertArr();
        
        void AddAttribute(unsigned int size);

    private:
        unsigned int m_objinfo_stride;
        
        VertexArray m_vertarr;
        VertexBuffer m_vertbuff;
    };
    
}
