#include "resultworkalgorithmform.h"
#include "ui_resultworkalgorithmform.h"
/**************************************************************************************************/
ResultWorkAlgorithmForm::ResultWorkAlgorithmForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWorkAlgorithmForm)

{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(""));
}
/**************************************************************************************************/
ResultWorkAlgorithmForm::~ResultWorkAlgorithmForm()
{
    delete ui;
}
/**************************************************************************************************/
void ResultWorkAlgorithmForm::setData(QVector<QVector<int> >g, QVector<int>path, int res)
{
    /**************************************************************************************************/
    this->g = g;
    this->prev = path;
    QString strPath, strMatrix;
    /**************************************************************************************************/
    this->ui->path->clear();
    this->ui->matrix->clear();
    this->ui->result->clear();
    /**************************************************************************************************/
    this->ui->result->setText(QString::number(res));
    for(auto&i:this->prev)
    {
        strPath += (QString::number(i + 1) + " ");
    }
    /**************************************************************************************************/
    this->ui->path->setText(strPath);
    /**************************************************************************************************/
    for(int i = 0; i  < this->g.size(); ++i)
    {
        for(int j = 0; j < this->g[i].size(); ++j)
        {
            strMatrix += QString::number(g[i][j]) + "\t ";
        }
        strMatrix += "\n";
    }
    /**************************************************************************************************/
    this->ui->matrix->setText(strMatrix);}
/**************************************************************************************************/
void ResultWorkAlgorithmForm::on_Close_clicked()
{
    this->close();
}
/**************************************************************************************************/
