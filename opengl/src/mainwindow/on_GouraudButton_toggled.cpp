#include "mainwindow.ih"

/**
 * @brief MainWindow::on_GouraudButton_toggled Changes the shading mode to
 * Gouraud shading.
 * @param checked Unused.
 */
void MainWindow::on_GouraudButton_toggled(bool checked)
{
    if (checked)
    {
        ui->mainView->setShadingMode(ShadingMode::GOURAUD);
        ui->mainView->update();
    }
}