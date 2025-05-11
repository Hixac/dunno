#include <objects/mesh.hpp>

namespace Object {
    
    Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, std::vector<My::Texture>& textures)
        : m_vert(vertices.size() * sizeof(Vertex),
                 &vertices[0],
                 indices.size() * sizeof(unsigned int),
                 &indices[0], 8,
                 My::DrawingType::STATIC_DRAW) {
        m_vertices = vertices;
        m_indices = indices;
        m_textures = textures;

        m_vert.BindVertArr();
        
        SetupMesh();
    }

    void Mesh::SetupMesh() {
        m_vert.AddAttribute(3);
        m_vert.AddAttribute(3);
        m_vert.AddAttribute(2);

        m_vert.UnbindVertArr();
    }
    
    void Mesh::Draw(My::Program& shader_program) {
        for (size_t i = 0; i < m_textures.size(); ++i) {
            m_textures[i].Bind();
        }

        m_vert.BindVertArr();
        OpenGl::draw_elems(m_indices.size());
        m_vert.UnbindVertArr();
    }
    
}
