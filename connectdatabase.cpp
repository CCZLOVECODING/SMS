#include "connectdatabase.h"
#include "ui_connectdatabase.h"
#include "inlog.h"
#include "sqlserver.h"
#include <QApplication>
#include "QString"
#include "jindutiao.h"
#include "widget.h"
connectdatabase::connectdatabase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::connectdatabase)
{
    ui->setupUi(this);
    this->setWindowTitle("连接数据库");
    ui->let_passwd->setEchoMode(QLineEdit::Password);
    //connect(ui->btn_connect,&on_btn_connect_clicked(),this,&connectdatabase::on_btn_connect_clicked());
}

connectdatabase::~connectdatabase()
{
    delete ui;
}

void connectdatabase::on_btn_connect_clicked()
{


//    SqlServer *sql=new SqlServer;
//    QString servername=ui->let_servername->text();
//    QString databasename=ui->let_databasename->text();
//    QString usename=ui->let_name->text();
//    QString password=ui->let_passwd->text();
//    this->hide();
//    jindutiao *h=new jindutiao();
//    h->show();
//    QMessageBox::information(this,"提示","连接中.......");
//    if(servername==nullptr || databasename==nullptr || usename==nullptr || password==nullptr)
//    {
//        QMessageBox::information(this,"连接数据库","请填写完整");
//        delete sql;
//    }
//    else
//    {
//        if(sql->initSql(servername,databasename,usename,password))
//        {
//            h->close();
//            inlog *w=new inlog();
//            w->show();
//            this->hide();
//            QMessageBox::information(this,"提示","数据库连接成功");
//            return;
//        }
//        else
//        {
//            h->close();
//            QMessageBox::critical(this,"提示","连接失败");
//            connectdatabase *w=new connectdatabase();
//            w->show();
//            return;
//        }
//    }




//直连数据库*********************************************************

    SqlServer *sql=new SqlServer;
    if(sql->initSql1())
    {
        QMessageBox::information(this,"提示","数据库连接成功");
        Widget *w=new Widget();
        w->show();
        this->hide();
        return;
    }
    else
    {
        QMessageBox::critical(this,"提示","连接失败");
        connectdatabase *w=new connectdatabase();
        w->show();
        return;
    }




//**********************************************************
}


void connectdatabase::on_btn_quit_clicked()
{
    this->close();

}

