#include <misc/camera.hpp>

#include <iostream>

namespace Misc {

    void Camera::Logic() {
        vec2 offset = {Input::Get().mouse_pos.x - last.x, last.y - Input::Get().mouse_pos.y};
        last = Input::Get().mouse_pos;
        std::cout << last.x << ' ' << last.y << '\n';
        offset *= sensitivity;

        yaw += offset.x;
        pitch += offset.y;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
            
        dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        dir.y = sin(glm::radians(pitch));
        dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(dir);
            
        speed = speed_coef * Distributer::Get().DeltaTime();
            
        if (My::Input("w") == My::Status::Press_Or_Repeat) {
            pos += speed * front;
        }

        if (My::Input("s") == My::Status::Press_Or_Repeat) {
            pos -= speed * front;
        }
        if (My::Input("d") == My::Status::Press_Or_Repeat) {
            pos += Object::normalize(Object::cross(front, up)) * speed;
        }
        if (My::Input("a") == My::Status::Press_Or_Repeat) {
            pos -= Object::normalize(Object::cross(front, up)) * speed;
        }

        View::Get().view.Reset();
        View::Get().view.LookAt(pos, pos + front, up);
    }
    
}
