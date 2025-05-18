#include <window.hpp>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <cstdlib>
#include <iostream>

namespace My {

    static void _window_size_callback(GLFWwindow* win, int w, int h) {
        glfwSetWindowSize(win, w, h);
    }
    
    Window::Window(uint32_t x_size, uint32_t y_size, const std::string& name)
        : m_name(name) {
        
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
        
        glfwSetMouseButtonCallback(m_window, Misc::_mouse_callback);
        glfwSetCursorPosCallback(m_window, Misc::_cursor_callback);
        glfwSetKeyCallback(m_window, Misc::_key_callback);
        glfwSetWindowSizeCallback(m_window, _window_size_callback);
        
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

    vec2 Window::GetSize() {
        int w, h;
        glfwGetWindowSize(m_window, &w, &h);
        
        return {w, h};
    }
    
    void Window::Render() {
        ImGui::Render();
	    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwPollEvents();
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

    void Window::EnableCursor(bool b) {
        if (!b) {
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            return;
        }
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    
    bool Window::CheckHealth() {
        return !glfwWindowShouldClose(m_window);
    }

}
