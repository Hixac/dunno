#include <shader.hpp>
#include <window.hpp>

#include <iostream>

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, const char **argv) {

    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit()) {
        return 1;
    }
    
    My::Window window(400, 400, "Haro");
    
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
		return -1;
    }
        
    My::Program prog;
    {    
        My::Shader vert(My::ShaderType::VERTEX);
        vert.Source({std::filesystem::current_path().generic_string() + "/res/triangle.vert"});
        vert.Compile();
        vert.LinkTo(prog);
        
        My::Shader frag(My::ShaderType::FRAGMENT);
        frag.Source({std::filesystem::current_path().generic_string() + "/res/triangle.frag"});
        frag.Compile();
        frag.LinkTo(prog);
    }
    prog.LinkAll();

    float vertices[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };  

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);
    
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    
    while (window.CheckHealth()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        prog.Use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        window.SwapBuffers();
        glfwWaitEvents();
    }
	
    return 0;
}
