#pragma once

#include <vector>

namespace My {

    enum class DrawingType : unsigned int {
        STATIC_DRAW = 0x88E4,
        DYNAMIC_DRAW = 0x88E8,
        STREAM_DRAW = 0x88E0
    };
    
    class VertexBuffer {
    public:
        VertexBuffer();
        ~VertexBuffer() = default;

        void Bind(size_t size_of_array, void* ref_to_first_el, DrawingType type);
        
    private:
        unsigned int m_randid;
    };
    
}
