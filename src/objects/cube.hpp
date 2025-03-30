#pragma once

#include <engine.hpp>

#include <transforms/transform.hpp>
#include <filesystem>

namespace Object {

    class Cube {
    public:
        Cube();

        void Render();
        void SetTexture(std::filesystem::path filepath);
        
        Transform transform;

    private:
        My::Program m_prog;
        My::Texture m_tex;
        My::Vertex m_vert;
    };
    
}
