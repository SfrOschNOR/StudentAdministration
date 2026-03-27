#include <gtest/gtest.h>

#include "student_administration/student_management/domain/model/Student.h"
#include "student_administration/student_management/domain/value_objects/EmailAddress.h"
#include "student_administration/student_management/domain/value_objects/StudentName.h"
#include "student_administration/student_management/infrastructure/persistence/InMemoryStudentRepository.h"

namespace student_administration::student_management::infrastructure::persistence {

TEST(InMemoryStudentRepositoryTests, SaveMakesStudentVisibleViaFindAll) {
    InMemoryStudentRepository repository;

    repository.save(domain::model::Student::registerNew(
        domain::value_objects::StudentName("Katherine Johnson"),
        domain::value_objects::EmailAddress("katherine@example.com")));

    const auto students = repository.findAll();
    ASSERT_EQ(students.size(), 1U);
    EXPECT_EQ(students.front().name().value(), "Katherine Johnson");
}

TEST(InMemoryStudentRepositoryTests, ExistsByEmailReturnsTrueForStoredStudent) {
    InMemoryStudentRepository repository;
    const domain::value_objects::EmailAddress email("hedy@example.com");

    repository.save(domain::model::Student::registerNew(
        domain::value_objects::StudentName("Hedy Lamarr"), email));

    EXPECT_TRUE(repository.existsByEmail(email));
}

} // namespace student_administration::student_management::infrastructure::persistence
