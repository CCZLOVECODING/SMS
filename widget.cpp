#include "widget.h"
#include "ui_widget.h"
#include "inlog.h"
#include "QString"
#include "sqlserver.h"
#include "QMessageBox"
#include "QMenuBar"
#include "QSqlQuery"
#include "QDateTime"
#include "QTableWidget"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("销售管理系统");
    ui->let_bh->setPlaceholderText("编号自动填写");
    ui->let_cs_2->setPlaceholderText("需已登记");;
    ui->let_ywybh_2->setPlaceholderText("需已登记");
    ui->let_cs->setPlaceholderText("需已登记");;
    ui->let_ywybh->setPlaceholderText("需已登记");
    ui->let_cs_3->setPlaceholderText("需已登记");;
    ui->let_ywybh_3->setPlaceholderText("需已登记");
    ui->let_year->setPlaceholderText("可自动填写");
    ui->let_year_2->setPlaceholderText("可自动填写");
    ui->let_year_3->setPlaceholderText("可自动填写");
    ui->let_csbcsbh->setPlaceholderText("添加时编号自动填写");
//    QMenuBar *bar=new QMenuBar(this);
//    QMenu *filemenu=bar->addMenu("文件");
//    QMenu *filemenu1=bar->addMenu("编辑");
//    QMenu *filemenu2=bar->addMenu("帮助");

//库存表
    ui->tw_kcb->setColumnCount(8);
    QStringList hltkcb;
    hltkcb <<"库存编号";
    hltkcb <<"生产厂商";
    hltkcb <<"商品名称";
    hltkcb <<"型号";
    hltkcb <<"数量";
    hltkcb <<"修改年";
    hltkcb <<"修改月";
    hltkcb <<"修改日";
    ui->tw_kcb->setHorizontalHeaderLabels(hltkcb);
    ui->tw_kcb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


//进货统计表
    ui->tw_hw->setColumnCount(11);
    QStringList hlthw;
    hlthw <<"进货编号";
    hlthw <<"生产厂商";
    hlthw <<"商品名";
    hlthw <<"型号";
    hlthw <<"单价";
    hlthw <<"数量";
    hlthw <<"总金额";
    hlthw <<"进货年";
    hlthw <<"进货月";
    hlthw <<"进货日";
    hlthw <<"业务员编号";
    ui->tw_hw->setHorizontalHeaderLabels(hlthw);
    ui->tw_hw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_cs->setColumnCount(5);
    QStringList hltcs;
    hltcs <<"生产厂商"; 
    hltcs <<"进货年";
    hltcs <<"进货月";
    hltcs <<"进货日";
    hltcs <<"总金额";
    ui->tw_cs->setHorizontalHeaderLabels(hltcs);
    ui->tw_cs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
 //销售统计表
    ui->tw_hw_2->setColumnCount(11);
    QStringList hlthw1;
    hlthw1 <<"销售编号";
    hlthw1 <<"生产厂商";
    hlthw1 <<"商品名";
    hlthw1 <<"型号";
    hlthw1 <<"单价";
    hlthw1 <<"数量";
    hlthw1 <<"总金额";
    hlthw1 <<"销售年";
    hlthw1 <<"销售月";
    hlthw1 <<"销售日";
    hlthw1 <<"业务员编号";
    ui->tw_hw_2->setHorizontalHeaderLabels(hlthw1);
    ui->tw_hw_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_cs_2->setColumnCount(2);
    QStringList hltcs1;
    hltcs1 <<"生产厂商";
    hltcs1 <<"总金额";
    ui->tw_cs_2->setHorizontalHeaderLabels(hltcs1);
    ui->tw_cs_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//员工业绩表
    ui->tw_ygyj->setColumnCount(3);
    QStringList ygyj;
    ygyj <<"员工编号";
    ygyj <<"员工姓名";
    ygyj <<"总销售额";
    ui->tw_ygyj->setHorizontalHeaderLabels(ygyj);
    ui->tw_ygyj->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//进货信息表
    ui->tw_jhb->setColumnCount(11);
    QStringList hltjhb;
    hltjhb <<"商品编号";
    hltjhb <<"生产厂商";
    hltjhb <<"商品名";
    hltjhb <<"型号";
    hltjhb <<"单价";
    hltjhb <<"数量";
    hltjhb <<"总金额";
    hltjhb <<"进货年";
    hltjhb <<"进货月";
    hltjhb <<"进货日";
    hltjhb <<"业务员编号";
    ui->tw_jhb->setHorizontalHeaderLabels(hltjhb);
    ui->tw_jhb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//销售信息表
    ui->tw_xsb->setColumnCount(11);
    QStringList hltxsb;
    hltxsb <<"销售编号";
    hltxsb <<"生产厂商";
    hltxsb <<"商品名";
    hltxsb <<"型号";
    hltxsb <<"单价";
    hltxsb <<"数量";
    hltxsb <<"总金额";
    hltxsb <<"销售年";
    hltxsb <<"销售月";
    hltxsb <<"销售日";
    hltxsb <<"业务员编号";
    ui->tw_xsb->setHorizontalHeaderLabels(hltxsb);
    ui->tw_xsb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//退货信息表
    ui->tw_thb->setColumnCount(11);
    QStringList hltthb;
    hltthb <<"退货编号";
    hltthb <<"生产厂商";
    hltthb <<"商品名";
    hltthb <<"型号";
    hltthb <<"单价";
    hltthb <<"数量";
    hltthb <<"总金额";
    hltthb <<"退货年";
    hltthb <<"退货月";
    hltthb <<"退货日";
    hltthb <<"业务员编号";
    ui->tw_thb->setHorizontalHeaderLabels(hltthb);
    ui->tw_thb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//员工信息表
    ui->tw_ygb->setColumnCount(4);
    QStringList hltygb;
    hltygb <<"员工编号";
    hltygb <<"员工姓名";
    hltygb <<"联系电话";
    hltygb <<"员工地址";

    ui->tw_ygb->setHorizontalHeaderLabels(hltygb);
    ui->tw_ygb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

//厂商信息表
    ui->tw_csb->setColumnCount(5);
    QStringList hltcsb;
    hltcsb <<"厂商编号";
    hltcsb <<"厂商名称";
    hltcsb <<"法人代表";
    hltcsb <<"联系电话";
    hltcsb <<"厂商地址";
    ui->tw_csb->setHorizontalHeaderLabels(hltcsb);
    ui->tw_csb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    //表格设置


    ui->tw_hw->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_hw->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_hw->setAlternatingRowColors(true);

    ui->tw_cs->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_cs->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_cs->setAlternatingRowColors(true);

    ui->tw_hw_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_hw_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_hw_2->setAlternatingRowColors(true);

    ui->tw_cs_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_cs_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_cs_2->setAlternatingRowColors(true);

    ui->tw_ygyj->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_ygyj->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_ygyj->setAlternatingRowColors(true);

    ui->tw_jhb->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_jhb->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_jhb->setAlternatingRowColors(true);

    ui->tw_xsb->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_xsb->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_xsb->setAlternatingRowColors(true);

    ui->tw_thb->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_thb->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_thb->setAlternatingRowColors(true);

    ui->tw_ygb->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_ygb->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_ygb->setAlternatingRowColors(true);

    ui->tw_csb->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tw_csb->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_csb->setAlternatingRowColors(true);
}

Widget::~Widget()
{
    delete ui;
}


//    11111111111111111111111111111111111111111111


void Widget::onitemclicked(QTableWidgetItem *item)
{
    int row=item->row();
    QString ygbh=ui->tw_ygb->item(row,0)->text();
    QString ygxm=ui->tw_ygb->item(row,1)->text();
    QString lxdh=ui->tw_ygb->item(row,2)->text();
    QString ygdz=ui->tw_ygb->item(row,3)->text();

    ui->let_ygbygbh->setText(ygbh);
    ui->let_ygbygxm->setText(ygxm);
    ui->let_ygblxdh->setText(lxdh);
    ui->let_ygbygdz->setText(ygdz);
}

void Widget::onitemclickedcsb(QTableWidgetItem *item)
{

    int row=item->row();
    QString csbh=ui->tw_csb->item(row,0)->text();
    QString csmc=ui->tw_csb->item(row,1)->text();
    QString frdb=ui->tw_csb->item(row,2)->text();
    QString lxdh=ui->tw_csb->item(row,3)->text();
    QString csdz=ui->tw_csb->item(row,4)->text();

    ui->let_csbcsbh->setText(csbh);
    ui->let_csbcsmc->setText(csmc);
    ui->let_csbfrdb->setText(frdb);
    ui->let_csblxdh->setText(lxdh);
    ui->let_csbcsdz->setText(csdz);
}

void Widget::on_pushButton_clicked()
{
    inlog *w=new inlog();
    w->show();
    this->hide();
}

//	商品编号 int identity(1,1) primary key not null,
//	生产厂商 nvarchar(20) collate chinese_prc_ci_as null,
//	商品名 nvarchar(20) collate chinese_prc_ci_as null,
//	型号 nvarchar(20) collate chinese_prc_ci_as null,
//	单价 money null constraint[DF_goods_单价] default(0),
//	数量 numeric(10,0) null constraint[DF_goods_数量] default(0),
//	总金额 money null,
//	进货年 smallint null constraint[DF_goods_进货年] default(datepart(year,getdate())),
//	进货月 smallint null constraint[DF_goods_进货月] default(datepart(month,getdate())),
//	进货日 smallint null constraint[DF_goods_进货日] default(datepart(day,getdate())),
//	业务员编号 int not null,
void Widget::on_btn_addw_clicked()
{


    QString mc=ui->let_mc->text();
    QString cs=ui->let_cs->text();
    QString xh=ui->let_xh->text();
    QString dj=ui->let_dj->text();
    QString sl=ui->let_sl->text();
    QString year=ui->let_year->text();
    QString moon=ui->let_moon->text();
    QString day=ui->let_day->text();
    QString ywybh=ui->let_ywybh->text();
    QString zje=ui->let_zje->text();

    if(mc==nullptr||cs==nullptr|| xh==nullptr|| dj==nullptr || sl==nullptr || ywybh==nullptr || zje==nullptr)
    {
        QMessageBox::information(this,"进货登记","必填项未填写完整");
    }
    else
    {
        if(year==nullptr && moon==nullptr && day==nullptr)
        {
            int ok=QMessageBox::question(this,"进货登记","确认登记");
            if(ok)
            {

                QDateTime datetime = QDateTime::currentDateTime();
                year=QString("%1").arg(datetime.date().year());
                moon=QString("%1").arg(datetime.date().month());
                day=QString("%1").arg(datetime.date().day());
                SqlServer *sql=new SqlServer();
                if(sql->insertStock(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh) && sql->jhinsertstock(cs,mc,xh,sl,year,moon,day))
                {
                    QMessageBox::information(this,"进货登记","登记成功");
                }
                else
                {
                    QMessageBox::critical(this,"进货登记","登记失败");
                }
            }
            else
            {}
        }
        else if((!ui->let_year->text().isEmpty())&&(!ui->let_moon->text().isEmpty())&&(!ui->let_day->text().isEmpty()))
        {
            int ok=QMessageBox::question(this,"进货登记","确认登记");
            if(ok)
            {
                SqlServer *sql=new SqlServer();
                if(sql->insertStock(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh) && sql->jhinsertstock(cs,mc,xh,sl,year,moon,day))
                {
                    QMessageBox::information(this,"进货登记","登记成功");
                }
                else
                {
                    QMessageBox::critical(this,"进货登记","登记失败");
                }
            }
        }
        else
        {
            QMessageBox::information(this,"进货登记","日期请填写完整");
        }
    }

}
void Widget::on_btn_clearw_clicked()
{
    ui->let_bh->clear();
    ui->let_cs->clear();
    ui->let_day->clear();
    ui->let_xh->clear();
    ui->let_dj->clear();
    ui->let_sl->clear();
    ui->let_year->clear();
    ui->let_moon->clear();
    ui->let_ywybh->clear();
    ui->let_zje->clear();
    ui->let_mc->clear();
    return;
}


void Widget::on_btn_clearmfr_clicked()
{
    ui->let_mfradd->clear();
    ui->let_mfrname->clear();
    ui->let_faren->clear();
    ui->let_number->clear();
    return;
}


void Widget::on_btn_addmfr_clicked()
{
    QString mfrname=ui->let_mfrname->text();
    QString farname=ui->let_faren->text();
    QString number=ui->let_number->text();
    QString mfradd=ui->let_mfradd->text();
    SqlServer *sql=new SqlServer();
    if(mfrname==nullptr || farname==nullptr || number==nullptr || mfradd==nullptr )
    {
        QMessageBox::information(this,"厂商登记","请填写完整");
        delete sql;
    }
    else
    {
        int ok=QMessageBox::question(this,"厂商登记","确认登记");
        if(ok)
        {
            if(sql->insertmfr(mfrname,farname,number,mfradd))
            {
                QMessageBox::information(this,"厂商登记","登记成功");
            }
            else
            {
                QMessageBox::critical(this,"进货登记","登记失败");
            }

        }
        delete sql;
    }
}

void Widget::on_btn_addw_2_clicked()
{
    QString cs=ui->let_cs_2->text();
    QString mc=ui->let_mc_2->text();
    QString xh=ui->let_xh_2->text();
    QString dj=ui->let_dj_2->text();
    QString sl=ui->let_sl_2->text();
    QString zje=ui->let_zje_2->text();
    QString year=ui->let_year_2->text();
    QString moon=ui->let_moon_2->text();
    QString day=ui->let_day_2->text();
    QString ywybh=ui->let_ywybh_2->text();


    if(cs==nullptr||mc==nullptr||zje==nullptr||ywybh==nullptr)
    {
        QMessageBox::information(this,"销售登记","请填写完整");
    }
    else
    {
        if(year==nullptr && moon==nullptr && day==nullptr)
        {

            int ok=QMessageBox::question(this,"销售登记","确认登记");
            if(ok)
            {
                QDateTime datetime = QDateTime::currentDateTime();
                year=QString("%1").arg(datetime.date().year());
                moon=QString("%1").arg(datetime.date().month());
                day=QString("%1").arg(datetime.date().day());
                SqlServer *sql=new SqlServer();
                QString sql1=QString("select * from stock where 生产厂商='%1' and 商品名='%2' and 型号='%3'").arg(cs,mc,xh);
                QSqlQuery *query1=new QSqlQuery;
                if(query1->exec(sql1))
                {
                    if(query1->first())
                    {
                        int sl1=query1->value("数量").toInt();
                        int sl2=sl.toInt();
                        if(sl1>=sl2)
                        {
                            QSqlQuery *query2=new QSqlQuery;

                            sl1=sl1-sl2;
                            QString sl3=QString("%1").arg(sl1);
                            //QMessageBox::information(this,"",sl3);

                            QString sql2=QString("update stock set 数量='%1',修改年='%2',修改月='%3',修改日='%4' where 生产厂商= '%5' and 商品名 = '%6' and 型号='%7'").arg(sl3,year,moon,day,cs,mc,xh);
                            query2->exec(sql2);

                            if(sql->insertsell(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh))
                            {
                                QMessageBox::information(this,"销售登记","登记成功");
                            }
                            else
                            {
                                QMessageBox::critical(this,"销售登记","登记失败");
                            }
                        }
                        else
                        {
                            QMessageBox::information(this,"销售登记","登记失败，商品库存不足");
                            delete sql;
                        }
                    }
                    else
                    {
                        QMessageBox::information(this,"销售登记","登记失败，暂无此商品信息");
                        delete sql;

                    }
                }
                else
                {
                    QMessageBox::critical(this,"销售登记","登记失败");
                    delete sql;
                }
            }
            else
            {}
        }
        else if((!ui->let_year_2->text().isEmpty())&&(!ui->let_moon_2->text().isEmpty())&&(!ui->let_day_2->text().isEmpty()))
        {
            int ok=QMessageBox::question(this,"销售登记","确认登记");
            if(ok)
            {
                SqlServer *sql=new SqlServer();
                QString sql1=QString("select * from stock where 生产厂商='%1' and 商品名='%2' and 型号='%3'").arg(cs,mc,xh);
                QSqlQuery *query1=new QSqlQuery;
                if(query1->exec(sql1))
                {
                    if(query1->first())
                    {
                        int sl1=query1->value("数量").toInt();
                        int sl2=sl.toInt();
                        if(sl1>=sl2)
                        {

                            QSqlQuery *query2=new QSqlQuery;
                            int sl1=sl.toInt();
                            int sl2=query1->value("数量").toInt();
                            sl1=sl1-sl2;
                            QString sl3=QString("%1").arg(sl1);
                            QString sql2=QString("update stock set 数量='%1',修改年='%2',修改月='%3',修改日='%4' where 生产厂商= '%5' and 商品名 = '%6' and 型号='%7'").arg(sl3,year,moon,day,cs,mc,xh);
                            query2->exec(sql2);

                            if(sql->insertsell(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh))
                            {
                                QMessageBox::information(this,"销售登记","登记成功");
                            }
                            else
                            {
                                QMessageBox::critical(this,"销售登记","登记失败");
                            }
                        }
                        else
                        {
                            QMessageBox::information(this,"销售登记","登记失败，商品库存不足");
                            delete sql;
                        }
                    }
                    else
                    {
                        QMessageBox::information(this,"销售登记","登记失败，暂无此商品信息");
                        delete sql;
                    }
                }
                else
                {
                    QMessageBox::critical(this,"销售登记","登记失败");
                    delete sql;
                }
            }
        }
        else
        {
            QMessageBox::information(this,"销售登记","日期请填写完整");
        }
    }
}

void Widget::on_btn_clearw_2_clicked()
{

    ui->let_bh_2->clear();
    ui->let_cs_2->clear();
    ui->let_day_2->clear();
    ui->let_xh_2->clear();
    ui->let_dj_2->clear();
    ui->let_sl_2->clear();
    ui->let_year_2->clear();
    ui->let_moon_2->clear();
    ui->let_ywybh_2->clear();
    ui->let_zje_2->clear();
    ui->let_mc_2->clear();
    return;
}

void Widget::on_btn_addw_3_clicked()
{

    QString cs=ui->let_cs_3->text();
    QString mc=ui->let_mc_3->text();
    QString xh=ui->let_xh_3->text();
    QString dj=ui->let_dj_3->text();
    QString sl=ui->let_sl_3->text();
    QString zje=ui->let_zje_3->text();
    QString year=ui->let_year_3->text();
    QString moon=ui->let_moon_3->text();
    QString day=ui->let_day_3->text();
    QString ywybh=ui->let_ywybh_3->text();
    //SqlServer *sql=new SqlServer();
    if(cs==nullptr||mc==nullptr||zje==nullptr||ywybh==nullptr)
    {
        QMessageBox::information(this,"退货登记","请填写完整");

    }
    else
    {
        if(year==nullptr && moon==nullptr && day==nullptr)
        {

            int ok=QMessageBox::question(this,"退货登记","确认登记");
            if(ok)
            {
                QDateTime datetime = QDateTime::currentDateTime();
                year=QString("%1").arg(datetime.date().year());
                moon=QString("%1").arg(datetime.date().month());
                day=QString("%1").arg(datetime.date().day());
                //                QMessageBox::information(this,"",year);
                //                QMessageBox::information(this,"",moon);
                //                QMessageBox::information(this,"",day);
                SqlServer *sql=new SqlServer();
                if(sql->retreat(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh))
                {
                    QMessageBox::information(this,"退货登记","登记成功");
                }
                else
                {
                    QMessageBox::critical(this,"退货登记","登记失败");
                }
            }
            else
            {}
        }
        else if((!ui->let_year_3->text().isEmpty())&&(!ui->let_moon_3->text().isEmpty())&&(!ui->let_day_3->text().isEmpty()))
        {
            int ok=QMessageBox::question(this,"退货登记","确认登记");
            if(ok)
            {
                SqlServer *sql=new SqlServer();
                if(sql->retreat(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh))
                {
                    QMessageBox::information(this,"退货登记","登记成功");
                }
                else
                {
                    QMessageBox::critical(this,"退货登记","登记失败");
                }
            }
        }
        else
        {
            QMessageBox::information(this,"退货登记","日期请填写完整");
        }
    }
}


void Widget::on_btn_clearw_3_clicked()
{
    ui->let_bh_3->clear();
    ui->let_cs_3->clear();
    ui->let_day_3->clear();
    ui->let_xh_3->clear();
    ui->let_dj_3->clear();
    ui->let_sl_3->clear();
    ui->let_year_3->clear();
    ui->let_moon_3->clear();
    ui->let_ywybh_3->clear();
    ui->let_zje_3->clear();
    ui->let_mc_3->clear();
    return;
}
//进货统计表***********************************************************************************************

void Widget::on_btn_day_clicked()
{
    ui->tw_hw->setRowCount(0);
    ui->tw_cs->setRowCount(0);
    QSqlQuery query;
    QString sql1="select * from goods where 进货年=datepart(year,getdate()) and 进货月=datepart(month,getdate()) and 进货日=datepart(day,getdate()) order by 生产厂商,总金额";
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
            query.last();
            QString bhlast=query.value("商品编号").toString();
            query.first();
            query.previous();
            int endzje1=0;
            int endzje2=0;
            int csbzje1=0;
            //QMessageBox::information(this,"",sccsstock);

            while (query.next())
            {
                int count=ui->tw_hw->rowCount();

                ui->tw_hw->setRowCount(count+1);


                spbh1=query.value("商品编号").toString();
                sccs1=query.value("生产厂商").toString();
                spm1=query.value("商品名").toString();
                xh1=query.value("型号").toString();
                dj1=query.value("单价").toString();
                sl1=query.value("数量").toString();
                year1=query.value("进货年").toString();
                moon1=query.value("进货月").toString();
                day1=query.value("进货日").toString();
                ywybh1=query.value("业务员编号").toString();
                zje1=query.value("总金额").toString();
                endzje1=query.value("总金额").toInt();
                endzje2+=endzje1;

                QTableWidgetItem *zje=new QTableWidgetItem(zje1);
                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);

                ui->tw_hw->setItem(count,0,spbh);
                ui->tw_hw->setItem(count,1,sccs);
                ui->tw_hw->setItem(count,2,spm);
                ui->tw_hw->setItem(count,3,xh);
                ui->tw_hw->setItem(count,4,dj);
                ui->tw_hw->setItem(count,5,sl);
                ui->tw_hw->setItem(count,6,zje);
                ui->tw_hw->setItem(count,7,year);
                ui->tw_hw->setItem(count,8,moon);
                ui->tw_hw->setItem(count,9,day);
                ui->tw_hw->setItem(count,10,ywybh);


                //**************************************************************************


                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=endzje1;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=endzje1;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=0;
                    sccsstock=sccs1;

                }

                //***********************************************************************************


            }
            QString endzje3=QString("%1").arg(endzje2);
            ui->let_jhzje->setText(endzje3);
        }
        else
        {
            QMessageBox::information(this,"进货统计","今日暂未进货");

        }
    }
    else
    {
        QMessageBox::critical(this,"进货统计","进货数据获取失败");
    }

}
void Widget::on_btn_moon_clicked()
{

    ui->tw_hw->setRowCount(0);
    ui->tw_cs->setRowCount(0);
    QSqlQuery query;
    QString sql1="select * from goods where 进货年=datepart(year,getdate()) and 进货月=datepart(month,getdate()) order by 生产厂商,总金额";
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
            query.last();
            QString bhlast=query.value("商品编号").toString();
            query.first();
            int je=0;
            int zje2=0;
            int csbzje1=0;
            query.previous();
            while (query.next())
            {
                int count=ui->tw_hw->rowCount();
                ui->tw_hw->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                sccs1=query.value("生产厂商").toString();
                spm1=query.value("商品名").toString();
                xh1=query.value("型号").toString();
                dj1=query.value("单价").toString();
                sl1=query.value("数量").toString();
                year1=query.value("进货年").toString();
                moon1=query.value("进货月").toString();
                day1=query.value("进货日").toString();
                ywybh1=query.value("业务员编号").toString();
                zje1=query.value("总金额").toString();
                je=query.value("总金额").toInt();
                zje2=zje2+je;

                QTableWidgetItem *zje=new QTableWidgetItem(zje1);

                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);


                ui->tw_hw->setItem(count,0,spbh);
                ui->tw_hw->setItem(count,1,sccs);
                ui->tw_hw->setItem(count,2,spm);
                ui->tw_hw->setItem(count,3,xh);
                ui->tw_hw->setItem(count,4,dj);
                ui->tw_hw->setItem(count,5,sl);
                ui->tw_hw->setItem(count,6,zje);
                ui->tw_hw->setItem(count,7,year);
                ui->tw_hw->setItem(count,8,moon);
                ui->tw_hw->setItem(count,9,day);
                ui->tw_hw->setItem(count,10,ywybh);


                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=je;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=je;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=0;
                    sccsstock=sccs1;

                }
            }
            QString zje3=QString("%1").arg(zje2);
            ui->let_jhzje->setText(zje3);

        }
        else
        {
            QMessageBox::information(this,"进货统计","今月暂未进货");
            ui->let_jhzje->setText("0");
        }
    }
    else
    {
        QMessageBox::critical(this,"进货统计","进货数据获取失败");
    }

}
void Widget::on_btn_bn_clicked()
{
    ui->tw_hw->setRowCount(0);
    ui->tw_cs->setRowCount(0);
    QDateTime datetime = QDateTime::currentDateTime();
    int qtmoon=datetime.date().month();
    int a=0,b=0;
    if(qtmoon>=1 && qtmoon<=3)
    {
        a=1;
        b=3;
    }
    else if(qtmoon>=4 && qtmoon<=6)
    {
        a=4;
        b=6;
    }
    else if(qtmoon>=7 && qtmoon<=9)
    {
        a=7;
        b=9;
    }
    else if(qtmoon>=10 && qtmoon<=12)
    {
        a=10;
        b=12;
    }
    QSqlQuery query;
    QString sql1=QString("select * from goods where 进货年=datepart(year,getdate()) and 进货月 between '%1' and '%2' order by 生产厂商,总金额").arg(a).arg(b);
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
                                    query.last();
            QString bhlast=query.value("商品编号").toString();
                                 query.first();
            int csbzje1=0;
            int je=0;
            int zje2=0;

            query.previous();
            while (query.next())
            {
                int count=ui->tw_hw->rowCount();
                ui->tw_hw->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                sccs1=query.value("生产厂商").toString();
                spm1=query.value("商品名").toString();
                xh1=query.value("型号").toString();
                dj1=query.value("单价").toString();
                sl1=query.value("数量").toString();
                year1=query.value("进货年").toString();
                moon1=query.value("进货月").toString();
                day1=query.value("进货日").toString();
                ywybh1=query.value("业务员编号").toString();
                zje1=query.value("总金额").toString();
                je=query.value("总金额").toInt();
                zje2=zje2+je;

                QTableWidgetItem *zje=new QTableWidgetItem(zje1);

                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);


                ui->tw_hw->setItem(count,0,spbh);
                ui->tw_hw->setItem(count,1,sccs);
                ui->tw_hw->setItem(count,2,spm);
                ui->tw_hw->setItem(count,3,xh);
                ui->tw_hw->setItem(count,4,dj);
                ui->tw_hw->setItem(count,5,sl);
                ui->tw_hw->setItem(count,6,zje);
                ui->tw_hw->setItem(count,7,year);
                ui->tw_hw->setItem(count,8,moon);
                ui->tw_hw->setItem(count,9,day);
                ui->tw_hw->setItem(count,10,ywybh);

                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=je;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=je;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=0;
                    sccsstock=sccs1;

                }
            }
            QString zje3=QString("%1").arg(zje2);
            ui->let_jhzje->setText(zje3);

        }
        else
        {
            QMessageBox::information(this,"进货统计","本季度暂未进货");
        }
    }
    else
    {
        QMessageBox::critical(this,"进货统计","进货数据获取失败");
    }

}
void Widget::on_btn_yn_clicked()
{
    ui->tw_hw->setRowCount(0);
    ui->tw_cs->setRowCount(0);
    QSqlQuery query;
    QString sql1="select * from goods where 进货年=datepart(year,getdate()) order by 生产厂商,总金额";
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
                                    query.last();
            QString bhlast=query.value("商品编号").toString();
                                 query.first();
            int csbzje1=0;
            int je=0;
            int zje2=0;
            query.previous();
            while (query.next())
            {
                int count=ui->tw_hw->rowCount();
                ui->tw_hw->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                sccs1=query.value("生产厂商").toString();
                spm1=query.value("商品名").toString();
                xh1=query.value("型号").toString();
                dj1=query.value("单价").toString();
                sl1=query.value("数量").toString();
                year1=query.value("进货年").toString();
                moon1=query.value("进货月").toString();
                day1=query.value("进货日").toString();
                ywybh1=query.value("业务员编号").toString();
                zje1=query.value("总金额").toString();
                je=query.value("总金额").toInt();
                zje2=zje2+je;
                QTableWidgetItem *zje=new QTableWidgetItem(zje1);
                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);

                ui->tw_hw->setItem(count,0,spbh);
                ui->tw_hw->setItem(count,1,sccs);
                ui->tw_hw->setItem(count,2,spm);
                ui->tw_hw->setItem(count,3,xh);
                ui->tw_hw->setItem(count,4,dj);
                ui->tw_hw->setItem(count,5,sl);
                ui->tw_hw->setItem(count,6,zje);
                ui->tw_hw->setItem(count,7,year);
                ui->tw_hw->setItem(count,8,moon);
                ui->tw_hw->setItem(count,9,day);
                ui->tw_hw->setItem(count,10,ywybh);

                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=je;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=je;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs->rowCount();
                    ui->tw_cs->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *year5=new QTableWidgetItem(year1);
                    QTableWidgetItem *moon5=new QTableWidgetItem(moon1);
                    QTableWidgetItem *day5=new QTableWidgetItem(day1);
                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs->setItem(count1,0,sccs2);
                    ui->tw_cs->setItem(count1,1,year5);
                    ui->tw_cs->setItem(count1,2,moon5);
                    ui->tw_cs->setItem(count1,3,day5);
                    ui->tw_cs->setItem(count1,4,zjecsb);
                    csbzje1=0;
                    sccsstock=sccs1;

                }
            }
            QString zje3=QString("%1").arg(zje2);
            ui->let_jhzje->setText(zje3);
        }
        else
        {
            QMessageBox::information(this,"进货统计","今年暂未进货");

        }
    }
    else
    {
        QMessageBox::critical(this,"进货统计","进货数据获取失败");
    }
}
//销售统计表***************************************************************************************
void Widget::on_btn_day_2_clicked()
{
    ui->let_xszje->setText("");
    ui->tw_hw_2->setRowCount(0);
    ui->tw_cs_2->setRowCount(0);
    QSqlQuery query;
    QString sql1="select * from sell where 销售年=datepart(year,getdate()) and 销售月=datepart(month,getdate()) and 销售日=datepart(day,getdate()) order by 生产厂商,总金额";
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
                                    query.last();
            QString bhlast=query.value("商品编号").toString();
                                 query.first();
            int csbzje1=0;
            int zje3=0;
            query.previous();
            while (query.next())
            {
                int zje2=0;

                int count=ui->tw_hw_2->rowCount();
                ui->tw_hw_2->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                sccs1=query.value("生产厂商").toString();
                spm1=query.value("商品名").toString();
                xh1=query.value("型号").toString();
                dj1=query.value("单价").toString();
                sl1=query.value("数量").toString();
                year1=query.value("销售年").toString();
                moon1=query.value("销售月").toString();
                day1=query.value("销售日").toString();
                ywybh1=query.value("业务员编号").toString();
                zje1=query.value("总金额").toString();
                zje2=query.value("总金额").toInt();
                zje3=zje3+zje2;
                QTableWidgetItem *zje=new QTableWidgetItem(zje1);
                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);


                ui->tw_hw_2->setItem(count,0,spbh);
                ui->tw_hw_2->setItem(count,1,sccs);
                ui->tw_hw_2->setItem(count,2,spm);
                ui->tw_hw_2->setItem(count,3,xh);
                ui->tw_hw_2->setItem(count,4,dj);
                ui->tw_hw_2->setItem(count,5,sl);
                ui->tw_hw_2->setItem(count,6,zje);
                ui->tw_hw_2->setItem(count,7,year);
                ui->tw_hw_2->setItem(count,8,moon);
                ui->tw_hw_2->setItem(count,9,day);
                ui->tw_hw_2->setItem(count,10,ywybh);

                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=zje2;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;

                }

            }
            QString zje4=QString("%1").arg(zje3);
            ui->let_xszje->setText(zje4);
        }
        else
        {

            QMessageBox::information(this,"销售统计","今日暂未销售货物");
        }
    }
    else
    {
        QMessageBox::critical(this,"销售统计","销售数据获取失败");
    }
}
void Widget::on_btn_moon_2_clicked()
{
    ui->let_xszje->setText("");
    ui->tw_hw_2->setRowCount(0);
    ui->tw_cs_2->setRowCount(0);
    QSqlQuery query;
    QString sql1="select * from sell where 销售年=datepart(year,getdate()) and 销售月=datepart(month,getdate()) order by 生产厂商,总金额";
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
                                    query.last();
            QString bhlast=query.value("商品编号").toString();
                                 query.first();
            int csbzje1=0;
            int zje3=0;
            query.previous();
            while (query.next())
            {
                int zje2=0;
                int count=ui->tw_hw_2->rowCount();
                ui->tw_hw_2->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                sccs1=query.value("生产厂商").toString();
                spm1=query.value("商品名").toString();
                xh1=query.value("型号").toString();
                dj1=query.value("单价").toString();
                sl1=query.value("数量").toString();
                year1=query.value("销售年").toString();
                moon1=query.value("销售月").toString();
                day1=query.value("销售日").toString();
                ywybh1=query.value("业务员编号").toString();
                zje1=query.value("总金额").toString();
                zje2=query.value("总金额").toInt();
                zje3=zje3+zje2;

                QTableWidgetItem *zje=new QTableWidgetItem(zje1);
                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);

                ui->tw_hw_2->setItem(count,0,spbh);
                ui->tw_hw_2->setItem(count,1,sccs);
                ui->tw_hw_2->setItem(count,2,spm);
                ui->tw_hw_2->setItem(count,3,xh);
                ui->tw_hw_2->setItem(count,4,dj);
                ui->tw_hw_2->setItem(count,5,sl);
                ui->tw_hw_2->setItem(count,6,zje);
                ui->tw_hw_2->setItem(count,7,year);
                ui->tw_hw_2->setItem(count,8,moon);
                ui->tw_hw_2->setItem(count,9,day);
                ui->tw_hw_2->setItem(count,10,ywybh);
                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=zje2;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
            }
            QString zje4=QString("%1").arg(zje3);
            ui->let_xszje->setText(zje4);
        }
        else
        {
            QMessageBox::information(this,"销售统计","本月暂未销售货物");
        }
    }
    else
    {
        QMessageBox::critical(this,"销售统计","销售数据获取失败");
    }
}
void Widget::on_btn_bn_2_clicked()
{
    ui->let_xszje->setText("");
    ui->tw_hw_2->setRowCount(0);
    ui->tw_cs_2->setRowCount(0);
    QDateTime datetime = QDateTime::currentDateTime();
    int qtmoon=datetime.date().month();
    int a=0,b=0;
    if(qtmoon>=1 && qtmoon<=3)
    {
        a=1;
        b=3;
    }
    else if(qtmoon>=4 && qtmoon<=6)
    {
        a=4;
        b=6;
    }
    else if(qtmoon>=7 && qtmoon<=9)
    {
        a=7;
        b=9;
    }
    else if(qtmoon>=10 && qtmoon<=12)
    {
        a=10;
        b=12;
    }
    QSqlQuery query;
    QString sql1=QString("select * from sell where 销售年=datepart(year,getdate()) and 销售月 between '%1' and '%2' order by 生产厂商,总金额").arg(a).arg(b);
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
                                    query.last();
            QString bhlast=query.value("商品编号").toString();
                                 query.first();
            int csbzje1=0;
            int zje3=0;
            query.previous();
            while (query.next())
            {
                int zje2=0;
                int count=ui->tw_hw_2->rowCount();
                ui->tw_hw_2->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                            sccs1=query.value("生产厂商").toString();
                          spm1=query.value("商品名").toString();
                          xh1=query.value("型号").toString();
                          dj1=query.value("单价").toString();
                          sl1=query.value("数量").toString();
                          year1=query.value("销售年").toString();
                          moon1=query.value("销售月").toString();
                          day1=query.value("销售日").toString();
                          ywybh1=query.value("业务员编号").toString();
                          zje1=query.value("总金额").toString();
                          zje2=query.value("总金额").toInt();
                          zje3=zje3+zje2;

                QTableWidgetItem *zje=new QTableWidgetItem(zje1);
                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);

                ui->tw_hw_2->setItem(count,0,spbh);
                ui->tw_hw_2->setItem(count,1,sccs);
                ui->tw_hw_2->setItem(count,2,spm);
                ui->tw_hw_2->setItem(count,3,xh);
                ui->tw_hw_2->setItem(count,4,dj);
                ui->tw_hw_2->setItem(count,5,sl);
                ui->tw_hw_2->setItem(count,6,zje);
                ui->tw_hw_2->setItem(count,7,year);
                ui->tw_hw_2->setItem(count,8,moon);
                ui->tw_hw_2->setItem(count,9,day);
                ui->tw_hw_2->setItem(count,10,ywybh);
                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=zje2;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
            }
            QString zje4=QString("%1").arg(zje3);
            ui->let_xszje->setText(zje4);
        }
        else
        {
            QMessageBox::information(this,"销售统计","本季度暂未销售货物");

        }
    }
    else
    {
        QMessageBox::critical(this,"销售统计","销售数据获取失败");
    }
}
void Widget::on_btn_yn_2_clicked()
{
    ui->let_xszje->setText("");
    ui->tw_hw_2->setRowCount(0);
    ui->tw_cs_2->setRowCount(0);
    QSqlQuery query;
    QString sql1="select * from sell where 销售年=datepart(year,getdate()) order by 生产厂商,总金额";
    QString spbh1;
    QString sccs1;
    QString spm1;
    QString xh1;
    QString dj1;
    QString sl1;
    QString year1;
    QString moon1;
    QString day1;
    QString zje1;
    QString ywybh1;
    if(query.exec(sql1))
    {
        if(query.first())
        {
            QString sccsstock=query.value("生产厂商").toString();
                                    query.last();
            QString bhlast=query.value("商品编号").toString();
                                 query.first();
            int csbzje1=0;
            int zje3=0;
            query.previous();
            while (query.next())
            {
                int zje2=0;
                int count=ui->tw_hw_2->rowCount();
                ui->tw_hw_2->setRowCount(count+1);

                spbh1=query.value("商品编号").toString();
                            sccs1=query.value("生产厂商").toString();
                          spm1=query.value("商品名").toString();
                          xh1=query.value("型号").toString();
                          dj1=query.value("单价").toString();
                          sl1=query.value("数量").toString();
                          year1=query.value("销售年").toString();
                          moon1=query.value("销售月").toString();
                          day1=query.value("销售日").toString();
                          ywybh1=query.value("业务员编号").toString();
                          zje1=query.value("总金额").toString();
                          zje2=query.value("总金额").toInt();
                          zje3=zje3+zje2;

                QTableWidgetItem *zje=new QTableWidgetItem(zje1);
                QTableWidgetItem *spbh=new QTableWidgetItem(spbh1);
                QTableWidgetItem *sccs=new QTableWidgetItem(sccs1);
                QTableWidgetItem *spm=new QTableWidgetItem(spm1);
                QTableWidgetItem *xh=new QTableWidgetItem(xh1);
                QTableWidgetItem *dj=new QTableWidgetItem(dj1);
                QTableWidgetItem *sl=new QTableWidgetItem(sl1);
                QTableWidgetItem *year=new QTableWidgetItem(year1);
                QTableWidgetItem *moon=new QTableWidgetItem(moon1);
                QTableWidgetItem *day=new QTableWidgetItem(day1);
                QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh1);

                ui->tw_hw_2->setItem(count,0,spbh);
                ui->tw_hw_2->setItem(count,1,sccs);
                ui->tw_hw_2->setItem(count,2,spm);
                ui->tw_hw_2->setItem(count,3,xh);
                ui->tw_hw_2->setItem(count,4,dj);
                ui->tw_hw_2->setItem(count,5,sl);
                ui->tw_hw_2->setItem(count,6,zje);
                ui->tw_hw_2->setItem(count,7,year);
                ui->tw_hw_2->setItem(count,8,moon);
                ui->tw_hw_2->setItem(count,9,day);
                ui->tw_hw_2->setItem(count,10,ywybh);
                if(sccs1==sccsstock)
                {
                    //QMessageBox::information(this,"","1");
                    csbzje1+=zje2;

                }
                else
                {
                    //QMessageBox::information(this,"","1");
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
                if(spbh1==bhlast)
                {
                    int count1=ui->tw_cs_2->rowCount();
                    ui->tw_cs_2->setRowCount(count1+1);
                    QString csbzje2=QString("%1").arg(csbzje1);

                    QTableWidgetItem *zjecsb=new QTableWidgetItem(csbzje2);
                    QTableWidgetItem *sccs2=new QTableWidgetItem(sccsstock);

                    ui->tw_cs_2->setItem(count1,0,sccs2);
                    ui->tw_cs_2->setItem(count1,1,zjecsb);
                    csbzje1=zje2;
                    sccsstock=sccs1;
                }
            }
            QString zje4=QString("%1").arg(zje3);
            ui->let_xszje->setText(zje4);
        }
        else
        {
            QMessageBox::information(this,"销售统计","本年暂未销售货物");

        }
    }
    else
    {
        QMessageBox::critical(this,"销售统计","销售数据获取失败");
    }
}

//业绩查看*****************************************************************************************************
void Widget::on_btn_ygyj_clicked()
{
    ui->tw_ygyj->setRowCount(0);
    QString ygbh1=ui->let_ygh->text();
    QSqlQuery query1;
    QSqlQuery query2;
    QString sql2=QString("select * from sell where 业务员编号='%1'").arg(ygbh1);
    QString sql1=QString("select * from employee where 员工编号='%1'").arg(ygbh1);
    QString ygxm1;
    int je=0;
    int zje1=0;
    if(query1.exec(sql1))
    {
        if(query1.first())
        {
            if(query2.exec(sql2))
            {
                if(query2.first())
                {
                    //QMessageBox::information(this,"1","1111");
                    query2.previous();
                    while (query2.next())
                    {
                        je=query2.value("总金额").toInt();
                        zje1=zje1+je;
                    }
                    int count=ui->tw_ygyj->rowCount();
                    ui->tw_ygyj->setRowCount(count+1);
                    ygxm1=query1.value("员工姓名").toString();
                    QString zje2=QString("%1").arg(zje1);
                    zje1=0;
                    je=0;
                    QTableWidgetItem *ygbh=new QTableWidgetItem(ygbh1);
                    QTableWidgetItem *ygxm=new QTableWidgetItem(ygxm1);
                    QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                    ui->tw_ygyj->setItem(count,0,ygbh);
                    ui->tw_ygyj->setItem(count,1,ygxm);
                    ui->tw_ygyj->setItem(count,2,zje);
                }
                else
                {
                    //QMessageBox::information(this,"1","222222");
                    int count=ui->tw_ygyj->rowCount();
                    ui->tw_ygyj->setRowCount(count+1);
                    zje1=0;
                    QString zje2=QString("%1").arg(zje1);
                    ygxm1=query1.value("员工姓名").toString();
                    QTableWidgetItem *ygbh=new QTableWidgetItem(ygbh1);
                    QTableWidgetItem *ygxm=new QTableWidgetItem(ygxm1);
                    QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                    ui->tw_ygyj->setItem(count,0,ygbh);
                    ui->tw_ygyj->setItem(count,1,ygxm);
                    ui->tw_ygyj->setItem(count,2,zje);
                }

            }
            else
            {
                QMessageBox::critical(this,"业绩查看","员工销售数据获取失败");
            }
        }
        else
        {
            QMessageBox::information(this,"业绩查看","此编号员工不存在");
        }

    }
    else
    {
        QMessageBox::critical(this,"业绩查看","员工销售数据获取失败");

    }
}

void Widget::on_btn_syygyj_clicked()
{
    ui->tw_ygyj->setRowCount(0);
    QSqlQuery query1;
    QSqlQuery query2;
    QString ygbh1;
    QString ygxm1;
    int je=0;
    int zje1=0;
    QString sql1="select * from employee";
    QString sql2=QString("select * from sell where 业务员编号='%1'").arg(ygbh1);

    if(query1.exec(sql1))
    {
        if(query1.first())
        {
            query1.previous();
            while (query1.next())
            {
                ygbh1=query1.value("员工编号").toString();
                //QMessageBox::information(this,"1",ygbh1);
                sql2=QString("select * from sell where 业务员编号='%1'").arg(ygbh1);
                if(query2.exec(sql2))
                {
                    if(query2.first())
                    {
                        //QMessageBox::information(this,"1","1111");
                        query2.previous();
                        while (query2.next())
                        {
                            je=query2.value("总金额").toInt();
                            zje1=zje1+je;
                        }

                        int count=ui->tw_ygyj->rowCount();
                        ui->tw_ygyj->setRowCount(count+1);
                        ygxm1=query1.value("员工姓名").toString();
                        QString zje2=QString("%1").arg(zje1);
                        zje1=0;
                        je=0;
                        QTableWidgetItem *ygbh=new QTableWidgetItem(ygbh1);
                        QTableWidgetItem *ygxm=new QTableWidgetItem(ygxm1);
                        QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                        ui->tw_ygyj->setItem(count,0,ygbh);
                        ui->tw_ygyj->setItem(count,1,ygxm);
                        ui->tw_ygyj->setItem(count,2,zje);
                    }
                    else
                    {
                        //QMessageBox::information(this,"1","22222");
                        int count=ui->tw_ygyj->rowCount();
                        ui->tw_ygyj->setRowCount(count+1);
                        zje1=0;
                        je=0;
                        QString zje2=QString("%1").arg(zje1);
                        ygxm1=query1.value("员工姓名").toString();
                        QTableWidgetItem *ygbh=new QTableWidgetItem(ygbh1);
                        QTableWidgetItem *ygxm=new QTableWidgetItem(ygxm1);
                        QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                        ui->tw_ygyj->setItem(count,0,ygbh);
                        ui->tw_ygyj->setItem(count,1,ygxm);
                        ui->tw_ygyj->setItem(count,2,zje);
                    }

                }
            }
        }
        else
        {
            QMessageBox::information(this,"业绩查看","暂无员工销售信息");
        }
    }
    else
    {
        QMessageBox::critical(this,"业绩查看","员工销售数据获取失败");
    }
}
//进货表*************************************************************************************************
void Widget::on_btn_jhbcx_clicked()
{
    ui->tw_jhb->setRowCount(0);
    //获取sql查询语句
    int flag=1;
    QString spbh1=QString("商品编号='%1'").arg(ui->let_jhbbh->text());
    QString cs1=QString("生产厂商='%1'").arg(ui->let_jhbsccs->text());
    QString spm1=QString("商品名='%1'").arg(ui->let_jhbmc->text());
    QString xh1=QString("型号='%1'").arg(ui->let_jhbxh->text());
    QString year1=QString("进货年='%1'").arg(ui->let_jhbyear->text());
    QString moon1=QString("进货月='%1'").arg(ui->let_jhbmoon->text());
    QString day1=QString("进货日='%1'").arg(ui->let_jhbday->text());
    QString ywybh1=QString("业务员编号='%1'").arg(ui->let_jhbywybh->text());
    QString endsql1="select * from goods";
    QString endsql2="";
    QString endsql3="";
    if(!ui->let_jhbbh->text().isEmpty())
    {
        endsql3.append(" where ");
        endsql2.append(spbh1);
    }
    if(!ui->let_jhbsccs->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(cs1);
    }
    if(!ui->let_jhbmc->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(spm1);
    }
    if(!ui->let_jhbxh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(xh1);
    }
    //日期***************************************************************************************************************************
    if((ui->let_jhbyear->text().isEmpty()) && (ui->let_jhbmoon->text().isEmpty()) && (ui->let_jhbday->text().isEmpty()))
    {

    }
    else if((!ui->let_jhbyear->text().isEmpty()) && (!ui->let_jhbmoon->text().isEmpty()) && (!ui->let_jhbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);
        endsql2.append(" and ");
        endsql2.append(day1);
    }

    else if((!ui->let_jhbyear->text().isEmpty()) && (!ui->let_jhbmoon->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);
    }
    else if((!ui->let_jhbyear->text().isEmpty())&&(ui->let_jhbmoon->text().isEmpty())&&(ui->let_jhbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
    }
    else
    {
        QMessageBox::information(this,"进货表","日期请填写完整");
        flag=0;
    }

   // ************************************************************************************************************
    if(!ui->let_jhbywybh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(ywybh1);
    }
    endsql1.append(endsql3);
    endsql1.append(endsql2);
    //QMessageBox::information(this,"",endsql1);
//获取查询数据
    if(flag)
    {
        QSqlQuery query;
        QString spbh2;
        QString sccs2;
        QString spm2;
        QString xh2;
        QString dj2;
        QString sl2;
        QString zje2;
        QString year2;
        QString moon2;
        QString day2;
        QString ywybh2;
        if(query.exec(endsql1))
        {
            if(query.first())
            {
                query.previous();
                while (query.next())
                {
                    int count=ui->tw_jhb->rowCount();
                    ui->tw_jhb->setRowCount(count+1);
                    ui->tw_jhb->setRowCount(count+1);

                    spbh2=query.value("商品编号").toString();
                    sccs2=query.value("生产厂商").toString();
                    spm2=query.value("商品名").toString();
                    xh2=query.value("型号").toString();
                    dj2=query.value("单价").toString();
                    sl2=query.value("数量").toString();
                    zje2=query.value("总金额").toString();
                    year2=query.value("进货年").toString();
                    moon2=query.value("进货月").toString();
                    day2=query.value("进货日").toString();
                    ywybh2=query.value("业务员编号").toString();


                    QTableWidgetItem *spbh=new QTableWidgetItem(spbh2);
                    QTableWidgetItem *sccs=new QTableWidgetItem(sccs2);
                    QTableWidgetItem *spm=new QTableWidgetItem(spm2);
                    QTableWidgetItem *xh=new QTableWidgetItem(xh2);
                    QTableWidgetItem *dj=new QTableWidgetItem(dj2);
                    QTableWidgetItem *sl=new QTableWidgetItem(sl2);

                    QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                    QTableWidgetItem *year=new QTableWidgetItem(year2);
                    QTableWidgetItem *moon=new QTableWidgetItem(moon2);
                    QTableWidgetItem *day=new QTableWidgetItem(day2);
                    QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh2);


                    ui->tw_jhb->setItem(count,0,spbh);
                    ui->tw_jhb->setItem(count,1,sccs);
                    ui->tw_jhb->setItem(count,2,spm);
                    ui->tw_jhb->setItem(count,3,xh);
                    ui->tw_jhb->setItem(count,4,dj);
                    ui->tw_jhb->setItem(count,5,sl);
                    ui->tw_jhb->setItem(count,6,zje);
                    ui->tw_jhb->setItem(count,7,year);
                    ui->tw_jhb->setItem(count,8,moon);
                    ui->tw_jhb->setItem(count,9,day);
                    ui->tw_jhb->setItem(count,10,ywybh);
                }
            }
            else
            {
                QMessageBox::information(this,"进货表","暂无进货数据");
            }
        }
        else
        {
            QMessageBox::critical(this,"进货表","进货数据获取失败");
        }
    }
}
void Widget::on_btn_jhbclear_clicked()
{
    ui->let_jhbbh->clear();
    ui->let_jhbsccs->clear();
    ui->let_jhbmc->clear();
    ui->let_jhbxh->clear();
    ui->let_jhbyear->clear();
    ui->let_jhbmoon->clear();
    ui->let_jhbday->clear();
    ui->let_jhbywybh->clear();
}

//销售表************************************************************************************
void Widget::on_btn_xsbcx_clicked()
{
    ui->tw_xsb->setRowCount(0);
    //获取sql查询语句
    int flag=1;
    QString spbh1=QString("商品编号='%1'").arg(ui->let_xsbbh->text());
    QString cs1=QString("生产厂商='%1'").arg(ui->let_xsbsccs->text());
    QString spm1=QString("商品名='%1'").arg(ui->let_xsbspmc->text());
    QString xh1=QString("型号='%1'").arg(ui->let_xsbxh->text());
    QString year1=QString("销售年='%1'").arg(ui->let_xsbyear->text());
    QString moon1=QString("销售月='%1'").arg(ui->let_xsbmoon->text());
    QString day1=QString("销售日='%1'").arg(ui->let_xsbday->text());
    QString ywybh1=QString("业务员编号='%1'").arg(ui->let_xsbywybh->text());
    QString endsql1="select * from sell";
    QString endsql2="";
    QString endsql3="";
    if(!ui->let_xsbbh->text().isEmpty())
    {
        endsql3.append(" where ");
        endsql2.append(spbh1);
    }
    if(!ui->let_xsbsccs->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(cs1);
    }
    if(!ui->let_xsbspmc->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(spm1);
    }
    if(!ui->let_xsbxh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(xh1);
    }


    //日期
    if((ui->let_xsbyear->text().isEmpty()) && (ui->let_xsbmoon->text().isEmpty()) && (ui->let_xsbday->text().isEmpty()))
    {

    }
    else if((!ui->let_xsbyear->text().isEmpty()) && (!ui->let_xsbmoon->text().isEmpty()) && (!ui->let_xsbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);
        endsql2.append(" and ");
        endsql2.append(day1);
    }

    else if((!ui->let_xsbyear->text().isEmpty()) && (!ui->let_xsbmoon->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);

    }
    else if((!ui->let_xsbyear->text().isEmpty())&&(ui->let_xsbmoon->text().isEmpty())&&(ui->let_xsbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
    }
    else
    {
        QMessageBox::information(this,"销售表","日期请填写完整");
        flag=0;
    }

    if(!ui->let_xsbywybh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(ywybh1);
    }
    endsql1.append(endsql3);
    endsql1.append(endsql2);
//获取查询数据
    if(flag)
    {
        //QMessageBox::information(this,"",endsql1);
        QSqlQuery query;
        QString spbh2;
        QString sccs2;
        QString spm2;
        QString xh2;
        QString dj2;
        QString sl2;
        QString zje2;
        QString year2;
        QString moon2;
        QString day2;
        QString ywybh2;
        if(query.exec(endsql1))
        {
            if(query.first())
            {
                query.previous();
                while (query.next())
                {
                    int count=ui->tw_xsb->rowCount();
                    ui->tw_xsb->setRowCount(count+1);
                    ui->tw_xsb->setRowCount(count+1);
                    spbh2=query.value("商品编号").toString();
                    sccs2=query.value("生产厂商").toString();
                    spm2=query.value("商品名").toString();
                    xh2=query.value("型号").toString();
                    dj2=query.value("单价").toString();
                    sl2=query.value("数量").toString();
                    zje2=query.value("总金额").toString();
                    year2=query.value("销售年").toString();
                    moon2=query.value("销售月").toString();
                    day2=query.value("销售日").toString();
                    ywybh2=query.value("业务员编号").toString();


                    QTableWidgetItem *spbh=new QTableWidgetItem(spbh2);
                    QTableWidgetItem *sccs=new QTableWidgetItem(sccs2);
                    QTableWidgetItem *spm=new QTableWidgetItem(spm2);
                    QTableWidgetItem *xh=new QTableWidgetItem(xh2);
                    QTableWidgetItem *dj=new QTableWidgetItem(dj2);
                    QTableWidgetItem *sl=new QTableWidgetItem(sl2);

                    QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                    QTableWidgetItem *year=new QTableWidgetItem(year2);
                    QTableWidgetItem *moon=new QTableWidgetItem(moon2);
                    QTableWidgetItem *day=new QTableWidgetItem(day2);
                    QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh2);


                    ui->tw_xsb->setItem(count,0,spbh);
                    ui->tw_xsb->setItem(count,1,sccs);
                    ui->tw_xsb->setItem(count,2,spm);
                    ui->tw_xsb->setItem(count,3,xh);
                    ui->tw_xsb->setItem(count,4,dj);
                    ui->tw_xsb->setItem(count,5,sl);
                    ui->tw_xsb->setItem(count,6,zje);
                    ui->tw_xsb->setItem(count,7,year);
                    ui->tw_xsb->setItem(count,8,moon);
                    ui->tw_xsb->setItem(count,9,day);
                    ui->tw_xsb->setItem(count,10,ywybh);
                }
            }
            else
            {
                QMessageBox::information(this,"销售表","暂无销售数据");
            }
        }
        else
        {
            QMessageBox::critical(this,"销售表","销售数据获取失败");
        }
    }
}
void Widget::on_btn_xsbclear_clicked()
{
    ui->let_xsbbh->clear();
    ui->let_xsbsccs->clear();
    ui->let_xsbspmc->clear();
    ui->let_xsbxh->clear();
    ui->let_xsbyear->clear();
    ui->let_xsbmoon->clear();
    ui->let_xsbday->clear();
    ui->let_xsbywybh->clear();
}

//退货表***************************************************************************************
void Widget::on_btn_thbcx_clicked()
{
    ui->tw_thb->setRowCount(0);
    //获取sql查询语句
    int flag=1;
    QString spbh1=QString("退货编号='%1'").arg(ui->let_thbspbh->text());
    QString cs1=QString("生产厂商='%1'").arg(ui->let_thbsccs->text());
    QString spm1=QString("商品名='%1'").arg(ui->let_thbspmc->text());
    QString xh1=QString("型号='%1'").arg(ui->let_thbxh->text());
    QString year1=QString("退货年='%1'").arg(ui->let_thbyear->text());
    QString moon1=QString("退货月='%1'").arg(ui->let_thbmoon->text());
    QString day1=QString("退货日='%1'").arg(ui->let_thbday->text());
    QString ywybh1=QString("业务员编号='%1'").arg(ui->let_thbywybh->text());
    QString endsql1="select * from retreat";
    QString endsql2="";
    QString endsql3="";
    if(!ui->let_thbspbh->text().isEmpty())
    {
        endsql3.append(" where ");
        endsql2.append(spbh1);
    }
    if(!ui->let_thbsccs->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(cs1);
    }
    if(!ui->let_thbspmc->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(spm1);
    }
    if(!ui->let_thbxh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(xh1);
    }


    //日期
    if((ui->let_thbyear->text().isEmpty()) && (ui->let_thbmoon->text().isEmpty()) && (ui->let_thbday->text().isEmpty()))
    {

    }
    else if((!ui->let_thbyear->text().isEmpty()) && (!ui->let_thbmoon->text().isEmpty()) && (!ui->let_thbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);
        endsql2.append(" and ");
        endsql2.append(day1);
    }
    else if((!ui->let_thbyear->text().isEmpty()) && (!ui->let_thbmoon->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);

    }
    else if((!ui->let_thbyear->text().isEmpty())&&(ui->let_thbmoon->text().isEmpty())&&(ui->let_thbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
    }
    else
    {
        QMessageBox::information(this,"退货表","日期请填写完整");
        flag=0;
    }

    if(!ui->let_thbywybh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(ywybh1);
    }
    endsql1.append(endsql3);
    endsql1.append(endsql2);

//获取查询数据
    if(flag)
    {
        QSqlQuery query;
        QString spbh2;
        QString sccs2;
        QString spm2;
        QString xh2;
        QString dj2;
        QString sl2;
        QString zje2;
        QString year2;
        QString moon2;
        QString day2;
        QString ywybh2;
        if(query.exec(endsql1))
        {
            if(query.first())
            {
                query.previous();
                while (query.next())
                {
                    int count=ui->tw_thb->rowCount();
                    ui->tw_thb->setRowCount(count+1);
                    ui->tw_thb->setRowCount(count+1);
                    spbh2=query.value("退货编号").toString();
                    sccs2=query.value("生产厂商").toString();
                    spm2=query.value("商品名").toString();
                    xh2=query.value("型号").toString();
                    dj2=query.value("单价").toString();
                    sl2=query.value("数量").toString();
                    zje2=query.value("总金额").toString();
                    year2=query.value("退货年").toString();
                    moon2=query.value("退货月").toString();
                    day2=query.value("退货日").toString();
                    ywybh2=query.value("业务员编号").toString();

                    QTableWidgetItem *spbh=new QTableWidgetItem(spbh2);
                    QTableWidgetItem *sccs=new QTableWidgetItem(sccs2);
                    QTableWidgetItem *spm=new QTableWidgetItem(spm2);
                    QTableWidgetItem *xh=new QTableWidgetItem(xh2);
                    QTableWidgetItem *dj=new QTableWidgetItem(dj2);
                    QTableWidgetItem *sl=new QTableWidgetItem(sl2);

                    QTableWidgetItem *zje=new QTableWidgetItem(zje2);
                    QTableWidgetItem *year=new QTableWidgetItem(year2);
                    QTableWidgetItem *moon=new QTableWidgetItem(moon2);
                    QTableWidgetItem *day=new QTableWidgetItem(day2);
                    QTableWidgetItem *ywybh=new QTableWidgetItem(ywybh2);

                    ui->tw_thb->setItem(count,0,spbh);
                    ui->tw_thb->setItem(count,1,sccs);
                    ui->tw_thb->setItem(count,2,spm);
                    ui->tw_thb->setItem(count,3,xh);
                    ui->tw_thb->setItem(count,4,dj);
                    ui->tw_thb->setItem(count,5,sl);
                    ui->tw_thb->setItem(count,6,zje);
                    ui->tw_thb->setItem(count,7,year);
                    ui->tw_thb->setItem(count,8,moon);
                    ui->tw_thb->setItem(count,9,day);
                    ui->tw_thb->setItem(count,10,ywybh);
                }
            }
            else
            {
                QMessageBox::information(this,"退货表","暂无退货数据");
            }
        }
        else
        {
            QMessageBox::critical(this,"退货表","退货数据获取失败");
        }
    }
}
void Widget::on_btn_thbclear_clicked()
{
    ui->let_thbspbh->clear();
    ui->let_thbsccs->clear();
    ui->let_thbspmc->clear();
    ui->let_thbxh->clear();
    ui->let_thbyear->clear();
    ui->let_thbmoon->clear();
    ui->let_thbday->clear();
    ui->let_thbywybh->clear();
}

//员工表************************************************************************************
void Widget::on_btn_ygbcx_clicked()
{
    ui->tw_ygb->setRowCount(0);
    //获取sql查询语句
    QString ygbh1=QString("员工编号='%1'").arg(ui->let_ygbygbh->text());
    QString ygxm1=QString("员工姓名='%1'").arg(ui->let_ygbygxm->text());
    QString lxdh1=QString("员工电话='%1'").arg(ui->let_ygblxdh->text());
    QString ygdz1=QString("员工地址='%1'").arg(ui->let_ygbygdz->text());
    QString endsql1="select * from employee";
    QString endsql2="";
    QString endsql3="";
    if(!ui->let_ygbygbh->text().isEmpty())
    {
        endsql3.append(" where ");
        endsql2.append(ygbh1);
    }
    if(!ui->let_ygbygxm->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(ygxm1);
    }
    if(!ui->let_ygblxdh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(lxdh1);
    }
    if(!ui->let_ygbygdz->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(ygdz1);
    }
    endsql1.append(endsql3);
    endsql1.append(endsql2);
//    QMessageBox::information(this,"",endsql1);
//获取查询数据
    QSqlQuery query;
    QString ygbh2;
    QString ygxm2;
    QString lxdh2;
    QString ygdz2;

    if(query.exec(endsql1))
    {
        if(query.first())
        {
            query.previous();
            while (query.next())
            {
                int count=ui->tw_ygb->rowCount();
                ui->tw_ygb->setRowCount(count+1);
                ygbh2=query.value("员工编号").toString();
                ygxm2=query.value("员工姓名").toString();
                lxdh2=query.value("员工电话").toString();
                ygdz2=query.value("员工地址").toString();

                QTableWidgetItem *ygbh=new QTableWidgetItem(ygbh2);
                QTableWidgetItem *ygxm=new QTableWidgetItem(ygxm2);
                QTableWidgetItem *lxdh=new QTableWidgetItem(lxdh2);
                QTableWidgetItem *ygdz=new QTableWidgetItem(ygdz2);

                ui->tw_ygb->setItem(count,0,ygbh);
                ui->tw_ygb->setItem(count,1,ygxm);
                ui->tw_ygb->setItem(count,2,lxdh);
                ui->tw_ygb->setItem(count,3,ygdz);

            }
        }
        else
        {
            if(!ui->let_ygbygbh->text().isEmpty())
            {
                QMessageBox::information(this,"员工表","暂无此员工信息");
            }
            else
            {
                QMessageBox::information(this,"员工表","暂无员工信息");
            }

        }
    }
    else
    {
        QMessageBox::critical(this,"员工表","员工信息获取失败");
    }

}
void Widget::on_btn_ygbclear_clicked()
{
    if(ui->checkBox->isChecked() || ui->check_ygbtj->isChecked())
    {
        ui->let_ygbygxm->clear();
        ui->let_ygblxdh->clear();
        ui->let_ygbygdz->clear();
    }
    else
    {
        ui->let_ygbygxm->clear();
        ui->let_ygbygbh->clear();
        ui->let_ygblxdh->clear();
        ui->let_ygbygdz->clear();
    }
}
//添加员工
void Widget::on_btn_ygbtj_clicked()
{
    if(ui->check_ygbtj->isChecked())
    {
        QString ygxm1=ui->let_ygbygxm->text();
        QString lxdh1=ui->let_ygblxdh->text();
        QString ygdz1=ui->let_ygbygdz->text();
        QSqlQuery query;
        QString sql1 = QString("insert into employee values('%1', '%2', '%3')").arg(ygxm1,lxdh1,ygdz1);
        if(ygxm1==nullptr || lxdh1==nullptr || ygdz1==nullptr)
        {
            QMessageBox::information(this,"员工表","请填写完整");
        }
        else
        {
            if(query.exec(sql1))
            {
                QMessageBox::information(this,"员工表","员工添加成功");

                //显示到表格
                QString ygbh2=ui->let_ygbygbh->text();
                QString ygxm2;
                QString lxdh2;
                QString ygdz2;
                QSqlQuery query1;
                QString sql2=QString("select * from employee where 员工编号='%1'").arg(ygbh2);
                query1.exec(sql2);
                query1.first();
                int count=ui->tw_ygb->rowCount();
                ui->tw_ygb->setRowCount(count+1);

                ygxm2=query1.value("员工姓名").toString();
                lxdh2=query1.value("员工电话").toString();
                ygdz2=query1.value("员工地址").toString();

                QTableWidgetItem *ygbh=new QTableWidgetItem(ygbh2);
                QTableWidgetItem *ygxm=new QTableWidgetItem(ygxm2);
                QTableWidgetItem *lxdh=new QTableWidgetItem(lxdh2);
                QTableWidgetItem *ygdz=new QTableWidgetItem(ygdz2);

                ui->tw_ygb->setItem(count,0,ygbh);
                ui->tw_ygb->setItem(count,1,ygxm);
                ui->tw_ygb->setItem(count,2,lxdh);
                ui->tw_ygb->setItem(count,3,ygdz);


                ui->let_ygbygxm->clear();
                ui->let_ygbygbh->clear();
                ui->let_ygblxdh->clear();
                ui->let_ygbygdz->clear();

                //添加成功后重新获取员工编号
                QSqlQuery query2;
                QString sql3="select * from employee";
                query2.exec(sql3);
                query2.last();
                int ygbh1=query2.value("员工编号").toInt();
                ygbh1+=1;
                QString ygbh3=QString("%1").arg(ygbh1);
                ui->let_ygbygbh->setText(ygbh3);
            }
            else
            {
                QMessageBox::critical(this,"员工表","员工添加失败");
            }
        }
    }
    else
    {
        QMessageBox::critical(this,"员工表","拒绝添加");
    }
}
//员工表编辑开关
void Widget::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        connect(ui->tw_ygb, &QTableWidget::itemClicked,this,&Widget::onitemclicked);
        ui->let_ygbygbh->setReadOnly(true);
        ui->check_ygbtj->setCheckable(false);

    }
    else if(ui->check_ygbtj->isChecked())
    {
    }
    else
    {
        ui->let_ygbygxm->clear();
        ui->let_ygbygbh->clear();
        ui->let_ygblxdh->clear();
        ui->let_ygbygdz->clear();
        disconnect(ui->tw_ygb, &QTableWidget::itemClicked,this,&Widget::onitemclicked);
        ui->let_ygbygbh->setReadOnly(false);
        ui->check_ygbtj->setCheckable(true);
    }
}
//员工信息修改
void Widget::on_btn_ygbxg_clicked()
{
    if(ui->checkBox->isChecked())
    {

        int ok=QMessageBox::question(this,"员工表","确认修改？");
        if(ok==QMessageBox::Yes)
        {
            QString ygbh=ui->let_ygbygbh->text();
            QString ygxm=ui->let_ygbygxm->text();
            QString yglxdh=ui->let_ygblxdh->text();
            QString ygdz=ui->let_ygbygdz->text();
            QSqlQuery query1;
            QSqlQuery query2;
            QSqlQuery query3;

            QString sql1=QString("update employee set 员工姓名='%1' where 员工编号= '%2'").arg(ygxm,ygbh);
            QString sql2=QString("update employee set 员工电话='%1' where 员工编号= '%2'").arg(yglxdh,ygbh);
            QString sql3=QString("update employee set 员工地址='%1' where 员工编号= '%2'").arg(ygdz,ygbh);

            if(query1.exec(sql1) && query2.exec(sql2) && query3.exec(sql3))
            {

                //QMessageBox::information(this,"员工表","修改成功");
                int count=ui->tw_ygb->currentRow();
                QTableWidgetItem *ygbh1=new QTableWidgetItem(ygbh);
                QTableWidgetItem *ygxm1=new QTableWidgetItem(ygxm);
                QTableWidgetItem *lxdh1=new QTableWidgetItem(yglxdh);
                QTableWidgetItem *ygdz1=new QTableWidgetItem(ygdz);

                ui->tw_ygb->setItem(count,0,ygbh1);
                ui->tw_ygb->setItem(count,1,ygxm1);
                ui->tw_ygb->setItem(count,2,lxdh1);
                ui->tw_ygb->setItem(count,3,ygdz1);
            }
            else
            {
                QMessageBox::information(this,"员工表","修改失败");
            }
        }
        else
        {

        }
    }
    else
    {
        QMessageBox::critical(this,"员工表","拒绝修改");
    }
}
//员工表添加开关
void Widget::on_check_ygbtj_clicked(bool checked)
{

    if(checked)
    {
        QSqlQuery query;
        QString sql1="select * from employee";
        query.exec(sql1);
        query.last();
        int ygbh1=query.value("员工编号").toInt();
        ygbh1+=1;
        QString ygbh=QString("%1").arg(ygbh1);
        ui->let_ygbygbh->setText(ygbh);
        ui->let_ygbygbh->setReadOnly(true);
        ui->checkBox->setCheckable(false);
    }
    else if(ui->checkBox->isChecked())
    {
    }
    else
    {
        ui->let_ygbygxm->clear();
        ui->let_ygbygbh->clear();
        ui->let_ygblxdh->clear();
        ui->let_ygbygdz->clear();
        ui->let_ygbygbh->setReadOnly(false);
        ui->checkBox->setCheckable(true);
    }
}


//厂商表***********************************************************************
//厂商添加
void Widget::on_btn_csbtj_clicked()
{

    if(ui->check_csbtj->isChecked())
    {
        QString csmc1=ui->let_csbcsmc->text();
        QString frdb1=ui->let_csbfrdb->text();
        QString lxdh1=ui->let_csblxdh->text();
        QString csdz1=ui->let_csbcsdz->text();
        QSqlQuery query;
        QString sql1 = QString("insert into manufacturer values('%1', '%2', '%3', '%4')").arg(csmc1,frdb1,lxdh1,csdz1);
        if(csmc1==nullptr || lxdh1==nullptr || csdz1==nullptr || frdb1==nullptr)
        {
            QMessageBox::information(this,"厂商表","请填写完整");
        }
        else
        {
            if(query.exec(sql1))
            {
                QMessageBox::information(this,"厂商表","厂商添加成功");

                //显示到表格
                QString csbh2=ui->let_csbcsbh->text();
                QString csmc2;
                QString frdb2;
                QString lxdh2;
                QString csdz2;
                QSqlQuery query1;
                QString sql2=QString("select * from manufacturer where 厂商编号='%1'").arg(csbh2);
                query1.exec(sql2);
                query1.first();
                int count=ui->tw_csb->rowCount();
                ui->tw_csb->setRowCount(count+1);

                csmc2=query1.value("厂商名称").toString();
                frdb2=query1.value("法人代表").toString();
                lxdh2=query1.value("联系电话").toString();
                csdz2=query1.value("厂商地址").toString();

                QTableWidgetItem *csbh=new QTableWidgetItem(csbh2);
                QTableWidgetItem *csmc=new QTableWidgetItem(csmc2);
                QTableWidgetItem *frdb=new QTableWidgetItem(frdb2);
                QTableWidgetItem *lxdh=new QTableWidgetItem(lxdh2);
                QTableWidgetItem *csdz=new QTableWidgetItem(csdz2);

                ui->tw_csb->setItem(count,0,csbh);
                ui->tw_csb->setItem(count,1,csmc);
                ui->tw_csb->setItem(count,2,frdb);
                ui->tw_csb->setItem(count,3,lxdh);
                ui->tw_csb->setItem(count,4,csdz);

                ui->let_csbcsbh->clear();
                ui->let_csbcsmc->clear();
                ui->let_csbfrdb->clear();
                ui->let_csblxdh->clear();
                ui->let_csbcsdz->clear();

                //添加成功后重新获取员工编号
                QSqlQuery query2;
                QString sql3="select * from manufacturer order by 厂商编号";
                query2.exec(sql3);
                query2.last();
                int csbh1=query2.value("厂商编号").toInt();
                csbh1+=1;
                QString csbh3=QString("%1").arg(csbh1);
                ui->let_ygbygbh->setText(csbh3);
            }
            else
            {
                QMessageBox::critical(this,"厂商表","厂商添加失败");
            }
        }
    }
    else
    {
        QMessageBox::critical(this,"厂商表","拒绝添加");
    }
}
//厂商查询
void Widget::on_btn_csbcx_clicked()
{
    ui->tw_csb->setRowCount(0);
    //获取sql查询语句
    QString csbh1=QString("厂商编号='%1'").arg(ui->let_csbcsbh->text());
    QString csmc1=QString("厂商名称='%1'").arg(ui->let_csbcsmc->text());
    QString frdb1=QString("法人代表='%1'").arg(ui->let_csbfrdb->text());
    QString lxdh1=QString("联系电话='%1'").arg(ui->let_csblxdh->text());
    QString csdz1=QString("厂商地址='%1'").arg(ui->let_csbcsdz->text());
    QString endsql1="select * from manufacturer";
    QString endsql2="";
    QString endsql3="";
    QString endsql4=" order by 厂商编号";
    if(!ui->let_csbcsbh->text().isEmpty())
    {
        endsql3.append(" where ");
        endsql2.append(csbh1);
    }
    if(!ui->let_csbcsmc->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(csmc1);
    }
    if(!ui->let_csbfrdb->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(frdb1);
    }
    if(!ui->let_csblxdh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(lxdh1);
    }
    if(!ui->let_csbcsdz->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(csdz1);
    }
    endsql1.append(endsql3);
    endsql1.append(endsql2);
    endsql1.append(endsql4);
    //QMessageBox::information(this,"",endsql1);
//获取查询数据
    QSqlQuery query;
    QString csbh2;
    QString csmc2;
    QString frdb2;
    QString lxdh2;
    QString csdz2;

    if(query.exec(endsql1))
    {
        if(query.first())
        {
            query.previous();
            while (query.next())
            {
                int count=ui->tw_csb->rowCount();
                ui->tw_csb->setRowCount(count+1);
                csbh2=query.value("厂商编号").toString();
                csmc2=query.value("厂商名称").toString();
                frdb2=query.value("法人代表").toString();
                lxdh2=query.value("联系电话").toString();
                csdz2=query.value("厂商地址").toString();

                QTableWidgetItem *csbh=new QTableWidgetItem(csbh2);
                QTableWidgetItem *csmc=new QTableWidgetItem(csmc2);
                QTableWidgetItem *frdb=new QTableWidgetItem(frdb2);
                QTableWidgetItem *lxdh=new QTableWidgetItem(lxdh2);
                QTableWidgetItem *csdz=new QTableWidgetItem(csdz2);

                ui->tw_csb->setItem(count,0,csbh);
                ui->tw_csb->setItem(count,1,csmc);
                ui->tw_csb->setItem(count,2,frdb);
                ui->tw_csb->setItem(count,3,lxdh);
                ui->tw_csb->setItem(count,4,csdz);
            }
        }
        else
        {
            if(!ui->let_ygbygbh->text().isEmpty())
            {
                QMessageBox::information(this,"厂商表","暂无此厂商信息");
            }
            else
            {
                QMessageBox::information(this,"厂商表","暂无厂商信息");
            }
        }
    }
    else
    {
        QMessageBox::critical(this,"厂商表","厂商信息获取失败");
    }
}
//修改
void Widget::on_btn_csbxg_clicked()
{
    if(ui->check_csbbj->isChecked())
    {

        int ok=QMessageBox::question(this,"厂商表","确认修改？");
        if(ok==QMessageBox::Yes)
        {
            QString csbh=ui->let_csbcsbh->text();
            QString csmc=ui->let_csbcsmc->text();
            QString frdb=ui->let_csbfrdb->text();
            QString lxdh=ui->let_csblxdh->text();
            QString csdz=ui->let_csbcsdz->text();
            QSqlQuery query1;
            QSqlQuery query2;
            QSqlQuery query3;
            QSqlQuery query4;
            QString sql1=QString("update manufacturer set 厂商名称='%1' where 厂商编号= '%2'").arg(csmc,csbh);
            QString sql2=QString("update manufacturer set 法人代表='%1' where 厂商编号= '%2'").arg(frdb,csbh);
            QString sql3=QString("update manufacturer set 联系电话='%1' where 厂商编号= '%2'").arg(lxdh,csbh);
            QString sql4=QString("update manufacturer set 厂商地址='%1' where 厂商编号= '%2'").arg(csdz,csbh);
            if(query1.exec(sql1) && query2.exec(sql2) && query3.exec(sql3) && query4.exec(sql4))
            {
                int count=ui->tw_csb->currentRow();

                csbh=ui->let_csbcsbh->text();
                csmc=ui->let_csbcsmc->text();
                frdb=ui->let_csbfrdb->text();
                lxdh=ui->let_csblxdh->text();
                csdz=ui->let_csbcsdz->text();

                QTableWidgetItem *csbh1=new QTableWidgetItem(csbh);
                QTableWidgetItem *csmc1=new QTableWidgetItem(csmc);
                QTableWidgetItem *frdb1=new QTableWidgetItem(frdb);
                QTableWidgetItem *lxdh1=new QTableWidgetItem(lxdh);
                QTableWidgetItem *csdz1=new QTableWidgetItem(csdz);

                ui->tw_csb->setItem(count,0,csbh1);
                ui->tw_csb->setItem(count,1,csmc1);
                ui->tw_csb->setItem(count,2,frdb1);
                ui->tw_csb->setItem(count,3,lxdh1);
                ui->tw_csb->setItem(count,4,csdz1);
            }
            else
            {
                QMessageBox::information(this,"厂商信息表","修改失败");
            }
        }
        else
        {

        }
    }
    else
    {
        QMessageBox::critical(this,"厂商信息表","拒绝修改");
    }
}


void Widget::on_btn_csbclear_clicked()
{
    if(ui->check_csbbj->isChecked() || ui->check_csbtj->isChecked())
    {
        ui->let_csbcsmc->clear();
        ui->let_csbfrdb->clear();
        ui->let_csblxdh->clear();
        ui->let_csbcsdz->clear();
    }
    else
    {
        ui->let_csbcsbh->clear();
        ui->let_csbcsmc->clear();
        ui->let_csbfrdb->clear();
        ui->let_csblxdh->clear();
        ui->let_csbcsdz->clear();
    }
}
//编辑开关
void Widget::on_check_csbbj_clicked(bool checked)
{
    if(checked)
    {
        connect(ui->tw_csb, &QTableWidget::itemClicked,this,&Widget::onitemclickedcsb);
        ui->let_csbcsbh->setReadOnly(true);
        ui->check_csbtj->setCheckable(false);
    }
    else if(ui->check_csbtj->isChecked())
    {
    }
    else
    {
        ui->let_csbcsbh->clear();
//        ui->let_csbcsmc->clear();
//        ui->let_csblxdh->clear();
//        ui->let_csbcsdz->clear();
//        ui->let_csbfrdb->clear();
        disconnect(ui->tw_csb, &QTableWidget::itemClicked,this,&Widget::onitemclickedcsb);
        ui->let_csbcsbh->setReadOnly(false);
        ui->check_csbtj->setCheckable(true);
    }
}

void Widget::on_check_csbtj_clicked(bool checked)
{    
    if(checked)
    {
        QSqlQuery query;
        QString sql1="select * from manufacturer order by 厂商编号";
        query.exec(sql1);
        query.last();
        int csbh1=query.value("厂商编号").toInt();
        csbh1+=1;
        QString csbh=QString("%1").arg(csbh1);
        ui->let_csbcsbh->setText(csbh);
        ui->let_csbcsbh->setReadOnly(true);
        ui->check_csbbj->setCheckable(false);
    }
    else if(ui->check_csbbj->isChecked())
    {
    }
    else
    {
        ui->let_csbcsbh->clear();
        ui->let_csbcsmc->clear();
        ui->let_csbfrdb->clear();
        ui->let_csblxdh->clear();
        ui->let_csbcsdz->clear();
        ui->let_csbcsbh->setReadOnly(false);
        ui->check_csbbj->setCheckable(true);
    }
}
//库存信息表
void Widget::on_btn_kcbcx_clicked()
{
    ui->tw_kcb->setRowCount(0);
    //获取sql查询语句
    int flag=1;
    QString kcbh1=QString("商品编号='%1'").arg(ui->let_kcbbh->text());
    QString sccs1=QString("生产厂商='%1'").arg(ui->let_kcbsccs->text());
    QString spmc1=QString("商品名='%1'").arg(ui->let_kcbspmc->text());
    QString xh1=QString("型号='%1'").arg(ui->let_kcbxh->text());
    QString year1=QString("修改年='%1'").arg(ui->let_kcbyear->text());
    QString moon1=QString("修改月='%1'").arg(ui->let_kcbmoon->text());
    QString day1=QString("修改日='%1'").arg(ui->let_kcbday->text());
    QString endsql1="select * from stock";
    QString endsql2="";
    QString endsql3="";
    if(!ui->let_kcbbh->text().isEmpty())
    {
        endsql3.append(" where ");
        endsql2.append(kcbh1);
    }
    if(!ui->let_kcbsccs->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(sccs1);
    }
    if(!ui->let_kcbspmc->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(spmc1);
    }
    if(!ui->let_kcbxh->text().isEmpty())
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(xh1);
    }
    //日期***************************************************************************************************************************
    if((ui->let_kcbyear->text().isEmpty()) && (ui->let_kcbmoon->text().isEmpty()) && (ui->let_kcbday->text().isEmpty()))
    {

    }
    else if((!ui->let_kcbyear->text().isEmpty()) && (!ui->let_kcbmoon->text().isEmpty()) && (!ui->let_kcbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);
        endsql2.append(" and ");
        endsql2.append(day1);
    }

    else if((!ui->let_kcbyear->text().isEmpty()) && (!ui->let_kcbmoon->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
        endsql2.append(" and ");
        endsql2.append(moon1);
    }
    else if((!ui->let_kcbyear->text().isEmpty())&&(ui->let_kcbmoon->text().isEmpty())&&(ui->let_kcbday->text().isEmpty()))
    {
        if(endsql3.isEmpty())
        {
            endsql3.append(" where ");
        }
        if(!endsql2.isEmpty())
        {
            endsql2.append(" and ");
        }
        endsql2.append(year1);
    }
    else
    {
        QMessageBox::information(this,"库存信息","日期请填写完整");
        flag=0;
    }

   // ************************************************************************************************************
    QString endsql4=" order by 生产厂商,数量";
    endsql1.append(endsql3);
    endsql1.append(endsql2);
    endsql1.append(endsql4);
    //QMessageBox::information(this,"",endsql1);
//获取查询数据
    if(flag)
    {
        QSqlQuery query;
        QString kcbh2;
        QString sccs2;
        QString spmc2;
        QString xh2;
        QString sl2;
        QString year2;
        QString moon2;
        QString day2;
        if(query.exec(endsql1))
        {
            if(query.first())
            {
                query.previous();
                while (query.next())
                {
                    int count=ui->tw_kcb->rowCount();
                    ui->tw_kcb->setRowCount(count+1);
                    ui->tw_kcb->setRowCount(count+1);

                    kcbh2=query.value("商品编号").toString();
                    sccs2=query.value("生产厂商").toString();
                    spmc2=query.value("商品名").toString();
                    xh2=query.value("型号").toString();
                    sl2=query.value("数量").toString();
                    year2=query.value("修改年").toString();
                    moon2=query.value("修改月").toString();
                    day2=query.value("修改日").toString();

                    QTableWidgetItem *spbh=new QTableWidgetItem(kcbh2);
                    QTableWidgetItem *sccs=new QTableWidgetItem(sccs2);
                    QTableWidgetItem *spm=new QTableWidgetItem(spmc2);
                    QTableWidgetItem *xh=new QTableWidgetItem(xh2);
                    QTableWidgetItem *sl=new QTableWidgetItem(sl2);
                    QTableWidgetItem *year=new QTableWidgetItem(year2);
                    QTableWidgetItem *moon=new QTableWidgetItem(moon2);
                    QTableWidgetItem *day=new QTableWidgetItem(day2);

                    ui->tw_kcb->setItem(count,0,spbh);
                    ui->tw_kcb->setItem(count,1,sccs);
                    ui->tw_kcb->setItem(count,2,spm);
                    ui->tw_kcb->setItem(count,3,xh);
                    ui->tw_kcb->setItem(count,4,sl);
                    ui->tw_kcb->setItem(count,5,year);
                    ui->tw_kcb->setItem(count,6,moon);
                    ui->tw_kcb->setItem(count,7,day);
                }
            }
            else
            {
                QMessageBox::information(this,"库存信息","暂无库存");
            }
        }
        else
        {
            QMessageBox::critical(this,"库存信息","库存信息获取失败");
        }
    }
}

void Widget::on_btn_kcbclear_clicked()
{

    ui->let_kcbbh->clear();
    ui->let_kcbsccs->clear();
    ui->let_kcbspmc->clear();
    ui->let_kcbxh->clear();
    ui->let_kcbyear->clear();
    ui->let_kcbmoon->clear();
    ui->let_kcbday->clear();
}


void Widget::on_btn_yjckclear_clicked()
{
    ui->let_ygh->clear();
}

