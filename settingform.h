#pragma once
#ifndef SETTINGFORM_H
#define SETTINGFORM_H
/**************************************************************************************************/
#include <QDialog>
#include <QColorDialog>
#include <QColor>
#include "Transfer.h"
/**************************************************************************************************/
namespace Ui {
class SettingForm;
}
/**************************************************************************************************/
class SettingForm : public QDialog
{
    Q_OBJECT

public:
    explicit SettingForm(QWidget *parent = nullptr);
    ~SettingForm();

private slots:
    void on_Close_clicked();

    void on_pushButton_Color1_clicked();

    void on_pushButton_Color2_clicked();

    void on_pushButton_Color3_clicked();

    void on_Apply_clicked();

private:
    Ui::SettingForm *ui;
    Transfer* transfer;
signals:
    void get(Transfer* transfer);
};
/**************************************************************************************************/
#endif // SETTINGFORM_H
