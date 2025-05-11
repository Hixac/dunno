#pragma once

#include <engine/vertex_buffer.hpp>

namespace My {

    class ElementBuffer {
    public:
        ElementBuffer();

        void Bind(size_t byte_size_of_array, void* ref_to_first_el, DrawingType type);
        
    private:
        unsigned int m_randid;
    };
    
}
