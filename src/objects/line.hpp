#pragma once

#include <engine.hpp>
#include <transforms/transform.hpp>

namespace Object {

    class Line {
    public:
        Line() = delete;
        Line(vec3 start, vec3 end, vec3 col);
        ~Line() = default;

        void Draw();

        Transform transform;
        
    private:
        std::shared_ptr<My::VertexArray> m_varr;
        std::shared_ptr<My::Program> m_prog;
        
        vec3 m_start, m_end;
    };
    
}
