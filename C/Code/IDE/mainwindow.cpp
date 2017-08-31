#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdlib.h>
#include <String.h>
#include <QDebug>
#define cout qDebug()

#include <QTextCodec>   //字符编码转换
#include <QFileDialog>  //文件对话框
#include <stdlib.h>     //system();

enum MyCode
{
    utf_8, gbk
};
enum MyCode flag;

QString path;

int *p;
QTextCodec *codec;
void MainWindow::test()
{
    cout << "MainWindow";
    p = (int *)malloc(sizeof(int));
    *p = 10;

    //QLabel的操作
    ui->label->setText("hello Qt");
    QString str;
    str = ui->label->text();
    cout << "str = " << str;

    //QTextEdit的操作
    ui->textEdit->setText("hello world");
    str = ui->textEdit->toPlainText();
    cout << "str = " << str;

    //codec->toUnicode(char *);
    ui->label->setText(codec->toUnicode("你好"));

}
void freeP()
{
    if(NULL != p)
    {
        free(p);
        p = NULL;
    }
    cout << "free(p)";
}

//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //test();
    flag = utf_8;
    codec = QTextCodec::codecForName("GBK");
    path = "";

}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
    //freeP();
}

//new
void MainWindow::on_actionnew_triggered()
{
    //path = "";
    path.clear();
    ui->textEdit->clear();

}

//utf_8
void MainWindow::on_actionutf_8_triggered()
{
    flag = utf_8;
    ui->label->setText("当前以utf-8编码显示");
//    QString tmp = ui->textEdit->toPlainText();
//    ui->textEdit->setText(QString::fromLocal8Bit(tmp));

    readFile();
}

//gbk
void MainWindow::on_actiongbk_triggered()
{
    flag = gbk;
    ui->label->setText("当前以gbk编码显示");
//    QString tmp = ui->textEdit->toPlainText();
//    ui->textEdit->setText(QString::toLocal8Bit(tmp));

    readFile();
}

//open
void MainWindow::on_actionopen_triggered()
{
    path = QFileDialog::getOpenFileName();
    readFile();

}

void MainWindow::readFile()
{
    //cout << path.toStdString().data();

    if(path.isEmpty())
    {
        cout << "path.isEmpty()";
        return;
    }

    //const char *file = path.toStdString().data();
    //char *file = path.toLocal8Bit().data();

    //cout << file;
    FILE *fp = fopen(path.toLocal8Bit().data(), "rb");
    if(fp == NULL)
    {
        //cout << "fp == NULL";
        perror("open");
        return;
    }
    //cout << "fopen:success";

    char buf[8*1024] = {0};
    QString str;

    //while( fgets(buf, sizeof(buf), fp) != 0)
    while( fread(buf, 1, sizeof(buf), fp) != 0)
    {
        if(utf_8 == flag)
        {
            str += buf;
        }
        else
        {
            str += QString::fromLocal8Bit((const char*)buf);
        }
        memset(buf, 0, sizeof(buf));
        //cout << sizeof(buf);
    }

    ui->textEdit->setText(str);

    fclose(fp);
    fp = NULL;
}

//save as
void MainWindow::on_actionsaveas_triggered()
{
    path = QFileDialog::getSaveFileName();
    writeFile();
}

void MainWindow::writeFile()
{
    if(path.isEmpty())
    {
        cout << "path.isEmpty()";
        return;
    }
    FILE *fp = fopen(path.toLocal8Bit().data() ,"wb");
    if(fp == NULL)
    {
        perror("save as");
        return;
    }

    QString str = ui->textEdit->toPlainText();
    fwrite(str.toStdString().data(), 1, str.toStdString().size(), fp);

    fclose(fp);
    fp = NULL;
}

//undo
void MainWindow::on_actionundo_triggered()
{
    ui->textEdit->undo();
}

//copy
void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

//paste
void MainWindow::on_actionpaste_triggered()
{
    ui->textEdit->paste();
}

//cut
void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
}

//compile
void MainWindow::on_actioncompile_triggered()
{
    if(path == "")
        return;

    QString target = path;
    target.replace(".c", "");

    QString cmd;
    //cmd = QString("gcc %1 -o %2").arg(path).arg(target);
    cmd = "gcc " + path + " -o " + target;
    int flag = system(cmd.toLocal8Bit().data());
    if(flag != 0)
    {
        cmd = "cmd /k" + cmd;
        system(cmd.toLocal8Bit().data());
        return;
    }
    cmd = "cmd /k" + target;
    system(cmd.toLocal8Bit().data());
}

//exit
void MainWindow::on_actionexit_triggered()
{
    exit(0);
}

//save
void MainWindow::on_actionsave_triggered()
{
    //if(path == NULL)
    if(path.isEmpty())
    {
        path = QFileDialog::getSaveFileName();
        if(path.isEmpty())
        {
            return;
        }
    }
    writeFile();
}
