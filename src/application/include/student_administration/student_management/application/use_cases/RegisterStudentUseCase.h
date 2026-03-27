#pragma once

// ApplicationExport.h enthaelt das von CMake erzeugte Export-Makro fuer die
// Application-DLL. So bleibt klar, welche Typen zur stabilen Modul-API gehoeren.
#include "ApplicationExport.h"
#include "student_administration/student_management/application/commands/RegisterStudentCommand.h"
#include "student_administration/student_management/application/dto/StudentView.h"
#include "student_administration/student_management/domain/repositories/StudentRepository.h"

namespace student_administration::student_management::application::use_cases {

class STUDENT_ADMINISTRATION_APPLICATION_EXPORT RegisterStudentUseCase {
public:
    explicit RegisterStudentUseCase(domain::repositories::StudentRepository& repository);

    [[nodiscard]] dto::StudentView execute(const commands::RegisterStudentCommand& command) const;

private:
    domain::repositories::StudentRepository& repository_;
};

}  // namespace student_administration::student_management::application::use_cases
