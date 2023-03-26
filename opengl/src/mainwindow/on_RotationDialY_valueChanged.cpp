#include "mainwindow.ih"

/**
 * @brief MainWindow::on_RotationDialY_sliderMoved Updates the number of degrees
 * of rotation in the y direction.
 * @param value Unused.
 */
void MainWindow::on_RotationDialY_valueChanged(int value)
{
    ui->mainView->setRotation(ui->RotationDialX->value(), value,
                              ui->RotationDialZ->value());
}