#include <objects/cube.hpp>
#include <misc/camera.hpp>

#include <window.hpp>
#include <misc/distributer.hpp>

int main(int argc, const char **argv) {

    My::Window window(2 * 640, 2 * 360, "Haro");
    OpenGl::init();

    Object::Cube cube;
    cube.transform.Translate({0, 0, -10});
    cube.transform.Scale({10, 10, 10});

    while (window.CheckHealth()) {
        Misc::Distributer::Get().CalculateFrameTime();
        window.NewFrame();
        
        bool spaced = My::Input("right") == My::Status::Press_Or_Repeat;
        window.EnableCursor(!spaced);
        if (spaced) {
            Misc::Camera::Logic();
        }

        vec2 win_size = window.GetSize();
        OpenGl::adapt_viewport(win_size.x, win_size.y);
        OpenGl::clear();

        Object::Ray ray = Misc::Camera::GetRay();
        OpenGl::draw_ray(ray, 100.f);
        //std::cout << cube.Collision(ray) << " is rayed\n";
        
        //cube.transform.Rotate(1, {0, 1, 1});
        cube.Render();

        window.Render();
    }
	
    return 0;
}

