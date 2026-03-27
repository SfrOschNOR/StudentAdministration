#pragma once

#include <string>

#include "DomainExport.h"

namespace student_administration::student_management::domain::value_objects {

class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentId {
    public:
    static StudentId generate();

    explicit StudentId(std::string value);

    [[nodiscard]] const std::string& value() const noexcept;

    private:
    std::string value_;
};

} // namespace student_administration::student_management::domain::value_objects
