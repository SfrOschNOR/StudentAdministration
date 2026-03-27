#pragma once

#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>

#include "PresentationExport.h"
#include "student_administration/student_management/application/use_cases/ListStudentsUseCase.h"
#include "student_administration/student_management/application/use_cases/RegisterStudentUseCase.h"

namespace student_administration::student_management::presentation::qt {

/**
 * @brief Qt Widgets main window acting as an inbound adapter for the use cases.
 *
 * The window collects user input, delegates all business work to application
 * use cases and refreshes the visible list of registered students.
 */
class STUDENT_ADMINISTRATION_PRESENTATION_EXPORT MainWindow : public QMainWindow {
    Q_OBJECT

    public:
    /**
     * @brief Creates the main window and wires it to the application layer.
     * @param registerStudentUseCase Use case responsible for student registration.
     * @param listStudentsUseCase Use case used to populate the student list.
     * @param parent Optional Qt parent widget.
     */
    MainWindow(application::use_cases::RegisterStudentUseCase& registerStudentUseCase,
               application::use_cases::ListStudentsUseCase& listStudentsUseCase,
               QWidget* parent = nullptr);

    private:
    /**
     * @brief Builds the Qt widget tree and layout for the window.
     */
    void buildLayout();
    /**
     * @brief Connects UI signals to the window's actions.
     */
    void wireEvents();
    /**
     * @brief Reloads the list widget from the list-students use case.
     */
    void refreshStudentList();
    /**
     * @brief Reads the form, runs the registration use case and updates the UI.
     */
    void registerStudent();

    application::use_cases::RegisterStudentUseCase& registerStudentUseCase_;
    application::use_cases::ListStudentsUseCase& listStudentsUseCase_;

    QLineEdit* fullNameEdit_{nullptr};
    QLineEdit* emailEdit_{nullptr};
    QListWidget* studentList_{nullptr};
    QPushButton* addButton_{nullptr};
};

} // namespace student_administration::student_management::presentation::qt
