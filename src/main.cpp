#include <shader.hpp>
#include <window.hpp>

#include <vertex_array.hpp>
#include <vertex_buffer.hpp>

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
    
    My::Window window(1000, 1000, "Haro");
    
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

    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,  // 0
         0.5f, -0.5f, 0.0f,  // 1
         0.5f,  0.5f, 0.0f,  // 2
        -0.5f,  0.5f, 0.0f   // 3
    };  

    unsigned int indices[] = {
        3, 0, 1, // first triangle
        1, 2, 3  // second triangle
    };
    
    My::VertexArray vertarr;
    vertarr.Bind();
    
    My::VertexBuffer vertbuff;
    vertbuff.Bind(vertices, My::DrawingType::STATIC_DRAW);
    
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, (void*)0);
    glEnableVertexAttribArray(0);

    while (window.CheckHealth()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        prog.Use();
        vertarr.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        window.SwapBuffers();
        glfwWaitEvents();
    }
	
    return 0;
}
