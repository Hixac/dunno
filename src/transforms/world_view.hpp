#pragma once

#include <transforms/transform.hpp>

namespace View {

    static Object::Transform ortho = Object::Transform(1.f)
        .Ortho(0, 1000, 0, 1000, 0.1f, 100.f);
    
    static Object::Transform proj  = Object::Transform(1.f)
        .Perspective(45.0f, 0.5f, 0.1f, 100.0f);
    
    static Object::Transform view  = Object::Transform(1.0f);
    
}
