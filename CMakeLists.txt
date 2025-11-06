cmake_minimum_required(VERSION 3.16)
project(DnDCompanion VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# SQLite cez pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLITE3 REQUIRED sqlite3)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.h
)

# Add executable
add_executable(DComp ${SOURCES})

# Link Qt6 libraries
target_link_libraries(DComp PRIVATE 
    Qt6::Widgets
    ${SQLITE3_LIBRARIES}    
)

# Include directories
target_include_directories(DComp PRIVATE
    src
    ${SQLITE3_INCLUDE_DIRS}
)


target_include_directories(DComp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
