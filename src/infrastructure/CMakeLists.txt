include(GenerateExportHeader)

add_library(StudentAdministrationInfrastructure SHARED
    src/persistence/InMemoryStudentRepository.cpp
)
add_library(StudentAdministration::Infrastructure ALIAS StudentAdministrationInfrastructure)

generate_export_header(StudentAdministrationInfrastructure
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/InfrastructureExport.h
    EXPORT_MACRO_NAME STUDENT_ADMINISTRATION_INFRASTRUCTURE_EXPORT
)

target_compile_features(StudentAdministrationInfrastructure PUBLIC cxx_std_20)

target_sources(StudentAdministrationInfrastructure
    PUBLIC
        FILE_SET public_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
            include/student_administration/student_management/infrastructure/persistence/InMemoryStudentRepository.h
        FILE_SET generated_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/InfrastructureExport.h
)

target_include_directories(StudentAdministrationInfrastructure
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(StudentAdministrationInfrastructure
    PUBLIC
        StudentAdministration::Domain
)

student_administration_apply_defaults(StudentAdministrationInfrastructure)
