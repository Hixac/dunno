#include <objects/collider.hpp>

namespace Object {

    ColliderOBB::ColliderOBB(vec3 aabb_min, vec3 aabb_max)
        : m_aabb_max(aabb_max), m_aabb_min(aabb_min)
    {}

    bool ColliderOBB::Intersect(const Ray& r) const {
        float tmin, tmax, tymin, tymax, tzmin, tzmax;
    
        tmin = (Bounds(r.sign[0]).x - r.origin.x) * r.inverted_direction.x;
        tmax = (Bounds(1-r.sign[0]).x - r.origin.x) * r.inverted_direction.x;
        tymin = (Bounds(r.sign[1]).y - r.origin.y) * r.inverted_direction.y;
        tymax = (Bounds(1-r.sign[1]).y - r.origin.y) * r.inverted_direction.y;
    
        if ((tmin > tymax) || (tymin > tmax))
            return false;

        if (tymin > tmin)
            tmin = tymin;
        if (tymax < tmax)
            tmax = tymax;
    
        tzmin = (Bounds(r.sign[2]).z - r.origin.z) * r.inverted_direction.z;
        tzmax = (Bounds(1-r.sign[2]).z - r.origin.z) * r.inverted_direction.z;
    
        if ((tmin > tzmax) || (tzmin > tmax))
            return false;

        if (tzmin > tmin)
            tmin = tzmin;
        if (tzmax < tmax)
            tmax = tzmax;

        return true;
    }
    
    vec3 ColliderOBB::Bounds(bool b) const {
        return b ? m_aabb_max : m_aabb_min;
    }
    
}
