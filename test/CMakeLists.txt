find_package(Catch2 2.9 CONFIG REQUIRED)

add_executable(test_vmix_taskio)

set_target_properties(test_vmix_taskio PROPERTIES
    OUTPUT_NAME "test-taskio"
)

target_link_libraries(test_vmix_taskio
    PRIVATE
        vmix::taskio
        Catch2::Catch2
)

target_include_directories(test_vmix_taskio
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(test_vmix_taskio
    PRIVATE
        main.cpp
        test_version.cpp
)

add_test(NAME test-v-mix-taskmgr
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test-taskio -r junit -o ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test-taskio.junit.xml
)
