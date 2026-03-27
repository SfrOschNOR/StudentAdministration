#pragma once

#include <stdexcept>
#include <string>

#include "DomainExport.h"

namespace student_administration::student_management::domain::exceptions {

/**
 * @brief Base type for business rule violations raised by the domain model.
 *
 * Use this exception type, or types derived from it, when a failure represents
 * a meaningful domain concept rather than a technical infrastructure problem.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT DomainException : public std::runtime_error {
    public:
    /**
     * @brief Creates a domain exception with a user-readable message.
     * @param message Description of the violated business rule.
     */
    explicit DomainException(const std::string& message);
};

} // namespace student_administration::student_management::domain::exceptions
