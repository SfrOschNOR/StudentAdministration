#include <gtest/gtest.h>

#include <vector>

#include "student_administration/student_management/application/use_cases/ListStudentsUseCase.h"
#include "student_administration/student_management/application/use_cases/RegisterStudentUseCase.h"
#include "student_administration/student_management/domain/exceptions/StudentAlreadyRegistered.h"

namespace student_administration::student_management::application {

namespace {

class RecordingStudentRepository final : public domain::repositories::StudentRepository {
    public:
    void save(domain::model::Student student) override {
        students.push_back(std::move(student));
    }

    [[nodiscard]] std::vector<domain::model::Student> findAll() const override {
        return students;
    }

    [[nodiscard]] bool
    existsByEmail(const domain::value_objects::EmailAddress& email) const override {
        for (const auto& student : students) {
            if (student.email().value() == email.value()) {
                return true;
            }
        }
        return false;
    }

    std::vector<domain::model::Student> students;
};

} // namespace

TEST(RegisterStudentUseCaseTests, ExecuteStoresAndReturnsStudentView) {
    RecordingStudentRepository repository;
    use_cases::RegisterStudentUseCase registerStudentUseCase(repository);
    use_cases::ListStudentsUseCase listStudentsUseCase(repository);

    const auto registeredStudent = registerStudentUseCase.execute({
        .fullName = "Grace Hopper",
        .email = "grace@example.com",
    });

    const auto students = listStudentsUseCase.execute();
    ASSERT_EQ(students.size(), 1U);
    EXPECT_EQ(registeredStudent.fullName, "Grace Hopper");
    EXPECT_EQ(students.front().email, "grace@example.com");
    EXPECT_EQ(students.front().status, "active");
}

TEST(RegisterStudentUseCaseTests, ExecuteRejectsDuplicateEmailAddress) {
    RecordingStudentRepository repository;
    use_cases::RegisterStudentUseCase registerStudentUseCase(repository);

    ASSERT_NO_THROW(static_cast<void>(registerStudentUseCase.execute({
        .fullName = "First Student",
        .email = "duplicate@example.com",
    })));

    EXPECT_THROW(registerStudentUseCase.execute({
                     .fullName = "Second Student",
                     .email = "duplicate@example.com",
                 }),
                 domain::exceptions::StudentAlreadyRegistered);
}

TEST(RegisterStudentUseCaseTests, ExecutePropagatesValueObjectValidation) {
    RecordingStudentRepository repository;
    use_cases::RegisterStudentUseCase registerStudentUseCase(repository);

    EXPECT_THROW(registerStudentUseCase.execute({
                     .fullName = "",
                     .email = "broken@example.com",
                 }),
                 std::invalid_argument);
}

} // namespace student_administration::student_management::application
