cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SnakeGame VERSION 1.0)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include project header files
include_directories(${CMAKE_SOURCE_DIR}/src)

# Define source files
set(SOURCES
        src/main.cpp
        src/game.cpp
        src/controller.cpp
        src/renderer.cpp
        src/snake.cpp
        src/obstacle.cpp
        src/speed_selector.cpp
        src/high_score.cpp
)

# Create executable with a unique name to avoid conflicts
add_executable(SnakeGameApp ${SOURCES})

# Link SDL2 libraries
target_link_libraries(SnakeGameApp ${SDL2_LIBRARIES})

# Install the executable
install(TARGETS SnakeGameApp DESTINATION bin)