#ifndef SQLSERVER_H
#define SQLSERVER_H
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "QMessageBox"
class SqlServer
{
public:
    SqlServer();
    bool initSql1();
    bool initSql(QString servername,QString databasename,QString usename,QString password);
    bool registerUser(QString name,QString password);
    bool loginUser(QString name,QString password);
    bool insertStock(QString mc,QString cs,QString xh,QString dj,QString sl,QString year,QString moon,QString day,QString ywybh,QString zje);
    bool chpd(QString name,QString password,QString password1);
    bool insertmfr(QString mfrname,QString faren,QString number,QString mfradd);
    bool insertsell(QString cs,QString mc,QString xh,QString dj,QString sl,QString zje,QString year,QString moon,QString day,QString ywybh);
    bool retreat(QString cs,QString mc,QString xh,QString dj,QString sl,QString zje,QString year,QString moon,QString day,QString ywybh);
    bool jhinsertstock(QString sccs,QString spmc,QString xh,QString sl,QString year,QString moon,QString day);
    QSqlQuery *query;
    QSqlDatabase db;
};
#endif // SQLSERVER_H
