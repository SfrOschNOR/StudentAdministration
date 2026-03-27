include(GenerateExportHeader)

add_library(StudentAdministrationDomain SHARED
    src/exceptions/DomainException.cpp
    src/exceptions/StudentAlreadyRegistered.cpp
    src/model/Student.cpp
    src/value_objects/EmailAddress.cpp
    src/value_objects/StudentId.cpp
    src/value_objects/StudentName.cpp
)
add_library(StudentAdministration::Domain ALIAS StudentAdministrationDomain)

generate_export_header(StudentAdministrationDomain
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/DomainExport.h
    EXPORT_MACRO_NAME STUDENT_ADMINISTRATION_DOMAIN_EXPORT
)

target_compile_features(StudentAdministrationDomain PUBLIC cxx_std_20)

target_sources(StudentAdministrationDomain
    PUBLIC
        FILE_SET public_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
            include/student_administration/student_management/domain/exceptions/DomainException.h
            include/student_administration/student_management/domain/exceptions/StudentAlreadyRegistered.h
            include/student_administration/student_management/domain/model/Student.h
            include/student_administration/student_management/domain/repositories/StudentRepository.h
            include/student_administration/student_management/domain/value_objects/EmailAddress.h
            include/student_administration/student_management/domain/value_objects/StudentId.h
            include/student_administration/student_management/domain/value_objects/StudentName.h
        FILE_SET generated_headers TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/DomainExport.h
)

target_include_directories(StudentAdministrationDomain
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

student_administration_apply_defaults(StudentAdministrationDomain)
