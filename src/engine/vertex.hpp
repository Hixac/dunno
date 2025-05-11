#pragma once

#include <engine/vertex_array.hpp>
#include <engine/vertex_buffer.hpp>
#include <engine/element_buffer.hpp>

namespace My {

    class Vertex {
    public:
        Vertex(size_t byte_size_of_array, void* ref_to_first_el, size_t stride, DrawingType type);
        Vertex(size_t byte_size_of_array, void* ref_to_first_el, size_t byte_size_of_indices, void* ref_to_first_ind, size_t stride, DrawingType type);
        
        void BindVertArr();
        void UnbindVertArr();
            
        void AddAttribute(unsigned int size);

    private:
        unsigned int m_objinfo_stride;

        ElementBuffer m_elembuff;
        VertexArray m_vertarr;
        VertexBuffer m_vertbuff;
    };
    
}
