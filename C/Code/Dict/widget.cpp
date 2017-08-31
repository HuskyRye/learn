#include "widget.h"
#include "ui_widget.h"
#include "dict.h"
#include <QTextCodec>
#include <QDebug>
#define cout qDebug()

struct dict *p;

int dict_size;

QTextCodec *codec;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    dict_size = open_dict(&p, "../dict.txt");
    if(dict_size == 0)
    {
        return;
    }
    codec = QTextCodec::codecForName("GBK");
}

Widget::~Widget()
{
    delete ui;
    if(p != NULL)
    {
        free_dict(p, dict_size);
    }
}

void Widget::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    if(str.isEmpty())
    {
        return;
    }

    char content[2048] = {0};
    if( search_dict(p, dict_size, codec->fromUnicode(str).data(), content) == 0)
    {
        ui->label->setText("no such word");
    }
    else
    {
        ui->label->setText( codec->toUnicode(content) );
    }

}
