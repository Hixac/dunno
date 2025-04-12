#pragma once

#include <window.hpp>
#include <transforms/world_view.hpp>

namespace Misc {

    struct Camera {
        static void Logic() {
            if (My::Keys("w") == My::Key_Status::Press_Or_Release) {
                camera_pos.y += 0.1f;
            }
            if (My::Keys("s") == My::Key_Status::Press_Or_Release) {
                camera_pos.y -= 0.1f;
            }
            if (My::Keys("d") == My::Key_Status::Press_Or_Release) {
                camera_pos.x += 0.1f;
            }
            if (My::Keys("a") == My::Key_Status::Press_Or_Release) {
                camera_pos.x -= 0.1f;
            }
            if (My::Keys("q") == My::Key_Status::Press_Or_Release) {
                camera_pos.z += 0.1f;
            }
            if (My::Keys("e") == My::Key_Status::Press_Or_Release) {
                camera_pos.z -= 0.1f;
            }
            
            View::Get().view.Reset();
            View::Get().view.Translate(camera_pos.AsGlmVec());
        }
        
        static inline Object::Vector camera_pos = Object::Vector(0, 0, 0);
    };
    
}
