#include <window.hpp>

#include <cstdlib>
#include <iostream>

namespace My {

    Window::Window(uint32_t x_size, uint32_t y_size, std::string_view name)
        : m_name(std::move(name)), m_x_size(x_size), m_y_size(y_size) {

        m_window = glfwCreateWindow(x_size, y_size, name.data(), nullptr, nullptr);
        
        if (m_window == nullptr) {
            glfwTerminate();
            
            std::cout << "FATAL: glfw window hasn't created well!" << std::endl;
            std::abort();
        }
        
        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(1);
    }

    Window::~Window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::SwapBuffers() {
        glfwSwapBuffers(m_window);
    }
    
    bool Window::CheckHealth() {
        return !glfwWindowShouldClose(m_window);
    }
    
}
