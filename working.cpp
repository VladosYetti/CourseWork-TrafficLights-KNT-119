#include "working.h"
#include "ui_working.h"

working::working(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::working)
{
  ui->setupUi(this);
  this->setWindowTitle("TrafficLightsApp");
}

working::~working()
{
  delete ui;
}
