#include "resultworkalgorithmform.h"
#include "ui_resultworkalgorithmform.h"
/**************************************************************************************************/
ResultWorkAlgorithmForm::ResultWorkAlgorithmForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWorkAlgorithmForm)

{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
}
/**************************************************************************************************/
ResultWorkAlgorithmForm::~ResultWorkAlgorithmForm()
{
    delete ui;
}
/**************************************************************************************************/
void ResultWorkAlgorithmForm::setData(TransferGraph obj)
{
    /**************************************************************************************************/
    this->g = obj.getG();
    this->prev = obj.getPrev();
    QString strPath, strMatrix;
    /**************************************************************************************************/
    this->ui->path->clear();
    this->ui->result->clear();
    /**************************************************************************************************/
    this->ui->result->setText(QString::number(obj.getRes()));
    /**************************************************************************************************/
    if(obj.getIs())
    {
        this->ui->Path->setVisible(true);
        for(auto&i:this->prev)
        {
            strPath += (QString::number(i + 1) + " ");
        }
    }
    else this->ui->Path->setVisible(false);
    /**************************************************************************************************/
    this->ui->path->setText(strPath);
    /**************************************************************************************************/
}
/**************************************************************************************************/
void ResultWorkAlgorithmForm::on_Close_clicked()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) this->close();
}
/**************************************************************************************************/
