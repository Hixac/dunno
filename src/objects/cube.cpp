#include <objects/cube.hpp>

#include <transforms/primitives.hpp>
#include <transforms/world_view.hpp>

namespace Object {

    Cube::Cube()
        : m_vert(Primitive::cube_vertices, 5, My::DrawingType::STATIC_DRAW),
          m_tex(), m_prog(), transform(1.f) {

        {    
            My::Shader vert(My::ShaderType::VERTEX);
            vert.Source({std::filesystem::current_path().generic_string() + "/res/default.vert"});
            vert.Compile();
            vert.LinkTo(m_prog);

            My::Shader frag(My::ShaderType::FRAGMENT);
            frag.Source({std::filesystem::current_path().generic_string() + "/res/default.frag"});
            frag.Compile();
            frag.LinkTo(m_prog);
        }
        m_prog.LinkAll();
        
        m_vert.AddAttribute(3);
        m_vert.AddAttribute(2);
    }

    void Cube::Render() {
        m_prog.Use();
        m_prog.SetVarMat4("transform", (View::Get().proj * View::Get().view * transform).Get());
        
        m_tex.Bind();
        
        m_vert.BindVertArr();

        OpenGl::draw_cube();
    }
    
    void Cube::SetTexture(std::filesystem::path filepath) {
        m_tex.Load(filepath.string());
    }
    
}
