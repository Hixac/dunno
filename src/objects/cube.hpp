#pragma once

#include <engine.hpp>

#include <transforms/primitives.hpp>
#include <transforms/transform.hpp>
#include <objects/collider.hpp>
#include <objects/mesh.hpp>

namespace Object {

    class Cube : Collideable {
    public:
        Cube();

        void Render();
        bool Collision(const Ray& ray) const override;
        
        Transform transform;
    private:
        ColliderOBB m_collider;
        
        My::Program m_prog;
        std::vector<Mesh> m_meshes;
    };
    
}
