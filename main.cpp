#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <assimp/Importer.hpp>

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>

//DEBUGGING!!!
#define LOG(message) cout << message
#ifndef LOG
#define LOG(message)
#endif

using std::string; using std::cout; using std::endl; using std::vector;
using std::pair; using std::cin; using std::make_pair; using std::stringstream;
using std::stoi;

GLFWwindow* window;
const unsigned int window_width = 1080, window_height = 720;

#include <headers/image.hpp>
#include <headers/shader.hpp>
#include <headers/render.hpp>

int main() 
{
    //Initialising OpenGL
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, true);
    window = glfwCreateWindow(window_width, window_height, "OpenGL App Window", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGL();


    //Initialising IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); //(void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();

    //Initialising IMGUI for OpenGL
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