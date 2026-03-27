#pragma once

#include <vector>

#include "InfrastructureExport.h"
#include "student_administration/student_management/domain/repositories/StudentRepository.h"

namespace student_administration::student_management::infrastructure::persistence {

/**
 * @brief In-memory implementation of the student repository port.
 *
 * This adapter is useful for learning, demos and tests because it avoids any
 * external dependency while still exercising the same domain/application flow
 * as a real persistence adapter.
 */
class STUDENT_ADMINISTRATION_INFRASTRUCTURE_EXPORT InMemoryStudentRepository
    : public domain::repositories::StudentRepository {
    public:
    /**
     * @brief Stores a student in the in-memory collection.
     * @param student Aggregate instance to append.
     */
    void save(domain::model::Student student) override;
    /**
     * @brief Returns all currently stored students.
     * @return Copy of the in-memory student collection.
     */
    [[nodiscard]] std::vector<domain::model::Student> findAll() const override;
    /**
     * @brief Checks whether the repository already contains the given email address.
     * @param email Email address to compare against stored students.
     * @return `true` if a matching student exists, otherwise `false`.
     */
    [[nodiscard]] bool
    existsByEmail(const domain::value_objects::EmailAddress& email) const override;

    private:
    std::vector<domain::model::Student> students_;
};

} // namespace student_administration::student_management::infrastructure::persistence
