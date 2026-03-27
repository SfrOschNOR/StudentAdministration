#include "student_administration/student_management/domain/value_objects/StudentName.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace student_administration::student_management::domain::value_objects {

namespace {

std::string trim(std::string value) {
    const auto first = std::find_if_not(value.begin(), value.end(), [](unsigned char character) {
        return std::isspace(character) != 0;
    });
    const auto last = std::find_if_not(value.rbegin(), value.rend(), [](unsigned char character) {
        return std::isspace(character) != 0;
    }).base();

    if (first >= last) {
        return {};
    }

    return std::string(first, last);
}

}  // namespace

StudentName::StudentName(std::string value) : value_(trim(std::move(value))) {
    if (value_.empty()) {
        throw std::invalid_argument("student name must not be empty");
    }
}

const std::string& StudentName::value() const noexcept {
    return value_;
}

}  // namespace student_administration::student_management::domain::value_objects
