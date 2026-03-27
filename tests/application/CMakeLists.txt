add_executable(StudentAdministrationApplicationTests
    RegisterStudentUseCaseTests.cpp
)

target_link_libraries(StudentAdministrationApplicationTests PRIVATE
    StudentAdministration::Application
    GTest::gtest_main
)
student_administration_apply_defaults(StudentAdministrationApplicationTests)

include(GoogleTest)
gtest_discover_tests(StudentAdministrationApplicationTests)
