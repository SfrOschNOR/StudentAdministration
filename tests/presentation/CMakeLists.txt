add_executable(StudentAdministrationPresentationTests
    MainWindowTests.cpp
)

target_link_libraries(StudentAdministrationPresentationTests PRIVATE
    StudentAdministration::Infrastructure
    StudentAdministration::Presentation
    GTest::gtest_main
)
student_administration_apply_defaults(StudentAdministrationPresentationTests)

include(GoogleTest)
gtest_discover_tests(StudentAdministrationPresentationTests)
