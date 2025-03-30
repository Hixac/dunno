#pragma once

namespace My {

    class VertexArray {
    public:
        VertexArray();
        ~VertexArray() = default;

        void Bind();

        void AddAttribute(unsigned int size, unsigned int stride);

    private:
        int m_last_id;
        unsigned int m_sum_sizes;
        unsigned int m_randid;
    };
    
}
