#include "working.h"
#include "ui_working.h"
/**************************************************************************************************/
working::working(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::working)
{
  ui->setupUi(this);
  this->setWindowTitle("TrafficLightsApp");
}
/**************************************************************************************************/
working::~working()
{
  delete ui;
}
/**************************************************************************************************/
void working::setMaxSizeConnect(int max)
{
  this->ui->Apply->setVisible(false);
  this->ui->Connect->setVisible(true);
  this->ui->Start->setMaximum(max);
  this->ui->Finish->setMaximum(max);
  this->ui->Start->setMinimum(1);
  this->ui->Finish->setMinimum(1);
}
/**************************************************************************************************/
void working::on_Connect_clicked()
{
    emit this->getConnect(this->ui->Start->text().toInt(), this->ui->Finish->text().toInt());
    this->close();
}
