cmake_minimum_required(VERSION 3.21)
project(meinkraft VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING
            "Choose the type of build (Debug or Release)" FORCE)
endif()

# Export compile commands for completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

if(NOT USE_INSTALL_RESOURCE_PATH)
    set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
else()
    set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/content/")
endif()

# Generate config.h
configure_file(include/config.h.in config.h)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(meinkraft src/main.cpp include/renderer.h include/sprite.h src/sprite.cpp include/game.h src/game.cpp include/keyboard_handler.h include/state.h include/game_state.h src/game_state.cpp include/sprite_sheet.h src/sprite_sheet.cc include/window.h src/window.cpp src/renderer.cpp include/color.h src/color.cpp include/entities/entity.h include/entities/renderable_entity.h include/rect.h)

target_include_directories(meinkraft
        PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Set executable RPATH
set_target_properties(meinkraft
        PROPERTIES
        INSTALL_RPATH
        "${CMAKE_INSTALL_PREFIX}/lib"
        )

# Link executable to required SFML modules
target_link_libraries(meinkraft sfml-graphics sfml-audio)

# Set executable install location
install(TARGETS meinkraft DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)
