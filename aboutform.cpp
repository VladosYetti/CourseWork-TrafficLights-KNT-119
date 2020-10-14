#include "aboutform.h"
#include "ui_aboutform.h"

AboutForm::AboutForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
<<<<<<< HEAD
    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
    this->ui->working->addItem("Vladislav Horobets \t KNT-119");
    this->ui->working->addItem("Danil Degtarenko \t KNT-119");
    this->ui->working->addItem("Alexey Pokrepow \t KNT-119");
    this->ui->working->addItem("Danil Sviridenko \t KNT-119");
=======
    this->setWindowIcon(QIcon(""));
    this->ui->working->addItem("Vladesav Horobets \t KNT119");
    this->ui->working->addItem("Danil Degtarenko \t KNT119");
    this->ui->working->addItem("Alexei Pokrepow \t KNT119");
    this->ui->working->addItem("Danil Sviridenko \t KNT119");

>>>>>>> db10660808d1ba441088f2abffa43c2e16e7694e
}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_close_clicked()
{
    this->close();
}


