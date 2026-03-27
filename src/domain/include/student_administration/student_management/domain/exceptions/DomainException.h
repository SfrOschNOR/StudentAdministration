#pragma once

#include <stdexcept>
#include <string>

#include "DomainExport.h"

namespace student_administration::student_management::domain::exceptions {

class STUDENT_ADMINISTRATION_DOMAIN_EXPORT DomainException : public std::runtime_error {
    public:
    explicit DomainException(const std::string& message);
};

} // namespace student_administration::student_management::domain::exceptions
