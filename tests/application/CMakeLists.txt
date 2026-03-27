add_executable(StudentAdministrationApplicationTests
    RegisterStudentUseCaseTests.cpp
)

target_link_libraries(StudentAdministrationApplicationTests PRIVATE
    StudentAdministration::Application
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(StudentAdministrationApplicationTests)
