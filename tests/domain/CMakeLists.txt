add_executable(StudentAdministrationDomainTests
    StudentTests.cpp
)

target_link_libraries(StudentAdministrationDomainTests PRIVATE
    StudentAdministration::Domain
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(StudentAdministrationDomainTests)
