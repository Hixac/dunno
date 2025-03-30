#include <window.hpp>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <cstdlib>
#include <iostream>

namespace My {

    Window::Window(uint32_t x_size, uint32_t y_size, std::string_view name)
        : m_name(std::move(name)), m_x_size(x_size), m_y_size(y_size) {

        glfwSetErrorCallback([](int error, const char* description) {
            fprintf(stderr, "Error: %s\n", description);
        });
        
        if (!glfwInit()) {
            std::cout << "FATAL: glfw hasn't initialized well!" << std::endl;
            std::abort();
        }
        
        m_window = glfwCreateWindow(x_size, y_size, m_name.data(), nullptr, nullptr);
        
        if (m_window == nullptr) {
            glfwTerminate();
            
            std::cout << "FATAL: glfw window hasn't created well!" << std::endl;
            std::abort();
        }
        
        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(1);
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(m_window, true);
        ImGui_ImplOpenGL3_Init(nullptr);
    }

    Window::~Window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    
    void Window::Render() {
        ImGui::Render();
	    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Window::NewFrame() {
        SwapBuffers();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
    
    void Window::SwapBuffers() {
        glfwSwapBuffers(m_window);
    }
    
    bool Window::CheckHealth() {
        return !glfwWindowShouldClose(m_window);
    }
    
}
