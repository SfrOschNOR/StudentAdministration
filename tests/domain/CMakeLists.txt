add_executable(StudentAdministrationDomainTests StudentTests.cpp)

    target_link_libraries(
        StudentAdministrationDomainTests PRIVATE StudentAdministration::Domain GTest::gtest_main)
        student_administration_apply_defaults(StudentAdministrationDomainTests)
            student_administration_apply_clang_tidy(StudentAdministrationDomainTests)

                include(GoogleTest) gtest_discover_tests(StudentAdministrationDomainTests)
