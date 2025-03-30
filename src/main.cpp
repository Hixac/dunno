#include <imgui_presets.hpp>

#include <transforms/world_view.hpp>
#include <objects/cube.hpp>

#include <window.hpp>

int main(int argc, const char **argv) {

    My::Window window(1000, 1000, "Haro");

    OpenGl::init();

    Object::Cube cube;
    cube.SetTexture("res/me.jpg");
    
    View::view.Translate({0, 0, -30});

    cube.transform.Translate({0, 0, -5});
    
    while (window.CheckHealth()) {
        window.NewFrame();

        OpenGl::clear();
        
        cube.transform.Rotate(2, {0, 1, 1});

        cube.Render();
        window.Render();
        
        glfwPollEvents();
    }
	
    return 0;
}

