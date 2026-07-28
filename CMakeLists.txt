cmake_minimum_required(VERSION 3.22)
project(melancholy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include(FetchContent)
FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.5.0
)
FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH src/core/Cargo.toml)

file(GLOB_RECURSE ALL_SOURCES 
    "src/*.cpp"
    "src/*.h"
    "widgets/*.h"
    "widgets/*.cpp"
)

add_executable(melancholy ${ALL_SOURCES})

target_include_directories(melancholy PRIVATE src)

target_link_libraries(melancholy 
    PRIVATE 
        core
        Qt6::Widgets
)
