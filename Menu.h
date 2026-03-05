#pragma once

using namespace ImGui;

void SetupImGui() {
    IMGUI_CHECKVERSION();
    CreateContext();
    ImGuiIO &io = GetIO();
    io.DisplaySize = ImVec2((float) glWidth, (float) glHeight);
    ImGui_ImplOpenGL3_Init("#version 100");
    StyleColorsDark();

    GetStyle().ScaleAllSizes(2.0f); // Change this to scale everything
}

void DrawMenu() {
    static bool showMenu = true;
    SetNextWindowSize(ImVec2(400, 400), ImGuiCond_FirstUseEver);
    if (Begin("Menu", &showMenu)) {
        Text("MCGG");
        if (Button("Close")) {
            showMenu = false;
        }
    	Checkbox("Aurora Double Reward", &dbAurora);
    }
    End();
}