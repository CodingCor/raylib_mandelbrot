cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(raylib_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
# set(BUILD_SHARED_LIBS TRUE)

add_subdirectory(lib/raylib)

# Comment: To ship the game in a self contained package use rpath
#set(LIBRARY_PATH "")
#set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
#set(CMAKE_INSTALL_RPATH $ORIGIN)

#Project

add_executable(${PROJECT_NAME} main.cpp)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# windows configuration
# Linker Options needed for Windows Builds
if(WIN32)
    message(WIN32 Build)
    target_link_options(${PROJECT_NAME} PRIVATE -mwin32 -mwindows)
endif()

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    message(WEB Build)
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    message(APPLE Build)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
