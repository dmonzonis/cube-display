#include "window.h"

#include <QMessageBox>

Window::Window()
    : QWidget(nullptr)
{
    ui.setupUi(this);
}

void Window::on_btnRotate_clicked()
{
    // Get info from the textboxes
    bool ok1, ok2, ok3;
    int xDeg = ui.txtX->text().toDouble(&ok1);
    int yDeg = ui.txtY->text().toDouble(&ok2);
    int zDeg = ui.txtZ->text().toDouble(&ok3);
    // If some data couldn't be converted to double, show error message and do nothing
    if (!(ok1 && ok2 && ok3))
    {
        QMessageBox errorMsg;
        errorMsg.critical(0, "Error", "Error with the format of the data.");
        errorMsg.setFixedSize(500, 200);
        return;
    }
    // Rotate the shape and repaint the widget
    ui.renderArea->rotateShape(xDeg, yDeg, zDeg);
    ui.renderArea->update();
}
