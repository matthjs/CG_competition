#include "mainwindow.ih"

/**
 * @brief MainWindow::on_ScaleSlider_sliderMoved Updates the scale value.
 * @param value The new scale value.
 */
void MainWindow::on_ScaleSlider_valueChanged(int value)
{
    ui->mainView->setScale(value / 100.0);
}