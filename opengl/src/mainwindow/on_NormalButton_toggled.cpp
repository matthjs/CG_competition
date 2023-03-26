#include "mainwindow.ih"

/**
 * @brief MainWindow::on_NormalButton_toggled Changes the shading mode to Normal
 * shading.
 * @param checked Unused.
 */
void MainWindow::on_NormalButton_toggled(bool checked)
{
    if (checked)
    {
        ui->mainView->setShadingMode(ShadingMode::NORMAL);
        ui->mainView->update();
    }
}