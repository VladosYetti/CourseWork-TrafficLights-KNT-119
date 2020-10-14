#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingForm)
{
    ui->setupUi(this);
<<<<<<< HEAD
    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
=======
    this->setWindowIcon(QIcon(""));
>>>>>>> db10660808d1ba441088f2abffa43c2e16e7694e
}

SettingForm::~SettingForm()
{
    delete ui;
}

void SettingForm::on_Close_clicked()
{
    this->ui->Close->close();
}
