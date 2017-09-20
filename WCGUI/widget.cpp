#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include "wc.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->dirButton,SIGNAL(clicked(bool)),this,SLOT(wcsSlot()));
    QObject::connect(ui->fileButton,SIGNAL(clicked(bool)),this,SLOT(wcSlot()));
    QObject::connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::wcsSlot()
{
    QString dirName=QFileDialog::getExistingDirectory(this,"Select Dir",QDir::homePath());
    ui->codeEdit->setText(QString("%1").arg(0));
    ui->wordEdit->setText(QString("%1").arg(0));
    ui->lineEdit->setText(QString("%1").arg(0));
    ui->codeLineEdit->setText(QString("%1").arg(0));
    ui->blankLineEdit->setText(QString("%1").arg(0));
    ui->commentLineEdit->setText(QString("%1").arg(0));
}

void Widget::wcSlot()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Select File",QDir::homePath());
    ui->codeEdit->setText(QString("%1").arg(charCount(fileName.toStdString().c_str())));
    ui->wordEdit->setText(QString("%1").arg(wordCount(fileName.toStdString().c_str())));
    ui->lineEdit->setText(QString("%1").arg(lineCount(fileName.toStdString().c_str())));
    int codeLineNum, blankLineNum, commentLineNum;
    multiLineCount(fileName.toStdString().c_str(),codeLineNum,blankLineNum,commentLineNum);
    ui->codeLineEdit->setText(QString("%1").arg(codeLineNum));
    ui->blankLineEdit->setText(QString("%1").arg(blankLineNum));
    ui->commentLineEdit->setText(QString("%1").arg(commentLineNum));
}
