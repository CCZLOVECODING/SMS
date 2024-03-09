#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);    
    ~Widget();

private slots:
    void onitemclicked(QTableWidgetItem * item);
    void onitemclickedcsb(QTableWidgetItem * item);
    void on_pushButton_clicked();

    void on_btn_addw_clicked();

    void on_btn_clearw_clicked();

    void on_btn_clearmfr_clicked();

    void on_btn_addmfr_clicked();

    void on_btn_addw_2_clicked();

    void on_btn_clearw_2_clicked();

    void on_btn_addw_3_clicked();

    void on_btn_clearw_3_clicked();

    void on_btn_day_clicked();

    void on_btn_moon_clicked();

    void on_btn_bn_clicked();

    void on_btn_yn_clicked();

    void on_btn_day_2_clicked();

    void on_btn_moon_2_clicked();

    void on_btn_bn_2_clicked();

    void on_btn_yn_2_clicked();

    void on_btn_ygyj_clicked();

    void on_btn_syygyj_clicked();

    void on_btn_jhbcx_clicked();

    void on_btn_jhbclear_clicked();

    void on_btn_xsbcx_clicked();

    void on_btn_xsbclear_clicked();

    void on_btn_thbcx_clicked();

    void on_btn_thbclear_clicked();

    void on_btn_ygbcx_clicked();

    void on_btn_ygbclear_clicked();

    void on_btn_ygbtj_clicked();

    void on_btn_csbtj_clicked();

    void on_btn_csbclear_clicked();

    void on_checkBox_clicked(bool checked);

    void on_btn_ygbxg_clicked();

    void on_check_ygbtj_clicked(bool checked);

    void on_btn_csbcx_clicked();

    void on_btn_csbxg_clicked();

    void on_check_csbbj_clicked(bool checked);

    void on_check_csbtj_clicked(bool checked);

    void on_btn_kcbcx_clicked();

    void on_btn_kcbclear_clicked();

    void on_btn_yjckclear_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
