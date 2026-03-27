#include "student_administration/student_management/domain/exceptions/DomainException.h"

namespace student_administration::student_management::domain::exceptions {

DomainException::DomainException(const std::string& message) : std::runtime_error(message) {}

} // namespace student_administration::student_management::domain::exceptions
