#pragma once

#include <string>

#include "DomainExport.h"
#include "student_administration/student_management/domain/exceptions/DomainException.h"

namespace student_administration::student_management::domain::exceptions {

/**
 * @brief Signals that a student cannot be registered because the email already exists.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentAlreadyRegistered : public DomainException {
    public:
    /**
     * @brief Creates the exception for a duplicate email address.
     * @param emailAddress Email address that caused the conflict.
     */
    explicit StudentAlreadyRegistered(const std::string& emailAddress);
};

} // namespace student_administration::student_management::domain::exceptions
