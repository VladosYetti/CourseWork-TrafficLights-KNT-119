#include "settingform.h"
#include "ui_settingform.h"
/**************************************************************************************************/
SettingForm::SettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingForm),
    transfer(new Transfer())
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Img/Recourse/traffic-lights.png"));
}
/**************************************************************************************************/
SettingForm::~SettingForm()
{
    delete ui;
    //delete transfer;
}
/**************************************************************************************************/
void SettingForm::on_pushButton_Color1_clicked()
{
    this->transfer->setQColor_1(QColorDialog::getColor(Qt::red,this,tr("Choose color")));
}
/**************************************************************************************************/
void SettingForm::on_pushButton_Color2_clicked()
{
    this->transfer->setQColor_2(QColorDialog::getColor(Qt::yellow,this,tr("Choose color")));
}
/**************************************************************************************************/
void SettingForm::on_pushButton_Color3_clicked()
{
    this->transfer->setQColor_3(QColorDialog::getColor(Qt::green,this,tr("Choose color")));
}
/**************************************************************************************************/
void SettingForm::on_Apply_clicked()
{
    this->transfer->setInterval(this->ui->interval_slider->value());
    this->transfer->setTraffic(this->ui->Traffic_spinBox->value());
    if(this->ui->on->isChecked()){
        this->transfer->setMode(true);
    }
    else{
         this->transfer->setMode(false);
    }
    emit get(transfer);
    this->close();
}
/**************************************************************************************************/
