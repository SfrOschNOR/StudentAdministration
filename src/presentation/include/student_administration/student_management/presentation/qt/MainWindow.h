#pragma once

#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>

// PresentationExport.h exportiert die Qt-UI-Typen des Presentation-Moduls.
// Ohne dieses Makro waere die Public API der DLL plattformabhaengig unvollstaendig.
#include "PresentationExport.h"
#include "student_administration/student_management/application/use_cases/ListStudentsUseCase.h"
#include "student_administration/student_management/application/use_cases/RegisterStudentUseCase.h"

namespace student_administration::student_management::presentation::qt {

class STUDENT_ADMINISTRATION_PRESENTATION_EXPORT MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(application::use_cases::RegisterStudentUseCase& registerStudentUseCase,
               application::use_cases::ListStudentsUseCase& listStudentsUseCase,
               QWidget* parent = nullptr);

private:
    void buildLayout();
    void wireEvents();
    void refreshStudentList();
    void registerStudent();

    application::use_cases::RegisterStudentUseCase& registerStudentUseCase_;
    application::use_cases::ListStudentsUseCase& listStudentsUseCase_;

    QLineEdit* fullNameEdit_{nullptr};
    QLineEdit* emailEdit_{nullptr};
    QListWidget* studentList_{nullptr};
    QPushButton* addButton_{nullptr};
};

}  // namespace student_administration::student_management::presentation::qt
