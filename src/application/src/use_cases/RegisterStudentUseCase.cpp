#include "student_administration/student_management/application/use_cases/RegisterStudentUseCase.h"

#include "student_administration/student_management/domain/exceptions/StudentAlreadyRegistered.h"
#include "student_administration/student_management/domain/model/Student.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"
#include "student_administration/student_management/domain/value_objects/StudentName.h"

namespace student_administration::student_management::application::use_cases {

namespace {

std::string toStatusLabel(domain::model::EnrollmentStatus status) {
    return status == domain::model::EnrollmentStatus::Active ? "active" : "inactive";
}

dto::StudentView toStudentView(const domain::model::Student& student) {
    return {
        .id = student.id().value(),
        .fullName = student.name().value(),
        .email = student.email().value(),
        .status = toStatusLabel(student.status()),
    };
}

}  // namespace

RegisterStudentUseCase::RegisterStudentUseCase(domain::repositories::StudentRepository& repository)
    : repository_(repository) {}

dto::StudentView RegisterStudentUseCase::execute(const commands::RegisterStudentCommand& command) const {
    const domain::value_objects::StudentName name(command.fullName);
    const domain::value_objects::EmailAddress email(command.email);

    if (repository_.existsByEmail(email)) {
        throw domain::exceptions::StudentAlreadyRegistered(email.value());
    }

    auto student = domain::model::Student::registerNew(name, email);
    repository_.save(student);

    return toStudentView(student);
}

}  // namespace student_administration::student_management::application::use_cases
