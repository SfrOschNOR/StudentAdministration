#pragma once

#include <vector>

// InfrastructureExport.h markiert die Public API des Infrastruktur-Moduls.
// Das ist vor allem dann noetig, wenn die Adapter als eigene DLL gebaut werden.
#include "InfrastructureExport.h"
#include "student_administration/student_management/domain/repositories/StudentRepository.h"

namespace student_administration::student_management::infrastructure::persistence {

class STUDENT_ADMINISTRATION_INFRASTRUCTURE_EXPORT InMemoryStudentRepository
    : public domain::repositories::StudentRepository {
public:
    void save(domain::model::Student student) override;
    [[nodiscard]] std::vector<domain::model::Student> findAll() const override;
    [[nodiscard]] bool existsByEmail(const domain::value_objects::EmailAddress& email) const override;

private:
    std::vector<domain::model::Student> students_;
};

}  // namespace student_administration::student_management::infrastructure::persistence
