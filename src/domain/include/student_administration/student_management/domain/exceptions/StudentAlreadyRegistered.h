#pragma once

#include <string>

#include "DomainExport.h"
#include "student_administration/student_management/domain/exceptions/DomainException.h"

namespace student_administration::student_management::domain::exceptions {

class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentAlreadyRegistered : public DomainException {
    public:
    explicit StudentAlreadyRegistered(const std::string& emailAddress);
};

} // namespace student_administration::student_management::domain::exceptions
