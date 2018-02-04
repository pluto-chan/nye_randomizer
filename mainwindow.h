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

private slots:
    void on_b1_clicked();

    void on_t_clicked();

    void on_roll_clicked();

    void on_ban_clicked();

    void on_ban_2_clicked();

    void on_ban_3_clicked();

    void on_ban_4_clicked();

    void on_ban_5_clicked();

    void on_ban_6_clicked();

    void on_ban_7_clicked();

    void on_ban_8_clicked();

    void on_ban_9_clicked();

    void on_ban_10_clicked();

    void on_ban_12_clicked();

    void on_ban_11_clicked();

    void on_t_6_clicked();

    void on_t_2_clicked();

    void on_t_3_clicked();

    void on_t_4_clicked();

    void on_t_5_clicked();

    void on_t_7_clicked();

    void on_t_8_clicked();

    void on_t_9_clicked();

    void on_t_10_clicked();

    void on_t_11_clicked();

    void on_t_12_clicked();

    void on_fuck_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
