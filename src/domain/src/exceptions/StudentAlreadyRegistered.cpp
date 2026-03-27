#include "student_administration/student_management/domain/exceptions/StudentAlreadyRegistered.h"

namespace student_administration::student_management::domain::exceptions {

StudentAlreadyRegistered::StudentAlreadyRegistered(const std::string& emailAddress)
    : DomainException("student with email '" + emailAddress + "' is already registered") {}

} // namespace student_administration::student_management::domain::exceptions
