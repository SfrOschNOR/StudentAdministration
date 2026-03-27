#include <QApplication>

#include "student_administration/student_management/application/use_cases/ListStudentsUseCase.h"
#include "student_administration/student_management/application/use_cases/RegisterStudentUseCase.h"
#include "student_administration/student_management/infrastructure/persistence/InMemoryStudentRepository.h"
#include "student_administration/student_management/presentation/qt/MainWindow.h"

int main(int argc, char* argv[]) {
    const QApplication app(argc, argv);

    using namespace student_administration::student_management;

    infrastructure::persistence::InMemoryStudentRepository repository;
    application::use_cases::RegisterStudentUseCase registerStudentUseCase(repository);
    application::use_cases::ListStudentsUseCase listStudentsUseCase(repository);

    presentation::qt::MainWindow window(registerStudentUseCase, listStudentsUseCase);
    window.show();

    return QApplication::exec();
}
