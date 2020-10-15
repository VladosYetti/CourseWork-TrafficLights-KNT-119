#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingForm)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
}

SettingForm::~SettingForm()
{
    delete ui;
}

void SettingForm::on_Close_clicked()
{
    this->ui->Close->close();
}
