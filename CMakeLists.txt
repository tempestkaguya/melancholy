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

corrosion_import_crate(MANIFEST_PATH backend/Cargo.toml)

add_executable(melancholy src/main.cpp)

target_link_libraries(melancholy 
    PRIVATE 
        backend
        Qt6::Widgets
)