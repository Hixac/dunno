#include <objects/line.hpp>

#include <transforms/world_view.hpp>

namespace Object {

    Line::Line(vec3 start, vec3 end, vec3 col)
        : m_start(start), m_end(end), transform(1.f) {
        m_varr = My::create_vertex_array();
        m_prog = My::create_shader_program();
        
        m_prog->Source({"res/line.vert"}, {"res/line.frag"});
        m_prog->LinkAll();
        
        std::vector<float> vertices = {
            start.x, start.y, start.z, col.x, col.y, col.z,
            end.x, end.y, end.z, col.x, col.y, col.z,
        };
        
        auto vbuff = My::create_vertex_buffer(vertices.size(), &vertices[0]);
        vbuff->AddLayer(3);
        vbuff->AddLayer(3);
        
        m_varr->SetVertexBuffer(vbuff);
    }

    void Line::Draw() {
        m_prog->SetVarMat4("model", transform.Get());
        m_prog->SetVarMat4("view", View::Get().view.Get());
        m_prog->SetVarMat4("projection", View::Get().proj.Get());
        
        m_prog->Use();
        m_varr->Bind();
        OpenGl::draw_lines(2);
        m_varr->Unbind();
    }
    
}
