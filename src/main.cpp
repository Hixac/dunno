#include <objects/cube.hpp>
#include <misc/camera.hpp>

#include <window.hpp>
#include <misc/distributer.hpp>

int main(int argc, const char **argv) {

    My::Window window(2 * 640, 2 * 360, "Haro");
    OpenGl::init();

    Object::Cube cube;
    cube.SetTexture("res/me.jpg");
    cube.transform.Translate({0, 0, 0});
    cube.transform.Scale({10, 10, 10});
    
    while (window.CheckHealth()) {
        Misc::Distributer::Get().CalculateFrameTime();
        window.NewFrame();
        
        bool spaced = My::Input("left") == My::Status::Press_Or_Repeat;
        window.EnableCursor(!spaced);
        if (spaced) {
            Misc::Camera::Logic();
        }
        
        OpenGl::clear();

        cube.transform.Rotate(1, {0, 1, 1});
        cube.Render();

        window.Render();
    }
	
    return 0;
}

