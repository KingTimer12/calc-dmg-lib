cmake_minimum_required(VERSION 3.15)
project(calcdmglib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(calcdmglib INTERFACE)

target_include_directories(calcdmglib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(calcdmglib INTERFACE
    CALCDMGLIB_VERSION="1.0.0"
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/calcdmglibConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/calcdmglibConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/calcdmglibConfig.cmake"
    INSTALL_DESTINATION lib/cmake/calcdmglib
)

install(TARGETS calcdmglib EXPORT calcdmglibTargets)
install(EXPORT calcdmglibTargets
    FILE calcdmglibTargets.cmake
    NAMESPACE calcdmglib::
    DESTINATION lib/cmake/calcdmglib
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/calcdmglibConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/calcdmglibConfigVersion.cmake"
    DESTINATION lib/cmake/calcdmglib
)
install(DIRECTORY include/ DESTINATION include)

enable_testing()
add_subdirectory(tests)