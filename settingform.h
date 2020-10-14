#pragma once
#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include <QDialog>
#include <QColorDialog>
#include <QColor>

namespace Ui {
class SettingForm;
}

class SettingForm : public QDialog
{
    Q_OBJECT

public:
    explicit SettingForm(QWidget *parent = nullptr);
    ~SettingForm();

private slots:
    void on_Close_clicked();

private:
    Ui::SettingForm *ui;
};

#endif // SETTINGFORM_H
