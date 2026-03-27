if(NOT (GTest_FOUND OR TARGET GTest::gtest_main))
    message(FATAL_ERROR "GoogleTest should be available before entering tests/.")
endif()

add_subdirectory(domain)
add_subdirectory(application)
add_subdirectory(infrastructure)
add_subdirectory(presentation)
