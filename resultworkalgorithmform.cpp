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

    QString strPath;
    /**************************************************************************************************/
    this->ui->path->clear();
    this->ui->result->clear();
    /**************************************************************************************************/
    if(obj.getAlgorithm() == "BFS")
    {
        this->ui->Viev->setVisible(true);
        this->ui->ResultGroup->setVisible(false);
        this->ui->path->setVisible(true);
        this->ui->Path->setVisible(true);
        this->prev = obj.getPrev();
        for(auto&i:this->prev)
        {
          strPath += QString::number(i + 1) + " ";
        }
        this->ui->path->setText(strPath);
        if(obj.getRes() == 1) this->ui->result->setText("All right, have a good trip");
        else this->ui->result->setText("Stop");
    }
    else if(obj.getAlgorithm() == "DIJKSTRA")
    {
        this->ui->Viev->setVisible(true);
        this->ui->ResultGroup->setVisible(true);
        this->ui->Viev->setVisible(true);
        this->ui->ResultGroup->setVisible(true);
        this->ui->path->setVisible(true);
        this->ui->Path->setVisible(true);
        this->prev = obj.getPrev();
        for(auto&i:this->prev)
        {
          strPath += QString::number(i + 1) + " ";
        }
        this->ui->path->setText(strPath);
        this->ui->Text_Green->setText(" 1 - 30");
        this->ui->Text_Yellow->setText("30 - 60");
        this->ui->Text_Red->setText("60 - 100");
        this->ui->result->setText(QString::number(obj.getRes()));
    }
    else if(obj.getAlgorithm() == "FORD-FULKERSON")
    {
        this->ui->Viev->setVisible(false);
        this->ui->ResultGroup->setVisible(true);
        this->ui->path->setVisible(false);
        this->ui->Path->setVisible(false);
        this->ui->Text_Green->setText(" 1 - 30");
        this->ui->Text_Yellow->setText("30 - 65");
        this->ui->Text_Red->setText("65 - 99");
        this->ui->result->setText(QString::number(obj.getRes()));
    }
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
void ResultWorkAlgorithmForm::on_Viev_clicked()
{
    emit path(this->prev);
}
/**************************************************************************************************/
