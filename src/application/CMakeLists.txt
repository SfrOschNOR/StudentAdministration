include(GenerateExportHeader)

add_library(StudentAdministrationApplication SHARED
    src/use_cases/ListStudentsUseCase.cpp
    src/use_cases/RegisterStudentUseCase.cpp
)
add_library(StudentAdministration::Application ALIAS StudentAdministrationApplication)

generate_export_header(StudentAdministrationApplication
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/ApplicationExport.h
    EXPORT_MACRO_NAME STUDENT_ADMINISTRATION_APPLICATION_EXPORT
)

target_compile_features(StudentAdministrationApplication PUBLIC cxx_std_20)

target_sources(StudentAdministrationApplication
    PUBLIC
        FILE_SET public_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
            include/student_administration/student_management/application/commands/RegisterStudentCommand.h
            include/student_administration/student_management/application/dto/StudentView.h
            include/student_administration/student_management/application/use_cases/ListStudentsUseCase.h
            include/student_administration/student_management/application/use_cases/RegisterStudentUseCase.h
        FILE_SET generated_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/ApplicationExport.h
)

target_include_directories(StudentAdministrationApplication
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(StudentAdministrationApplication
    PUBLIC
        StudentAdministration::Domain
)
