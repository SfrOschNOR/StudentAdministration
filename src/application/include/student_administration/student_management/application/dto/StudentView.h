#pragma once

#include <string>

#include "ApplicationExport.h"

namespace student_administration::student_management::application::dto {

struct STUDENT_ADMINISTRATION_APPLICATION_EXPORT StudentView {
    std::string id;
    std::string fullName;
    std::string email;
    std::string status;
};

}  // namespace student_administration::student_management::application::dto
