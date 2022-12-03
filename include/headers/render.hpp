#pragma once

void input()
{
    glfwPollEvents();
}

void draw()
{
    glClearColor(0.25f,0.25,0.75f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void draw_gui()
{
    //New frame for OpenGL
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();

    //Drawing GUI 
    ImGui::NewFrame();
    
    ImGui::Begin("Boss window");
    
    ImGui::Text("Helloo Mr.Boss!");
    
    ImGui::End();
    
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void update_window(GLFWwindow* a_window)
{
    glfwSwapBuffers(a_window);
}
