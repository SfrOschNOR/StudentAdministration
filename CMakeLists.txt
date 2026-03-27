cmake_minimum_required(VERSION 3.28)
project(StudentAdministration VERSION 0.5.0 LANGUAGES CXX)

include(CTest)
include(FetchContent)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(GTest QUIET)

if(BUILD_TESTING AND NOT (GTest_FOUND OR TARGET GTest::gtest_main))
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_subdirectory(src/domain)
add_subdirectory(src/application)
add_subdirectory(src/infrastructure)
add_subdirectory(src/presentation)

add_executable(StudentAdministration main.cpp)
target_compile_features(StudentAdministration PRIVATE cxx_std_20)
target_link_libraries(StudentAdministration PRIVATE
    StudentAdministration::Infrastructure
    StudentAdministration::Presentation
    Qt::Widgets
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/StudentAdministrationConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/StudentAdministrationConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/StudentAdministrationConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/StudentAdministration"
)

install(
    TARGETS
        StudentAdministrationDomain
        StudentAdministrationApplication
        StudentAdministrationInfrastructure
        StudentAdministrationPresentation
    EXPORT StudentAdministrationTargets
    FILE_SET public_headers
    FILE_SET generated_headers
)

install(
    EXPORT StudentAdministrationTargets
    FILE StudentAdministrationTargets.cmake
    NAMESPACE StudentAdministration::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/StudentAdministration"
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/StudentAdministrationConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/StudentAdministrationConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/StudentAdministration"
)
