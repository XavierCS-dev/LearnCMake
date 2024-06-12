# Add all needed source files
set(SRC 
  "imgui.cpp"
  "imgui_demo.cpp"
  "imgui_draw.cpp"
  "imgui_tables.cpp"
  "imgui_widgets.cpp"
  "backends/imgui_impl_vulkan.cpp"
)

# Add a library target called DearImGUI
add_library(DearImGUI ${SRC})

# Add the directories to search, using the global project
target_include_directories(DearImGUI PUBLIC
                           "${PROJECT_SOURCE_DIR}/deps/imgui"
                           "${PROJECT_SOURCE_DIR}/deps/imgui/backends"
                           )
