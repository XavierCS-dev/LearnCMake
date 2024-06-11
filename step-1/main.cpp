#include "LearnCMakeConfig.h"
#include <format>
#include <iostream>
#include <print>

int main(void) {
  std::println("Hello, World!");
  std::cout << std::format("Hello, world! Version: {}",
                           LearnCMake_VERSION_MAJOR)
            << std::endl;
}
