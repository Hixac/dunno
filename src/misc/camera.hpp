#pragma once

#include <window.hpp>
#include <transforms/world_view.hpp>

#include <misc/input_listener.hpp>
#include <misc/distributer.hpp>

namespace Misc {

    struct Camera {
        static void Logic();
        
    private:
        static inline float yaw = 0;
        static inline float pitch = 0;
        static inline vec2 last = Input::Get().mouse_pos;
        static inline const float sensitivity = 0.1f;
        static inline const float speed_coef = 2.5f;
        static inline float speed = .5f;
        static inline vec3 dir = {0, 0, 0};
        static inline vec3 up = {0, 1, 0};
        static inline vec3 front = {0, 0, -1};
        static inline vec3 pos = {0, 0, 0};
    };
    
}
