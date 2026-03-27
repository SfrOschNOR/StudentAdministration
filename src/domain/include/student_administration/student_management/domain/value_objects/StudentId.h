#pragma once

#include <string>

#include "DomainExport.h"

namespace student_administration::student_management::domain::value_objects {

/**
 * @brief Value object representing the identity of a student aggregate.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentId {
    public:
    /**
     * @brief Generates a new non-empty student identifier.
     * @return Fresh identifier suitable for a new aggregate.
     */
    static StudentId generate();

    /**
     * @brief Creates a student identifier from an existing value.
     * @param value Identifier string, for example from persistence.
     * @throws std::invalid_argument If the identifier is empty.
     */
    explicit StudentId(std::string value);

    /**
     * @brief Returns the raw identifier string.
     * @return Stored identifier value.
     */
    [[nodiscard]] const std::string& value() const noexcept;

    private:
    std::string value_;
};

} // namespace student_administration::student_management::domain::value_objects
