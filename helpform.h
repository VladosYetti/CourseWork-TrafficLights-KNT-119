#pragma once
#ifndef HELPFORM_H
#define HELPFORM_H
/**************************************************************************************************/
#include <QDialog>
#include <QIcon>
/**************************************************************************************************/
namespace Ui {
  class HelpForm;
}

class HelpForm : public QDialog
{
  Q_OBJECT

public:
  explicit HelpForm(QWidget *parent = nullptr);
  ~HelpForm();

private slots:
  void on_Close_clicked();

private:
  Ui::HelpForm *ui;
};

#endif // HELPFORM_H
