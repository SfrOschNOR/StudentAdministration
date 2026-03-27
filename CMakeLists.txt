cmake_minimum_required(VERSION 3.28) project(StudentAdministration VERSION 0.5.0 LANGUAGES CXX)

    include(CTest) include(FetchContent) include(GNUInstallDirs) include(CMakePackageConfigHelpers)

        set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

            option(ENABLE_CLANG_TIDY "Run clang-tidy during C++ compilation." OFF) option(
                ENABLE_CLANG_FORMAT_TARGETS "Add clang-format helper targets." ON)

                find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED) find_package(GTest QUIET)

                    find_program(CLANG_TIDY_BIN NAMES clang -
                                 tidy) find_program(CLANG_FORMAT_BIN NAMES clang - format)

                        add_library(StudentAdministrationWarnings INTERFACE) add_library(
                            StudentAdministration::Warnings ALIAS StudentAdministrationWarnings)

                            target_compile_options(
                                StudentAdministrationWarnings INTERFACE
                                    $<$<CXX_COMPILER_ID : Clang, GNU> : -Wall - Wextra - Wpedantic -
                                          Wconversion - Wsign - conversion - Wshadow - Wundef -
                                          Wdouble - promotion - Wformat = 2 - Werror>
                                        $<$<CXX_COMPILER_ID : MSVC> : / W4 / WX / permissive ->)

                                function(
                                    student_administration_apply_defaults
                                        target_name) target_link_libraries(${
                                    target_name} PRIVATE StudentAdministration::
                                                                               Warnings) endfunction()

                                    if (ENABLE_CLANG_TIDY) if (NOT CLANG_TIDY_BIN) message(
                                        FATAL_ERROR "ENABLE_CLANG_TIDY is ON, but clang-tidy was "
                                                    "not found.") endif() endif()

                                        function(student_administration_apply_clang_tidy target_name) if (
                                            ENABLE_CLANG_TIDY) set_target_properties(${
                                            target_name} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_"
                                                                                   "BIN};--extra-"
                                                                                   "arg-before=--"
                                                                                   "driver-mode=g+"
                                                                                   "+") endif() endfunction()

                                            if (BUILD_TESTING AND NOT(GTest_FOUND OR TARGET GTest::gtest_main)) FetchContent_Declare(
                                                googletest URL https
                                                : // github.com/google/googletest/archive/refs/tags/v1.17.0.zip
                                                DOWNLOAD_EXTRACT_TIMESTAMP
                                                    OFF) set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
                                                set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) set(
                                                    gtest_force_shared_crt ON
                                                        CACHE BOOL
                                                    "" FORCE) FetchContent_MakeAvailable(googletest) endif()

                                                    add_subdirectory(src / domain) add_subdirectory(src / application) add_subdirectory(
                                                        src / infrastructure) add_subdirectory(src /
                                                                                               presentation)

                                                        add_executable(StudentAdministration main.cpp) target_compile_features(
                                                            StudentAdministration PRIVATE
                                                                cxx_std_20)
                                                            target_link_libraries(
                                                                StudentAdministration PRIVATE
                                                                    StudentAdministration::Infrastructure
                                                                        StudentAdministration::
                                                                            Presentation Qt::
                                                                                Widgets) student_administration_apply_defaults(StudentAdministration)
                                                                student_administration_apply_clang_tidy(
                                                                    StudentAdministration)

                                                                    if (BUILD_TESTING) add_subdirectory(
                                                                        tests) endif()

                                                                        if (ENABLE_CLANG_FORMAT_TARGETS) if (CLANG_FORMAT_BIN) add_custom_target(
                                                                            format COMMAND ${
                                                                                CMAKE_COMMAND} -
                                                                                DCLANG_FORMAT_BIN =
                                                                                ${CLANG_FORMAT_BIN} -
                                                                                DPROJECT_SOURCE_DIR =
                                                                                    ${CMAKE_SOURCE_DIR} -
                                                                                    DMODE =
                                                                                        apply -
                                                                                        P ${CMAKE_SOURCE_DIR} /
                                                                                            cmake /
                                                                                            RunClangFormat
                                                                                                .cmake COMMENT
                                                                                            "Format"
                                                                                            "ting "
                                                                                            "C++ "
                                                                                            "source"
                                                                                            "s "
                                                                                            "with "
                                                                                            "clang-"
                                                                                            "forma"
                                                                                            "t")

                                                                            add_custom_target(
                                                                                format -
                                                                                    check COMMAND ${
                                                                                        CMAKE_COMMAND} -
                                                                                    DCLANG_FORMAT_BIN =
                                                                                    ${CLANG_FORMAT_BIN} -
                                                                                    DPROJECT_SOURCE_DIR =
                                                                                        ${CMAKE_SOURCE_DIR} -
                                                                                        DMODE =
                                                                                            check -
                                                                                            P ${CMAKE_SOURCE_DIR} /
                                                                                                cmake /
                                                                                                RunClangFormat
                                                                                                    .cmake COMMENT
                                                                                                "Ch"
                                                                                                "ec"
                                                                                                "ki"
                                                                                                "ng"
                                                                                                " C"
                                                                                                "++"
                                                                                                " f"
                                                                                                "or"
                                                                                                "ma"
                                                                                                "tt"
                                                                                                "in"
                                                                                                "g "
                                                                                                "wi"
                                                                                                "th"
                                                                                                " c"
                                                                                                "la"
                                                                                                "ng"
                                                                                                "-f"
                                                                                                "or"
                                                                                                "ma"
                                                                                                "t") else()
                                                                                message(STATUS
                                                                                        "clang-"
                                                                                        "format "
                                                                                        "was not "
                                                                                        "found; "
                                                                                        "'format' "
                                                                                        "targets "
                                                                                        "will not "
                                                                                        "be "
                                                                                        "available"
                                                                                        ".") endif() endif()

                                                                                    write_basic_package_version_file(
                                                                                        "${CMAKE_"
                                                                                        "CURRENT_"
                                                                                        "BINARY_"
                                                                                        "DIR}/"
                                                                                        "StudentAdm"
                                                                                        "inistratio"
                                                                                        "nConfigVer"
                                                                                        "sion."
                                                                                        "cmak"
                                                                                        "e" VERSION ${
                                                                                            PROJECT_VERSION} COMPATIBILITY
                                                                                            SameMajorVersion)

                                                                                        configure_package_config_file(
                                                                                            "${"
                                                                                            "CMAKE_"
                                                                                            "CURREN"
                                                                                            "T_"
                                                                                            "SOURCE"
                                                                                            "_DIR}/"
                                                                                            "cmake/"
                                                                                            "Studen"
                                                                                            "tAdmin"
                                                                                            "istrat"
                                                                                            "ionCon"
                                                                                            "fig."
                                                                                            "cmake."
                                                                                            "in"
                                                                                            "${"
                                                                                            "CMAKE_"
                                                                                            "CURREN"
                                                                                            "T_"
                                                                                            "BINARY"
                                                                                            "_DIR}/"
                                                                                            "Studen"
                                                                                            "tAdmin"
                                                                                            "istrat"
                                                                                            "ionCon"
                                                                                            "fig."
                                                                                            "cmak"
                                                                                            "e" INSTALL_DESTINATION
                                                                                            "${"
                                                                                            "CMAKE_"
                                                                                            "INSTAL"
                                                                                            "L_"
                                                                                            "LIBDIR"
                                                                                            "}/"
                                                                                            "cmake/"
                                                                                            "Studen"
                                                                                            "tAdmin"
                                                                                            "istrat"
                                                                                            "ion")

                                                                                            install(
                                                                                                TARGETS StudentAdministrationDomain StudentAdministrationApplication
                                                                                                    StudentAdministrationInfrastructure
                                                                                                        StudentAdministrationPresentation
                                                                                                            EXPORT StudentAdministrationTargets
                                                                                                                FILE_SET public_headers
                                                                                                                    FILE_SET
                                                                                                                        generated_headers)

                                                                                                install(
                                                                                                    EXPORT StudentAdministrationTargets
                                                                                                        FILE StudentAdministrationTargets
                                                                                                            .cmake NAMESPACE
                                                                                                                StudentAdministration::
                                                                                                                    DESTINATION
                                                                                                    "${CMAKE_INSTALL_LIBDIR}/cmake/StudentAdministration")

                                                                                                    install(
                                                                                                        FILES
                                                                                                        "${CMAKE_CURRENT_BINARY_DIR}/StudentAdministrationConfig.cmake"
                                                                                                        "${CMAKE_CURRENT_BINARY_DIR}/StudentAdministrationConfigVersion.cmake" DESTINATION
                                                                                                        "${CMAKE_INSTALL_LIBDIR}/cmake/StudentAdministration")
