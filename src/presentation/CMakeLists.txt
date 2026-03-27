include(GenerateExportHeader)

add_library(StudentAdministrationPresentation SHARED
    src/qt/MainWindow.cpp
)
add_library(StudentAdministration::Presentation ALIAS StudentAdministrationPresentation)

generate_export_header(StudentAdministrationPresentation
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/PresentationExport.h
    EXPORT_MACRO_NAME STUDENT_ADMINISTRATION_PRESENTATION_EXPORT
)

target_compile_features(StudentAdministrationPresentation PUBLIC cxx_std_20)
set_target_properties(StudentAdministrationPresentation PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)

target_sources(StudentAdministrationPresentation
    PUBLIC
        FILE_SET public_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
            include/student_administration/student_management/presentation/qt/MainWindow.h
        FILE_SET generated_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/PresentationExport.h
)

target_include_directories(StudentAdministrationPresentation
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(StudentAdministrationPresentation
    PUBLIC
        StudentAdministration::Application
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

student_administration_apply_defaults(StudentAdministrationPresentation)
student_administration_apply_sanitizers(StudentAdministrationPresentation)
student_administration_apply_clang_tidy(StudentAdministrationPresentation)
