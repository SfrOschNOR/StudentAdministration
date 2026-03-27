#include "student_administration/student_management/domain/model/Student.h"

namespace student_administration::student_management::domain::model {

Student::Student(value_objects::StudentId id,
                 value_objects::StudentName name,
                 value_objects::EmailAddress email,
                 EnrollmentStatus status)
    : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)), status_(status) {}

Student Student::registerNew(value_objects::StudentName name, value_objects::EmailAddress email) {
    return Student(value_objects::StudentId::generate(), std::move(name), std::move(email));
}

void Student::deactivate() {
    status_ = EnrollmentStatus::Inactive;
}

const value_objects::StudentId& Student::id() const noexcept {
    return id_;
}

const value_objects::StudentName& Student::name() const noexcept {
    return name_;
}

const value_objects::EmailAddress& Student::email() const noexcept {
    return email_;
}

EnrollmentStatus Student::status() const noexcept {
    return status_;
}

bool Student::isActive() const noexcept {
    return status_ == EnrollmentStatus::Active;
}

}  // namespace student_administration::student_management::domain::model
