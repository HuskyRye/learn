#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void test();
    void readFile();
    void writeFile();

private slots:
    void on_actionnew_triggered();

    void on_actionutf_8_triggered();

    void on_actiongbk_triggered();

    void on_actionopen_triggered();

    void on_actionsaveas_triggered();

    void on_actionundo_triggered();

    void on_actioncopy_triggered();

    void on_actionpaste_triggered();

    void on_actioncut_triggered();

    void on_actioncompile_triggered();

    void on_actionexit_triggered();

    void on_actionsave_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
