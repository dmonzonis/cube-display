#ifndef WINDOW_H
#define WINDOW_H

#include "ui_window.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private slots:
    // Using auto-connect naming conventions for uic
    void on_btnRotate_clicked();

private:
    Ui::Window ui;
};

#endif // WINDOW_H
