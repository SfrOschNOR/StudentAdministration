#pragma once

// DomainExport.h wird von CMake pro Modul generiert.
// Das Export-Makro markiert die Public API der Domain-DLL, damit Symbole
// beim Bauen/Verwenden von Shared Libraries korrekt exportiert bzw. importiert werden.
#include "DomainExport.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"
#include "student_administration/student_management/domain/value_objects/StudentId.h"
#include "student_administration/student_management/domain/value_objects/StudentName.h"

namespace student_administration::student_management::domain::model {

enum class EnrollmentStatus {
    Active,
    Inactive
};

class STUDENT_ADMINISTRATION_DOMAIN_EXPORT Student {
public:
    Student(value_objects::StudentId id,
            value_objects::StudentName name,
            value_objects::EmailAddress email,
            EnrollmentStatus status = EnrollmentStatus::Active);

    [[nodiscard]] static Student registerNew(value_objects::StudentName name,
                                             value_objects::EmailAddress email);

    void deactivate();

    [[nodiscard]] const value_objects::StudentId& id() const noexcept;
    [[nodiscard]] const value_objects::StudentName& name() const noexcept;
    [[nodiscard]] const value_objects::EmailAddress& email() const noexcept;
    [[nodiscard]] EnrollmentStatus status() const noexcept;
    [[nodiscard]] bool isActive() const noexcept;

private:
    value_objects::StudentId id_;
    value_objects::StudentName name_;
    value_objects::EmailAddress email_;
    EnrollmentStatus status_;
};

}  // namespace student_administration::student_management::domain::model
