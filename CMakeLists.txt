cmake_minimum_required(VERSION 3.16)
project(DnDCompanion VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SQLITE3 REQUIRED sqlite3)

add_library(dndcore
    src/data/repositories/SpellRepository.cpp
    src/data/services/SpellService.cpp
)

target_include_directories(dndcore PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${SQLITE3_INCLUDE_DIRS}
)

target_link_libraries(dndcore PUBLIC
    ${SQLITE3_LIBRARIES}
)

file(GLOB_RECURSE CLI_SOURCES CONFIGURE_DEPENDS
    src/cli/*.cpp
)

add_executable(dndcli
    src/app/main.cpp
    ${CLI_SOURCES}
)

target_link_libraries(dndcli PRIVATE dndcore)

add_custom_target(run
    COMMAND dndcli
    DEPENDS dndcli
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
