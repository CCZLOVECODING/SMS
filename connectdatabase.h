#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H

#include <QWidget>

namespace Ui {
class connectdatabase;
}

class connectdatabase : public QWidget
{
    Q_OBJECT

public:
    explicit connectdatabase(QWidget *parent = nullptr);
    ~connectdatabase();

private slots:
    void on_btn_connect_clicked();

    void on_btn_quit_clicked();

private:
    Ui::connectdatabase *ui;
};

#endif // CONNECTDATABASE_H
