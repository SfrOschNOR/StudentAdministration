#pragma once

#include <string>

#include "DomainExport.h"

namespace student_administration::student_management::domain::value_objects {

/**
 * @brief Value object representing a validated student name.
 *
 * The constructor trims surrounding whitespace and rejects empty names so the
 * domain model always works with meaningful user names.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentName {
    public:
    /**
     * @brief Creates a validated student name.
     * @param value Raw name string provided by a caller.
     * @throws std::invalid_argument If the name is empty after trimming.
     */
    explicit StudentName(std::string value);

    /**
     * @brief Returns the normalized name string.
     * @return Stored name value.
     */
    [[nodiscard]] const std::string& value() const noexcept;

    private:
    std::string value_;
};

} // namespace student_administration::student_management::domain::value_objects
