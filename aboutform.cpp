#include "aboutform.h"
#include "ui_aboutform.h"
/**************************************************************************************************/
AboutForm::AboutForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
    this->ui->working->addItem("Vladislav Horobets \t KNT-119");
    this->ui->working->addItem("Danil Degtarenko \t KNT-119");
    this->ui->working->addItem("Alexey Pokrepow \t KNT-119");
    this->ui->working->addItem("Danil Sviridenko \t KNT-119");
    this->ui->About->setVisible(false);
}
/**************************************************************************************************/
AboutForm::~AboutForm()
{
    delete ui;
}
/**************************************************************************************************/
void AboutForm::on_close_clicked()
{
    this->close();
}
/**************************************************************************************************/
void AboutForm::on_Duties_clicked()
{
  this->ui->icon->setVisible(false);
  this->ui->Duties->setVisible(false);
  this->ui->about->setVisible(false);
  this->ui->About->setVisible(true);
  QString str;
  QFile file(":/Data/Recourse/Dyties.txt");
  file.open(QIODevice::Text | QIODevice::ReadOnly);
  QTextStream stream(&file);
  str = stream.readAll();
  this->ui->working->clear();
  this->ui->working->addItem(str);
}
/**************************************************************************************************/
void AboutForm::on_About_clicked()
{
  this->ui->icon->setVisible(true);
  this->ui->Duties->setVisible(true);
  this->ui->about->setVisible(true);
  this->ui->About->setVisible(false);
  this->ui->working->clear();
  this->ui->working->addItem("Vladislav Horobets \t KNT-119");
  this->ui->working->addItem("Danil Degtarenko \t KNT-119");
  this->ui->working->addItem("Alexey Pokrepow \t KNT-119");
  this->ui->working->addItem("Danil Sviridenko \t KNT-119");
}
/**************************************************************************************************/
