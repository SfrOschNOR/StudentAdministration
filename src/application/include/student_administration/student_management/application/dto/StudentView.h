#pragma once

#include <string>

#include "ApplicationExport.h"

namespace student_administration::student_management::application::dto {

/**
 * @brief Read model returned by application use cases for presentation.
 *
 * The DTO keeps the data in UI-friendly string form so presentation code does
 * not need to depend on domain entities or value objects.
 */
struct STUDENT_ADMINISTRATION_APPLICATION_EXPORT StudentView {
    /** @brief Stable identifier of the student. */
    std::string id;
    /** @brief Human-readable full name. */
    std::string fullName;
    /** @brief Email address shown to the user. */
    std::string email;
    /** @brief Display label for the enrollment status, for example `active`. */
    std::string status;
};

} // namespace student_administration::student_management::application::dto
