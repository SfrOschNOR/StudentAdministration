#pragma once

#include <vector>

#include "DomainExport.h"
#include "student_administration/student_management/domain/model/Student.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"

namespace student_administration::student_management::domain::repositories {

/**
 * @brief Domain repository port for storing and querying students.
 *
 * The domain depends on this abstraction rather than on concrete persistence
 * technology. Infrastructure adapters implement this interface.
 */
class STUDENT_ADMINISTRATION_DOMAIN_EXPORT StudentRepository {
    public:
    /**
     * @brief Virtual destructor for polymorphic deletion.
     */
    virtual ~StudentRepository() = default;

    /**
     * @brief Persists the given student aggregate.
     * @param student Student aggregate to store.
     */
    virtual void save(model::Student student) = 0;
    /**
     * @brief Returns every stored student aggregate.
     * @return Snapshot of all students known to the repository.
     */
    [[nodiscard]] virtual std::vector<model::Student> findAll() const = 0;
    /**
     * @brief Checks whether a student with the given email already exists.
     * @param email Email address to search for.
     * @return `true` if a matching student exists, otherwise `false`.
     */
    [[nodiscard]] virtual bool existsByEmail(const value_objects::EmailAddress& email) const = 0;
};

} // namespace student_administration::student_management::domain::repositories
