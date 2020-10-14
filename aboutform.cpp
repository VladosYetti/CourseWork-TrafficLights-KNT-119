#include "aboutform.h"
#include "ui_aboutform.h"

AboutForm::AboutForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);
    this->setWindowTitle("TrafficLightsApp");
    this->setWindowIcon(QIcon(""));
    this->ui->working->addItem("Vladesav Horobets \t KNT119");
    this->ui->working->addItem("Danil Degtarenko \t KNT119");
    this->ui->working->addItem("Alexei Pokrepow \t KNT119");
    this->ui->working->addItem("Danil Sviridenko \t KNT119");

}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_close_clicked()
{
    this->close();
}


