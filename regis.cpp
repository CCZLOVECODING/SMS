#include "regis.h"
#include "ui_regis.h"
#include "inlog.h"
#include <QMessageBox>
#include "QString"
#include "sqlserver.h"


regis::regis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regis)
{
    ui->setupUi(this);
    this->setWindowTitle("添加用户");
    ui->let_passwd1->setEchoMode(QLineEdit::Password);
    ui->let_passwd2->setEchoMode(QLineEdit::Password);
}

regis::~regis()
{
    delete ui;
}

void regis::on_btn_reg_clicked()
{
    SqlServer *sql=new SqlServer;
    QString name=ui->let_name->text();
    QString password1=ui->let_passwd1->text();
    QString password2=ui->let_passwd2->text();
    int i=QString::compare(password1,password2);
    if(name==nullptr||password1==nullptr||password2==nullptr)
    {
        QMessageBox::information(this,"注册","注册失败，请输入完整");
        delete sql;
        return;
    }
    else if(i)
    {
        QMessageBox::information(this,"注册","注册失败，两次密码输入不同");
        delete sql;
        return;
    }
    else if(sql->registerUser(name,password1))
    {
        QMessageBox::information(this,"注册","注册成功");
        inlog *w=new inlog();
        w->show();
        this->hide();
        delete sql;
        return;

    }
    else
    {
        QMessageBox::critical(this,"注册","注册失败，账户已存在");
        delete sql;
        return;
    }
}


void regis::on_btn_quit_clicked()
{
    inlog *w=new inlog();
    w->show();
    this->hide();
}


void regis::on_checkBox_clicked(bool checked)
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

