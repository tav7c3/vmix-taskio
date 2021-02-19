add_executable(test_vmix_taskio)

set_target_properties(test_vmix_taskio PROPERTIES
    OUTPUT_NAME "test-taskio"
)

target_link_libraries(test_vmix_taskio
    PRIVATE
        vmix::taskio
)

target_include_directories(test_vmix_taskio
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(test_vmix_taskio
    PRIVATE
        main.cpp
)

add_test(NAME test-v-mix-taskmgr
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test-taskio
)
