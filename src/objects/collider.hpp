#pragma once

#include <transforms/ray.hpp>

namespace Object {

    class Collideable {
    public:
        virtual ~Collideable() = default;

        virtual bool Collision(const Ray& ray) const = 0;
        
    protected:
        Collideable() = default;
    };
    
    class ColliderOBB {
    public:
        ColliderOBB() = default;
        ColliderOBB(vec3 aabb_min, vec3 aabb_max);
        ~ColliderOBB() = default;

        bool Intersect(const Ray& ray) const;

        void SetAABB(vec3 min, vec3 max) { m_aabb_min = min; m_aabb_max = max; }
        
    private:
        vec3 Bounds(bool) const;
        
        vec3 m_aabb_min, m_aabb_max;
    };
    
}
