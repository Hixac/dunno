#pragma once

#include <transforms/transform.hpp>
#include <engine.hpp>

namespace Object {
    
    class Mesh {
    public:
        Mesh(std::vector<float>& vertices,
             std::vector<size_t>& indices,
             std::vector<My::Texture>& textures);

        void Draw(My::Program& shader_program);
    private:
        
        std::shared_ptr<My::VertexArray> m_varr;
        
        std::vector<float>        m_vertices;
        std::vector<size_t>       m_indices;
        std::vector<My::Texture>  m_textures;
    };

}
