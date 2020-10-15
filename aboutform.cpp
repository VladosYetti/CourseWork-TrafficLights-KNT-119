#include "aboutform.h"
#include "ui_aboutform.h"

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
}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_close_clicked()
{
    this->close();
}


