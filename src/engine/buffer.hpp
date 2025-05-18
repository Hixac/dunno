#pragma once

#include <cstddef>
#include <vector>

#include <memory>

namespace My {
    
    class VertexBuffer {
    public:
        VertexBuffer(size_t size);
        VertexBuffer(size_t size, float *data);
        ~VertexBuffer();

        void SetData(size_t size, float *data);
        
        void Bind() const;
        void Unbind() const;

        size_t GetStride() const;
        inline void AddLayer(size_t size) { m_layers.push_back(size); }
        inline auto GetLayers() const { return m_layers; }
        
        inline unsigned int Size() const { return m_size; }
        
    private:
        std::vector<size_t> m_layers;
        size_t m_size;
        unsigned int m_randid;
    };

    class ElementBuffer {
    public:
        ElementBuffer(size_t count, size_t *indices);
        ~ElementBuffer();

        void Bind() const;
        void Unbind() const;

        inline size_t Count() const { return m_count; }
        
    private:
        size_t m_count;
        unsigned int m_randid;
    };

    static auto create_vertex_buffer(size_t size, float *data) {
        return std::make_shared<VertexBuffer>(size, data);
    }

    static auto create_element_buffer(size_t size, size_t *indices) {
        return std::make_shared<ElementBuffer>(size, indices);
    }
}
