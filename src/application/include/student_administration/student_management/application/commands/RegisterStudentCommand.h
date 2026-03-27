#pragma once

#include <string>

#include "ApplicationExport.h"

namespace student_administration::student_management::application::commands {

struct STUDENT_ADMINISTRATION_APPLICATION_EXPORT RegisterStudentCommand {
    std::string fullName;
    std::string email;
};

}  // namespace student_administration::student_management::application::commands
