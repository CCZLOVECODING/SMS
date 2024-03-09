#include "inlog.h"
#include "ui_inlog.h"
#include "widget.h"
#include "regis.h"
#include "chpd.h"
#include "QString"
#include <QMessageBox>
#include "sqlserver.h"


SqlServer *sql=new SqlServer;
inlog::inlog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inlog)
{
    ui->setupUi(this);
    this->setWindowTitle("用户登录");
    ui->let_passwd->setEchoMode(QLineEdit::Password);
    ui->let_passwd->setPlaceholderText("密码");
    ui->let_name->setPlaceholderText("用户名");
}

inlog::~inlog()
{
    delete ui;
}

void inlog::on_btn_inlog_clicked()
{

    QString name=ui->let_name->text();
    QString password=ui->let_passwd->text();
    if(name==nullptr || password==nullptr)
    {
        QMessageBox::information(this,"登录","账号或密码输入为空\n请输入完整");

    }
    else if(sql->loginUser(name,password))
    {
        Widget *w=new Widget();
        w->show();
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "登录", "账号或密码输入错误\n请重新输入");
    }

}

void inlog::on_btn_reg_clicked()
{
    regis *w=new regis();
    w->show();
    this->hide();
}


void inlog::on_btn_quit_clicked()
{
    this->close();
}


void inlog::on_btn_alt_clicked()
{
    chpd *w=new chpd();
    w->show();
    this->hide();
}


void inlog::on_checkBox_clicked(bool checked)
{

    if(checked)
    {
        ui->let_passwd->setEchoMode(QLineEdit::Normal);

    }
    else
    {

        ui->let_passwd->setEchoMode(QLineEdit::Password);
    }
}








