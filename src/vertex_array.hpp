#pragma once

#include <vector>

namespace My {

    class VertexArray {
    public:
        VertexArray();
        ~VertexArray() = default;

        void Bind();

    private:
        unsigned int m_randid;
    };
    
}
