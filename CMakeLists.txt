cmake_minimum_required(VERSION 3.15...3.16)

#
## vcpkg
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CMAKE_TOOLCHAIN_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "vcpkg toolchain file"
    )
endif()

project(vmix_taskio_proj
    VERSION 1.0.0
    LANGUAGES CXX
)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)

option(BUILD_SHARED_LIBS    "Build shared libs" ON)
option(BUILD_TESTING        "Build tests"       ON)

add_library(vmix_taskio)
add_library(vmix::taskio ALIAS vmix_taskio)

set_target_properties(vmix_taskio PROPERTIES
    OUTPUT_NAME "taskio"
)

target_compile_features(vmix_taskio
    PUBLIC cxx_std_17
)

target_include_directories(vmix_taskio
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(GenerateExportHeader)
generate_export_header(vmix_taskio
    EXPORT_FILE_NAME include/vmix/taskio/export.hpp
)

target_sources(vmix_taskio
    PRIVATE
        src/detail/in_memory_task_storage.cpp
        src/main.cpp
        src/task.cpp
        src/task_service.cpp
        src/task_storage.cpp
)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
