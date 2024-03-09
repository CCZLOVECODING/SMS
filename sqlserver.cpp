#include "sqlserver.h"

SqlServer::SqlServer()
{

}

bool SqlServer::initSql1()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("LAPTOP-MB4PN1LO");
    db.setDatabaseName("delightsms");
    db.setUserName("delight");
    db.setPassword("123456");
    if (!db.open())
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(nullptr,"连接数据库",db.lastError().text());
        return false;
    }
    else
    {
        return true;
    }
}

bool SqlServer::initSql(QString servername,QString databasename,QString usename,QString password)
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(servername);
    db.setDatabaseName(databasename);
    db.setUserName(usename);
    db.setPassword(password);
    if (!db.open())
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(nullptr,QObject::tr("Databaseerror"),db.lastError().text());
        return false;
    }
    else
    {
        return true;
    }
}



//登录
bool SqlServer::loginUser(QString name,QString password)
{

        QSqlQuery *query=new QSqlQuery;
        QString str=QString("select * from Manager where Maccount= '%1' and Mpassword = '%2'").arg(name,password);
        query->exec(str);
        return query->next();


//    QSqlQuery *query=new QSqlQuery;
//    query->prepare("select * from Manager where Maccount= ? and Mpassword = ?");//限定查询结构
//    query->addBindValue(name);
//    query->addBindValue(password);
//    query->exec();
//    return query->next();
}

//注册
bool SqlServer::registerUser(QString name,QString password)
{
    QSqlQuery *query=new QSqlQuery;
    QString str = QString("insert into Manager(Maccount,Mpassword) values('%1','%2')").arg(name,password);
    return query->exec(str);
}
//修改密码
bool SqlServer::chpd(QString name,QString password,QString password1)
{
    QSqlQuery *query=new QSqlQuery;
    QString str=QString("update Manager set Mpassword='%1' where Maccount= '%2' and Mpassword ='%3'").arg(password1,name,password);
    return query->exec(str);
}
//进货
bool SqlServer::insertStock(QString cs,QString mc,QString xh,QString dj,QString sl,QString zje,QString year,QString moon,QString day,QString ywybh)
{
    QSqlQuery *query=new QSqlQuery;
    QString str = QString("insert into goods values('%1', '%2', '%3','%4','%5','%6','%7','%8','%9','%10')").arg(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh);
    if(!query->exec(str))
        return false;
    return true;
}
//厂商登记
bool SqlServer::insertmfr(QString mfrname,QString faren,QString number,QString mfradd)
{
    QSqlQuery *query=new QSqlQuery;
    QString str = QString("insert into manufacturer values('%1', '%2', '%3','%4')").arg(mfrname,faren,number,mfradd);
    if(!query->exec(str))
    {
        return false;
    }
    else
    {
        return true;
    }
}

//销售登记
bool SqlServer::insertsell(QString cs,QString mc,QString xh,QString dj,QString sl,QString zje,QString year,QString moon,QString day,QString ywybh)
{
    QSqlQuery *query=new QSqlQuery;
    QString str = QString("insert into sell values('%1', '%2', '%3','%4','%5','%6','%7','%8','%9','%10')").arg(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh);
    if(!query->exec(str))
        return false;
    return true;
}

//退货登记
bool SqlServer::retreat(QString cs,QString mc,QString xh,QString dj,QString sl,QString zje,QString year,QString moon,QString day,QString ywybh)
{
    QSqlQuery *query=new QSqlQuery;
    QString str = QString("insert into retreat values('%1', '%2', '%3','%4','%5','%6','%7','%8','%9','%10')").arg(cs,mc,xh,dj,sl,zje,year,moon,day,ywybh);
    if(!query->exec(str))
        return false;
    return true;
}

bool SqlServer::jhinsertstock(QString sccs,QString spmc,QString xh,QString sl,QString year,QString moon,QString day)
{
    QSqlQuery *query1=new QSqlQuery;
    QString sql1=QString("select * from stock where 生产厂商= '%1' and 商品名 = '%2' and 型号='%3'").arg(sccs,spmc,xh);
    if(query1->exec(sql1))
    {

        if(query1->first())
        {
            QSqlQuery *query2=new QSqlQuery;
            int sl1=sl.toInt();
            int sl2=query1->value("数量").toInt();
            sl2=sl1+sl2;
            QString sl3=QString("%1").arg(sl2);
            QString sql2=QString("update stock set 数量='%1',修改年='%2',修改月='%3',修改日='%4' where 生产厂商= '%5' and 商品名 = '%6' and 型号='%7'").arg(sl3,year,moon,day,sccs,spmc,xh);
            return query2->exec(sql2);
        }
        else
        {
            QSqlQuery *query3=new QSqlQuery;
            QString sql3 = QString("insert into stock values('%1', '%2', '%3','%4','%5','%6','%7')").arg(sccs,spmc,xh,sl,year,moon,day);
            return query3->exec(sql3);
        }
    }
    else
    {
        return false;
    }
}









































