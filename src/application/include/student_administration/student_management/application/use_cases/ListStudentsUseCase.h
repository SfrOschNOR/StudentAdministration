#pragma once

#include <vector>

#include "ApplicationExport.h"
#include "student_administration/student_management/application/dto/StudentView.h"
#include "student_administration/student_management/domain/repositories/StudentRepository.h"

namespace student_administration::student_management::application::use_cases {

class STUDENT_ADMINISTRATION_APPLICATION_EXPORT ListStudentsUseCase {
public:
    explicit ListStudentsUseCase(const domain::repositories::StudentRepository& repository);

    [[nodiscard]] std::vector<dto::StudentView> execute() const;

private:
    const domain::repositories::StudentRepository& repository_;
};

}  // namespace student_administration::student_management::application::use_cases
