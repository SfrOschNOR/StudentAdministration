#include "student_administration/student_management/domain/value_objects/EmailAddress.h"

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

bool isValidEmailAddress(const std::string& value) {
    const auto atPosition = value.find('@');
    if (value.empty() || atPosition == std::string::npos || atPosition == 0 ||
        atPosition == value.size() - 1) {
        return false;
    }

    if (value.find('@', atPosition + 1) != std::string::npos) {
        return false;
    }

    const auto dotPosition = value.find('.', atPosition);
    return dotPosition != std::string::npos && dotPosition < value.size() - 1;
}

} // namespace

EmailAddress::EmailAddress(std::string value) : value_(trim(std::move(value))) {
    if (!isValidEmailAddress(value_)) {
        throw std::invalid_argument("email address is invalid");
    }
}

const std::string& EmailAddress::value() const noexcept {
    return value_;
}

} // namespace student_administration::student_management::domain::value_objects
