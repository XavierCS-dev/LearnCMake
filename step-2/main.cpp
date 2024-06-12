#include "LearnCMakeConfig.h"
#include "imgui.h"
#include <format>
#include <iostream>
#include <print>

int main(void) {
  std::println("Hello, World!");
  std::cout << std::format("Hello, world! Version: {}",
                           LearnCMake_VERSION_MAJOR)
            << std::endl;
  std::cout << IMGUI_CHECKVERSION() << std::endl;
#ifdef GOODBYE_WORLD
  std::println("Goodbye, world!");
#endif
}
