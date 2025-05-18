#include <objects/mesh.hpp>

namespace Object {

    Mesh::Mesh(std::vector<float>& vertices) {
        m_varr = My::create_vertex_array();
        
        m_vertices = vertices;
        auto vbuff = My::create_vertex_buffer(vertices.size(), &vertices[0]);
        vbuff->AddLayer(3);
        vbuff->AddLayer(3);
        vbuff->AddLayer(2);

        m_varr->SetVertexBuffer(vbuff);
    }
    
    Mesh::Mesh(std::vector<float>& vertices, std::vector<size_t>& indices, std::vector<My::Texture>& textures) {
        m_varr = My::create_vertex_array();
        
        m_vertices = vertices;
        m_indices  = indices;
        m_textures = textures;
        
        auto vbuff = My::create_vertex_buffer(vertices.size(), &vertices[0]);
        vbuff->AddLayer(3);
        vbuff->AddLayer(3);
        vbuff->AddLayer(2);

        auto ebuff = My::create_element_buffer(indices.size(), &indices[0]);

        m_varr->SetVertexBuffer(vbuff);
        m_varr->SetElementBuffer(ebuff);
    }
    
    void Mesh::Draw(My::Program& shader_program) {
        for (size_t i = 0; i < m_textures.size(); ++i) {
            m_textures[i].Bind();
        }

        shader_program.Use();
        m_varr->Bind();
        OpenGl::draw_vertices(6);
        m_varr->Unbind();
    }
    
}
