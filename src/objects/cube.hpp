#pragma once

#include <engine.hpp>

#include <transforms/transform.hpp>
#include <objects/mesh.hpp>

namespace Object {

    class Cube {
    public:
        Cube();

        void Render();
        
        Transform transform;
    private:
        std::vector<Mesh> m_meshes;
    };
    
}
