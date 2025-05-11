#pragma once

#include <engine.hpp>

#include <transforms/primitives.hpp>
#include <transforms/transform.hpp>
#include <objects/mesh.hpp>

namespace Object {

    class Cube {
    public:
        Cube();

        void Render();
        
        Transform transform;
    private:
        My::Program m_prog;
        std::vector<Mesh> m_meshes;
    };
    
}
