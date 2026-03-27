#pragma once

#include "DomainExport.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"
#include "student_administration/student_management/domain/value_objects/StudentId.h"
#include "student_administration/student_management/domain/value_objects/StudentName.h"

namespace student_administration::student_management::domain::model {

/**
 * @brief Lifecycle state of a student within the bounded context.
 */
enum class EnrollmentStatus {
    /** @brief The student is currently active. */
    Active,
    /** @brief The student was deactivated and is no longer active. */
    Inactive
};

/**
 * @brief Aggregate root representing a student in the student management context.
 *
 * The aggregate owns the student's identity, name, email address and lifecycle
 * status. In a larger system, additional behavior and invariants that belong to
 * the student would also live here.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT Student {
    public:
    /**
     * @brief Rehydrates or explicitly constructs a student aggregate.
     * @param id Stable identifier of the student.
     * @param name Validated student name value object.
     * @param email Validated email address value object.
     * @param status Current enrollment status of the student.
     */
    Student(value_objects::StudentId id,
            value_objects::StudentName name,
            value_objects::EmailAddress email,
            EnrollmentStatus status = EnrollmentStatus::Active);

    /**
     * @brief Factory for a newly registered active student.
     * @param name Validated student name.
     * @param email Validated student email address.
     * @return A new active student with a generated identifier.
     */
    [[nodiscard]] static Student registerNew(value_objects::StudentName name,
                                             value_objects::EmailAddress email);

    /**
     * @brief Marks the student as inactive.
     */
    void deactivate();

    /**
     * @brief Returns the student's identifier.
     * @return Immutable student identifier value object.
     */
    [[nodiscard]] const value_objects::StudentId& id() const noexcept;
    /**
     * @brief Returns the student's name.
     * @return Immutable student name value object.
     */
    [[nodiscard]] const value_objects::StudentName& name() const noexcept;
    /**
     * @brief Returns the student's email address.
     * @return Immutable email value object.
     */
    [[nodiscard]] const value_objects::EmailAddress& email() const noexcept;
    /**
     * @brief Returns the current enrollment status.
     * @return Active or inactive status of the aggregate.
     */
    [[nodiscard]] EnrollmentStatus status() const noexcept;
    /**
     * @brief Convenience check for the active state.
     * @return `true` if the student is active, otherwise `false`.
     */
    [[nodiscard]] bool isActive() const noexcept;

    private:
    value_objects::StudentId id_;
    value_objects::StudentName name_;
    value_objects::EmailAddress email_;
    EnrollmentStatus status_;
};

} // namespace student_administration::student_management::domain::model
