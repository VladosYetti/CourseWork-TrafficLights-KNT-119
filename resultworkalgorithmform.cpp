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
    this->g = obj.g;
    this->prev = obj.prev;
    QString strPath, strMatrix;
    /**************************************************************************************************/
    this->ui->path->clear();
    this->ui->matrixlist->clear();
    this->ui->result->clear();
    /**************************************************************************************************/
    this->ui->result->setText(QString::number(obj.res));
    /**************************************************************************************************/
    if(obj.is)
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
    for(int i = 0; i  < this->g.size(); ++i)
    {
        strMatrix.clear();
        for(int j = 0; j < this->g[i].size(); ++j)
        {
            strMatrix += QString::number(g[i][j]) + "\t";
        }
        this->ui->matrixlist->addItem(strMatrix);
    }
}
/**************************************************************************************************/
void ResultWorkAlgorithmForm::on_Close_clicked()
{
    if(QMessageBox::question(this, tr("TrafficLightsApp"), tr("Are you sure?"), QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) this->close();
}
/**************************************************************************************************/
