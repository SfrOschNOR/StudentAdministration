add_executable(StudentAdministrationInfrastructureTests
    InMemoryStudentRepositoryTests.cpp
)

target_link_libraries(StudentAdministrationInfrastructureTests PRIVATE
    StudentAdministration::Infrastructure
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(StudentAdministrationInfrastructureTests)
