#pragma once

#include <window.hpp>
#include <transforms/world_view.hpp>

#include <misc/input_listener.hpp>
#include <misc/distributer.hpp>

namespace Misc {

    struct Camera {
        inline static void Logic() {
            vec2 offset = {Mouse::Get().pos.x - last.x, last.y - Mouse::Get().pos.y};
            last = Mouse::Get().pos;
            offset *= sensitivity;

            yaw += offset.x;
            pitch += offset.y;

            if(pitch > 89.0f)
                pitch = 89.0f;
            if(pitch < -89.0f)
                pitch = -89.0f;
            
            dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            dir.y = sin(glm::radians(pitch));
            dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            front = glm::normalize(dir);
            
            speed = speed_coef * Distributer::Get().DeltaTime();
            
            if (My::Keys("w") == My::Status::Press_Or_Release) {
                pos += speed * front;
            }
            if (My::Keys("s") == My::Status::Press_Or_Release) {
                pos -= speed * front;
            }
            if (My::Keys("d") == My::Status::Press_Or_Release) {
                pos += Object::normalize(Object::cross(front, up)) * speed;
            }
            if (My::Keys("a") == My::Status::Press_Or_Release) {
                pos -= Object::normalize(Object::cross(front, up)) * speed;
            }

            View::Get().view.Reset();
            View::Get().view.LookAt(pos, pos + front, up);
        }
        
    private:
        static inline float yaw = 0;
        static inline float pitch = 0;
        static inline vec2 last = Mouse::Get().pos;
        static inline const float sensitivity = 0.1f;
        static inline const float speed_coef = 2.5f;
        static inline float speed = .5f;
        static inline vec3 dir = {0, 0, 0};
        static inline vec3 up = {0, 1, 0};
        static inline vec3 front = {0, 0, -1};
        static inline vec3 pos = {0, 0, 0};
    };
    
}
