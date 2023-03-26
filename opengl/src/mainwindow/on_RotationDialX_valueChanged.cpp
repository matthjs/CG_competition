#include "mainwindow.ih"

/**
 * @brief MainWindow::on_RotationDialX_sliderMoved Updates the number of degrees
 * of rotation in the x direction.
 * @param value Unused.
 */
void MainWindow::on_RotationDialX_valueChanged(int value)
{
    ui->mainView->setRotation(value, ui->RotationDialY->value(),
                              ui->RotationDialZ->value());
}