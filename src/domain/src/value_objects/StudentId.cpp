#include "student_administration/student_management/domain/value_objects/StudentId.h"

#include <random>
#include <sstream>
#include <stdexcept>

namespace student_administration::student_management::domain::value_objects {

namespace {

std::string generateToken() {
    static std::mt19937_64 generator(std::random_device{}());
    static std::uniform_int_distribution<unsigned long long> distribution;

    std::ostringstream stream;
    stream << std::hex << distribution(generator) << distribution(generator);
    return stream.str();
}

} // namespace

StudentId StudentId::generate() {
    return StudentId(generateToken());
}

StudentId::StudentId(std::string value) : value_(std::move(value)) {
    if (value_.empty()) {
        throw std::invalid_argument("student id must not be empty");
    }
}

const std::string& StudentId::value() const noexcept {
    return value_;
}

} // namespace student_administration::student_management::domain::value_objects
