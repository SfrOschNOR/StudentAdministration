if(NOT DEFINED CLANG_FORMAT_BIN)
    message(FATAL_ERROR "CLANG_FORMAT_BIN is required.")
endif()

if(NOT DEFINED PROJECT_SOURCE_DIR)
    message(FATAL_ERROR "PROJECT_SOURCE_DIR is required.")
endif()

if(NOT DEFINED MODE)
    message(FATAL_ERROR "MODE must be 'apply' or 'check'.")
endif()

file(GLOB_RECURSE PROJECT_CPP_FILES
    LIST_DIRECTORIES FALSE
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/tests/*.h"
    "${PROJECT_SOURCE_DIR}/tests/*.cpp"
)

list(SORT PROJECT_CPP_FILES)

if(PROJECT_CPP_FILES STREQUAL "")
    message(FATAL_ERROR "No C++ files found for clang-format.")
endif()

if(MODE STREQUAL "apply")
    execute_process(
        COMMAND ${CLANG_FORMAT_BIN} -i ${PROJECT_CPP_FILES}
        RESULT_VARIABLE result
    )
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "clang-format failed while applying formatting.")
    endif()
elseif(MODE STREQUAL "check")
    execute_process(
        COMMAND ${CLANG_FORMAT_BIN} --dry-run --Werror ${PROJECT_CPP_FILES}
        RESULT_VARIABLE result
    )
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "clang-format reported formatting differences.")
    endif()
else()
    message(FATAL_ERROR "Unsupported MODE='${MODE}'.")
endif()
