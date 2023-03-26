#include "mainwindow.ih"

/**
 * @brief MainWindow::on_ResetScaleButton_clicked Resets the scale factor.
 * @param checked Unused.
 */
void MainWindow::on_ResetScaleButton_clicked(bool checked)
{
    Q_UNUSED(checked)
    ui->ScaleSlider->setValue(100);
    ui->mainView->setScale(1.0);
}