#ifndef JINDUTIAO_H
#define JINDUTIAO_H

#include <QWidget>

namespace Ui {
class jindutiao;
}

class jindutiao : public QWidget
{
    Q_OBJECT

public:
    explicit jindutiao(QWidget *parent = nullptr);
    ~jindutiao();

private:
    Ui::jindutiao *ui;
};

#endif // JINDUTIAO_H
