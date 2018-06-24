#ifndef WINDOW_H
#define WINDOW_H

#include "ui_window.h"

/**
 * @brief Main window of the program.
 *
 * Contains all the GUI elements to interact with the program and visualize the results.
 */
class Window : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Default constructor. Sets up the UI given by the corresponding form.
     */
    Window();

private slots:
    // Using auto-connect naming conventions for uic
    void on_btnRotate_clicked();
    void on_btnScale_clicked();

private:
    void showErrorMessage(char *msg) const;

private:
    Ui::Window ui;
};

#endif // WINDOW_H
