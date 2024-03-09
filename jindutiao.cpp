#include "jindutiao.h"
#include "ui_jindutiao.h"

jindutiao::jindutiao(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jindutiao)
{
    ui->setupUi(this);
}

jindutiao::~jindutiao()
{
    delete ui;
}
