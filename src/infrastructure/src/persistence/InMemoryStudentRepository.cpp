#include "student_administration/student_management/infrastructure/persistence/InMemoryStudentRepository.h"

namespace student_administration::student_management::infrastructure::persistence {

void InMemoryStudentRepository::save(domain::model::Student student) {
    students_.push_back(std::move(student));
}

std::vector<domain::model::Student> InMemoryStudentRepository::findAll() const {
    return students_;
}

bool InMemoryStudentRepository::existsByEmail(const domain::value_objects::EmailAddress& email) const {
    for (const auto& student : students_) {
        if (student.email().value() == email.value()) {
            return true;
        }
    }
    return false;
}

}  // namespace student_administration::student_management::infrastructure::persistence
