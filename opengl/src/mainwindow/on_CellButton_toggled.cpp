#include "mainwindow.ih"

/**
 * @brief MainWindow::on_GouraudButton_toggled Changes the shading mode to
 * Gouraud shading.
 * @param checked Unused.
 */
void MainWindow::on_CellButton_toggled(bool checked)
{
    if (checked)
    {
        ui->mainView->setShadingMode(ShadingMode::CELL);
        ui->mainView->update();
    }
}
