#pragma once

#include <vector>

#include "ApplicationExport.h"
#include "student_administration/student_management/application/dto/StudentView.h"
#include "student_administration/student_management/domain/repositories/StudentRepository.h"

namespace student_administration::student_management::application::use_cases {

/**
 * @brief Returns the students currently known to the system as presentation-ready DTOs.
 *
 * This use case sits in the application layer and translates domain entities
 * coming from the repository port into read models that a UI can render
 * without additional mapping.
 */
class STUDENT_ADMINISTRATION_APPLICATION_EXPORT ListStudentsUseCase {
    public:
    /**
     * @brief Creates the use case with the repository port it should query.
     * @param repository Repository abstraction used to read students.
     */
    explicit ListStudentsUseCase(const domain::repositories::StudentRepository& repository);

    /**
     * @brief Loads all students and maps them to application DTOs.
     * @return A list of students in a format suitable for presentation code.
     */
    [[nodiscard]] std::vector<dto::StudentView> execute() const;

    private:
    const domain::repositories::StudentRepository& repository_;
};

} // namespace student_administration::student_management::application::use_cases
