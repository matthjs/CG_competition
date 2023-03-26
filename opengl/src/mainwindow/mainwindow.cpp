#include "mainwindow.ih"

/**
 * @brief MainWindow::MainWindow Constructs a new main window.
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent)
:
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}