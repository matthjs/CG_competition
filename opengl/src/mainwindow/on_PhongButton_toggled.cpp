#include "mainwindow.ih"

/**
 * @brief MainWindow::on_PhongButton_toggled Changes the shading mode to Phong
 * shading.
 * @param checked Unused.
 */
void MainWindow::on_PhongButton_toggled(bool checked)
{
    if (checked)
    {
        ui->mainView->setShadingMode(ShadingMode::PHONG);
        ui->mainView->update();
    }
}