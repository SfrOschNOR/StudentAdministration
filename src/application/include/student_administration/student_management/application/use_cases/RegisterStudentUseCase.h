#pragma once

#include "ApplicationExport.h"
#include "student_administration/student_management/application/commands/RegisterStudentCommand.h"
#include "student_administration/student_management/application/dto/StudentView.h"
#include "student_administration/student_management/domain/repositories/StudentRepository.h"

namespace student_administration::student_management::application::use_cases {

/**
 * @brief Handles the application flow for registering a new student.
 *
 * The use case validates the incoming command by constructing domain value
 * objects, checks whether the email address is already in use, creates a new
 * student aggregate and persists it through the repository port.
 */
class STUDENT_ADMINISTRATION_APPLICATION_EXPORT RegisterStudentUseCase {
    public:
    /**
     * @brief Creates the use case with the repository port it should use.
     * @param repository Repository abstraction used for duplicate checks and persistence.
     */
    explicit RegisterStudentUseCase(domain::repositories::StudentRepository& repository);

    /**
     * @brief Registers a new student from the given command.
     * @param command Raw input data collected by the caller.
     * @return A DTO describing the newly registered student.
     * @throws std::invalid_argument If the command data cannot form valid domain value objects.
     * @throws domain::exceptions::StudentAlreadyRegistered If the email is already in use.
     */
    [[nodiscard]] dto::StudentView execute(const commands::RegisterStudentCommand& command) const;

    private:
    domain::repositories::StudentRepository& repository_;
};

} // namespace student_administration::student_management::application::use_cases
