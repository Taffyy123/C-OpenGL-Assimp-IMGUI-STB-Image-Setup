//BS COORDS -312.8, 977,9, -1969.0
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>




#include <headers/quick_functions.hpp>

GLFWwindow* window;
const unsigned int window_width = 1080, window_height = 720;


#include <headers/image.hpp>
#include <headers/shader.hpp>
#include <headers/processes.hpp>
#include <headers/render.hpp>

int main() 
{
    //Initialising OpenGL
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, true);
    window = glfwCreateWindow(window_width, window_height, "Taffy\'s Client", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGL();


    //Initialising IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); //(void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while(!glfwWindowShouldClose(window)) 
    {
        input();
        draw_gui();
        update_window(window);
        draw();
    }

    system("pause");
}