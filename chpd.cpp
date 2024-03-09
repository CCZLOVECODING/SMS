#include "chpd.h"
#include "ui_chpd.h"

#include "inlog.h"
#include "sqlserver.h"
chpd::chpd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chpd)
{
    ui->setupUi(this);
    ui->let_passwd1->setEchoMode(QLineEdit::Password);
    ui->let_passwd2->setEchoMode(QLineEdit::Password);
    ui->let_passwd3->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("修改密码");
}

chpd::~chpd()
{
    delete ui;
}

void chpd::on_btn_reg_clicked()
{

    SqlServer *sql=new SqlServer;
    QString name=ui->let_name->text();
    QString password1=ui->let_passwd1->text();
    QString password2=ui->let_passwd2->text();
    QString password3=ui->let_passwd3->text();
    int i=QString::compare(password2,password3);
    if(name==nullptr || password1==nullptr || password2==nullptr || password3==nullptr)
    {
        QMessageBox::information(this,"修改密码","请输入完整");
        delete sql;
        return;

    }
    else if(i)
    {
        QMessageBox::information(this,"修改密码","两次密码输入不同");
        delete sql;
        return;
    }
    else if(sql->loginUser(name,password1))
    {
        if(sql->chpd(name,password1,password2))
        {
            QMessageBox::information(this,"修改密码","修改成功");
            inlog *w=new inlog();
            w->show();
            this->hide();
            delete sql;
            return;
        }
        else
        {
            QMessageBox::critical(this,"修改密码","修改失败");

        }

    }
    else
    {
        QMessageBox::critical(this,"修改密码","修改失败,账号或密码输入错误");
        delete sql;
        return;
    }


}


void chpd::on_btn_quit_clicked()
{
    inlog *w=new inlog();
    w->show();
    this->hide();
}




void chpd::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        ui->let_passwd2->setEchoMode(QLineEdit::Normal);

    }
    else
    {
        ui->let_passwd2->setEchoMode(QLineEdit::Password);

    }
}


void chpd::on_checkBox_2_clicked(bool checked)
{
    if(checked)
    {
        ui->let_passwd1->setEchoMode(QLineEdit::Normal);

    }
    else
    {
        ui->let_passwd1->setEchoMode(QLineEdit::Password);

    }
}

