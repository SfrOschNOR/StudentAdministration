#pragma once

#include <string>

#include "DomainExport.h"

namespace student_administration::student_management::domain::value_objects {

/**
 * @brief Value object representing a validated email address.
 *
 * The constructor trims surrounding whitespace and enforces a minimal email
 * shape so invalid addresses cannot enter the domain model.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT EmailAddress {
    public:
    /**
     * @brief Creates a validated email address value object.
     * @param value Raw email string provided by a caller.
     * @throws std::invalid_argument If the email address is empty or malformed.
     */
    explicit EmailAddress(std::string value);

    /**
     * @brief Returns the normalized email string.
     * @return Stored email value.
     */
    [[nodiscard]] const std::string& value() const noexcept;

    private:
    std::string value_;
};

} // namespace student_administration::student_management::domain::value_objects
