#include "student_administration/student_management/presentation/qt/MainWindow.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QStatusBar>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

namespace student_administration::student_management::presentation::qt {

namespace {

QString toDisplayString(const application::dto::StudentView& student) {
    return QString("%1 | %2 | %3")
        .arg(QString::fromStdString(student.fullName))
        .arg(QString::fromStdString(student.email))
        .arg(QString::fromStdString(student.status));
}

}  // namespace

MainWindow::MainWindow(application::use_cases::RegisterStudentUseCase& registerStudentUseCase,
                       application::use_cases::ListStudentsUseCase& listStudentsUseCase,
                       QWidget* parent)
    : QMainWindow(parent),
      registerStudentUseCase_(registerStudentUseCase),
      listStudentsUseCase_(listStudentsUseCase) {
    buildLayout();
    wireEvents();
    refreshStudentList();
}

void MainWindow::buildLayout() {
    setWindowTitle("Student Administration");
    resize(840, 460);

    auto* centralWidget = new QWidget(this);
    auto* rootLayout = new QHBoxLayout(centralWidget);

    auto* formGroup = new QGroupBox("Register student", centralWidget);
    auto* formLayout = new QFormLayout(formGroup);

    fullNameEdit_ = new QLineEdit(formGroup);
    emailEdit_ = new QLineEdit(formGroup);
    addButton_ = new QPushButton("Register student", formGroup);
    fullNameEdit_->setObjectName("fullNameEdit");
    emailEdit_->setObjectName("emailEdit");
    addButton_->setObjectName("addStudentButton");

    formLayout->addRow("Full name", fullNameEdit_);
    formLayout->addRow("Email", emailEdit_);
    formLayout->addRow("", addButton_);

    auto* listGroup = new QGroupBox("Registered students", centralWidget);
    auto* listLayout = new QVBoxLayout(listGroup);

    auto* hint = new QLabel(
        "DDD learning setup:\n"
        "- student_management is the bounded context\n"
        "- domain owns model, value objects and repository contract\n"
        "- application orchestrates use cases and returns DTOs\n"
        "- infrastructure implements ports\n"
        "- Qt stays in the presentation adapter",
        listGroup);
    hint->setWordWrap(true);

    studentList_ = new QListWidget(listGroup);
    studentList_->setObjectName("studentList");

    listLayout->addWidget(hint);
    listLayout->addWidget(studentList_);

    rootLayout->addWidget(formGroup, 1);
    rootLayout->addWidget(listGroup, 2);

    setCentralWidget(centralWidget);
}

void MainWindow::wireEvents() {
    connect(addButton_, &QPushButton::clicked, this, &MainWindow::registerStudent);
}

void MainWindow::refreshStudentList() {
    studentList_->clear();

    for (const auto& student : listStudentsUseCase_.execute()) {
        studentList_->addItem(toDisplayString(student));
    }
}

void MainWindow::registerStudent() {
    try {
        const auto registeredStudent = registerStudentUseCase_.execute({
            .fullName = fullNameEdit_->text().toStdString(),
            .email = emailEdit_->text().toStdString(),
        });

        fullNameEdit_->clear();
        emailEdit_->clear();
        refreshStudentList();
        statusBar()->showMessage(
            QString("Registered %1").arg(QString::fromStdString(registeredStudent.fullName)),
            3000);
    } catch (const std::exception& exception) {
        QMessageBox::warning(this, "Registration failed", exception.what());
    }
}

}  // namespace student_administration::student_management::presentation::qt
