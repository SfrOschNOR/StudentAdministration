#include <gtest/gtest.h>

#include <stdexcept>

#include "student_administration/student_management/domain/model/Student.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"
#include "student_administration/student_management/domain/value_objects/StudentName.h"

namespace student_administration::student_management::domain {

TEST(StudentTests, RegisterNewCreatesActiveStudentWithGeneratedId) {
    const auto student = model::Student::registerNew(
        value_objects::StudentName("Ada Lovelace"), value_objects::EmailAddress("ada@example.com"));

    EXPECT_FALSE(student.id().value().empty());
    EXPECT_EQ(student.name().value(), "Ada Lovelace");
    EXPECT_EQ(student.email().value(), "ada@example.com");
    EXPECT_EQ(student.status(), model::EnrollmentStatus::Active);
}

TEST(StudentTests, StudentCanBeDeactivated) {
    auto student = model::Student::registerNew(value_objects::StudentName("Barbara Liskov"),
                                               value_objects::EmailAddress("barbara@example.com"));

    student.deactivate();

    EXPECT_EQ(student.status(), model::EnrollmentStatus::Inactive);
    EXPECT_FALSE(student.isActive());
}

TEST(StudentTests, EmptyNameIsRejected) {
    EXPECT_THROW(value_objects::StudentName("   "), std::invalid_argument);
}

TEST(StudentTests, InvalidEmailIsRejected) {
    EXPECT_THROW(value_objects::EmailAddress("invalid-email"), std::invalid_argument);
}

} // namespace student_administration::student_management::domain
