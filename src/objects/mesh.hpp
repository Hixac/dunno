#pragma once

#include <transforms/transform.hpp>
#include <engine.hpp>

namespace Object {
    
    struct Vertex {
        vec3 position;
        vec3 normal;
        vec2 tex_coords;
    };
    
    class Mesh {
    public:
        Mesh(std::vector<Vertex>& vertices,
             std::vector<unsigned int>& indices,
             std::vector<My::Texture>& textures);

        void Draw(My::Program& shader_program);
    private:
        void SetupMesh();
        
        My::Vertex m_vert;
        
        std::vector<Vertex>       m_vertices;
        std::vector<unsigned int> m_indices;
        std::vector<My::Texture>  m_textures;
    };

}
