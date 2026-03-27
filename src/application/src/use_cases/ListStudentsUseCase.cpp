#include "student_administration/student_management/application/use_cases/ListStudentsUseCase.h"

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

} // namespace

ListStudentsUseCase::ListStudentsUseCase(const domain::repositories::StudentRepository& repository)
    : repository_(repository) {}

std::vector<dto::StudentView> ListStudentsUseCase::execute() const {
    std::vector<dto::StudentView> students;
    for (const auto& student : repository_.findAll()) {
        students.push_back(toStudentView(student));
    }
    return students;
}

} // namespace student_administration::student_management::application::use_cases
