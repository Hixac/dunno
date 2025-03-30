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

        void Bind(const std::vector<float>& v_f, DrawingType type);
        
    private:
        unsigned int m_randid;
    };
    
}
