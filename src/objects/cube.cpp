#include <objects/cube.hpp>

#include <transforms/world_view.hpp>

namespace Object {

    Cube::Cube()
        : transform(1.f)
        , m_prog() {

        My::Texture tex;
        tex.Load("res/me.jpg");
        std::vector<My::Texture> texes = {tex};
        
        m_meshes.emplace_back(
            Primitive::quad_vertices,
            Primitive::cube_indices,
            texes
            );
        
        m_prog.Source({"res/default.vert"}, {"res/default.frag"});
        m_prog.LinkAll();
    }

    void Cube::Render() {
        m_prog.SetVarMat4("model", transform.Get());
        m_prog.SetVarMat4("view", View::Get().view.Get());
        m_prog.SetVarMat4("projection", View::Get().proj.Get());

        for (auto& mesh : m_meshes) {
            mesh.Draw(m_prog);
        }
    }
    
}
