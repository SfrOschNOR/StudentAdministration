#pragma once

#include <vector>

#include "DomainExport.h"
#include "student_administration/student_management/domain/model/Student.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"

namespace student_administration::student_management::domain::repositories {

class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentRepository {
    public:
    virtual ~StudentRepository() = default;

    virtual void save(model::Student student) = 0;
    [[nodiscard]] virtual std::vector<model::Student> findAll() const = 0;
    [[nodiscard]] virtual bool existsByEmail(const value_objects::EmailAddress& email) const = 0;
};

} // namespace student_administration::student_management::domain::repositories
