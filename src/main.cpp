#include <objects/cube.hpp>
#include <misc/camera.hpp>

#include <window.hpp>

int main(int argc, const char **argv) {

    My::Window window(2 * 640, 2 * 360, "Haro");
    OpenGl::init();

    Object::Cube cube;
    cube.SetTexture("res/me.jpg");
    cube.transform.Translate({0, 0, 0});

    while (window.CheckHealth()) {
        window.NewFrame();
        
        Misc::Camera::Logic();
        
        OpenGl::clear();

        cube.transform.Rotate(1, {0, 1, 1});
        cube.Render();

        window.Render();
    }
	
    return 0;
}

