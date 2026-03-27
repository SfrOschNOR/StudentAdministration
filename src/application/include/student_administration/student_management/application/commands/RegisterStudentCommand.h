#pragma once

#include <string>

#include "ApplicationExport.h"

namespace student_administration::student_management::application::commands {

/**
 * @brief Carries the user input required to register a new student.
 *
 * This command is the write-side input model for the registration use case.
 * It intentionally keeps raw strings so the application layer can construct
 * and validate the corresponding domain value objects.
 */
struct STUDENT_ADMINISTRATION_APPLICATION_EXPORT RegisterStudentCommand {
    /** @brief Full name entered by the user. */
    std::string fullName;
    /** @brief Email address entered by the user. */
    std::string email;
};

} // namespace student_administration::student_management::application::commands
