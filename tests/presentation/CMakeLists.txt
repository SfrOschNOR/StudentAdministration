add_executable(StudentAdministrationPresentationTests
    MainWindowTests.cpp
)

target_link_libraries(StudentAdministrationPresentationTests PRIVATE
    StudentAdministration::Infrastructure
    StudentAdministration::Presentation
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(StudentAdministrationPresentationTests)
