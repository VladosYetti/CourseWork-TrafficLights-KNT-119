#include "helpform.h"
#include "ui_helpform.h"

HelpForm::HelpForm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::HelpForm)
{
  ui->setupUi(this);
  this->setWindowTitle("TrafficLightsApp");
  this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
}

HelpForm::~HelpForm()
{
  delete ui;
}
