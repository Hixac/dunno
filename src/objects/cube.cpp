#include <objects/cube.hpp>

#include <transforms/world_view.hpp>

namespace Object {

    Cube::Cube()
        : transform(1.f)
        , m_prog() {

        My::Texture tex;
        tex.Load("res/me.jpg");
        std::vector<My::Texture> texes;
        
        m_meshes.emplace_back(
            Primitive::cube_vertices_minus_z,
            Primitive::cube_indices_minus_z,
            texes
            );

        m_meshes.emplace_back(
            Primitive::cube_vertices_plus_z,
            Primitive::cube_indices_plus_z,
            texes
            );

        m_meshes.emplace_back(
            Primitive::cube_vertices_minus_x,
            Primitive::cube_indices_minus_x,
            texes
            );

        m_meshes.emplace_back(
            Primitive::cube_vertices_plus_x,
            Primitive::cube_indices_plus_x,
            texes
            );

        m_meshes.emplace_back(
            Primitive::cube_vertices_minus_y,
            Primitive::cube_indices_minus_y,
            texes
            );

        m_meshes.emplace_back(
            Primitive::cube_vertices_plus_y,
            Primitive::cube_indices_plus_y,
            texes
            );
        
        m_prog.Source({"res/default.vert"}, {"res/default.frag"});
        m_prog.LinkAll();
    }

    void Cube::Render() {
        m_prog.Use();
        m_prog.SetVarMat4("model", transform.Get());
        m_prog.SetVarMat4("view", View::Get().view.Get());
        m_prog.SetVarMat4("projection", View::Get().proj.Get());

        for (auto& mesh : m_meshes) {
            mesh.Draw(m_prog);
        }
    }
    
}
