#include <gtest/gtest.h>

#include <QApplication>
#include <QByteArray>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QString>

#include <memory>

#include "student_administration/student_management/application/use_cases/ListStudentsUseCase.h"
#include "student_administration/student_management/application/use_cases/RegisterStudentUseCase.h"
#include "student_administration/student_management/infrastructure/persistence/InMemoryStudentRepository.h"
#include "student_administration/student_management/presentation/qt/MainWindow.h"

namespace student_administration::student_management::presentation::qt {

namespace {

class QApplicationEnvironment final : public ::testing::Environment {
    public:
    void SetUp() override {
        if (QApplication::instance() == nullptr) {
            qputenv("QT_QPA_PLATFORM", QByteArray("offscreen"));
            int argc = 1;
            argvData_[0] = const_cast<char*>(appName_);
            app_ = std::make_unique<QApplication>(argc, argvData_);
        }
    }

    private:
    const char* appName_ = "student-admin-tests";
    char* argvData_[1]{};
    std::unique_ptr<QApplication> app_;
};

const ::testing::Environment* const qtEnvironment =
    ::testing::AddGlobalTestEnvironment(new QApplicationEnvironment());

} // namespace

TEST(MainWindowTests, RegisteringStudentUpdatesListWidget) {
    infrastructure::persistence::InMemoryStudentRepository repository;
    application::use_cases::RegisterStudentUseCase registerStudentUseCase(repository);
    application::use_cases::ListStudentsUseCase listStudentsUseCase(repository);
    MainWindow window(registerStudentUseCase, listStudentsUseCase);

    auto* fullNameEdit = window.findChild<QLineEdit*>("fullNameEdit");
    auto* emailEdit = window.findChild<QLineEdit*>("emailEdit");
    auto* addButton = window.findChild<QPushButton*>("addStudentButton");
    auto* studentList = window.findChild<QListWidget*>("studentList");

    ASSERT_NE(fullNameEdit, nullptr);
    ASSERT_NE(emailEdit, nullptr);
    ASSERT_NE(addButton, nullptr);
    ASSERT_NE(studentList, nullptr);

    fullNameEdit->setText("Alan Turing");
    emailEdit->setText("alan@example.com");
    addButton->click();

    ASSERT_EQ(studentList->count(), 1);
    EXPECT_TRUE(studentList->item(0)->text().contains(QString("Alan Turing")));
}

} // namespace student_administration::student_management::presentation::qt
