#ifndef REGIS_H
#define REGIS_H

#include <QWidget>

namespace Ui {
class regis;
}

class regis : public QWidget
{
    Q_OBJECT

public:
    explicit regis(QWidget *parent = nullptr);
    ~regis();

private slots:
    void on_btn_reg_clicked();

    void on_btn_quit_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::regis *ui;
};

#endif // REGIS_H
