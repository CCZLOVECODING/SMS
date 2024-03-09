#ifndef CHPD_H
#define CHPD_H

#include <QWidget>

namespace Ui {
class chpd;
}

class chpd : public QWidget
{
    Q_OBJECT

public:
    explicit chpd(QWidget *parent = nullptr);
    ~chpd();

private slots:
    void on_btn_reg_clicked();

    void on_btn_quit_clicked();

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

private:
    Ui::chpd *ui;
};

#endif // CHPD_H
