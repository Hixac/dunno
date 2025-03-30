#pragma once

#include <transforms/transform.hpp>

class View {
public:
    inline static View& Get() {
        static View v;

        return v;
    }

    Object::Transform ortho = Object::Transform(1.f)
        .Ortho(0, 1000, 0, 1000, 0.1f, 100.f);
    
    Object::Transform proj  = Object::Transform(1.f)
        .Perspective(90.0f,1.77778f, 0.1f, 100.0f);
    
    Object::Transform view  = Object::Transform(1.0f);
    
private:
    View() = default;
};  
    
    
    
