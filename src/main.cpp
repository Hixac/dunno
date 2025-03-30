#include <imgui_presets.hpp>

#include <transforms/world_view.hpp>
#include <objects/cube.hpp>

#include <window.hpp>

int main(int argc, const char **argv) {

    My::Window window(640, 360, "Haro");

    OpenGl::init();

    Object::Cube cube;
    
    cube.SetTexture("res/me.jpg");

    cube.transform.Translate({0, 0, -2});
    
    View::Get().view.Translate({0, 0, -2});

    while (window.CheckHealth()) {
        window.NewFrame();

        OpenGl::clear();

        cube.transform.Rotate(1, {0, 1, 1});
        cube.Render();

        window.Render();
        
        glfwPollEvents();
    }
	
    return 0;
}

