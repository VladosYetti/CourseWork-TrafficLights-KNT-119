#pragma once
#ifndef WORKING_H
#define WORKING_H
/**************************************************************************************************/
#include <QDialog>
/**************************************************************************************************/
namespace Ui {
  class working;
}

class working : public QDialog
{
  Q_OBJECT

public:
  explicit working(QWidget *parent = nullptr);
  ~working();
public slots:
  void setMaxSizeConnect(int);
signals:
  void getConnect(int a, int b);
private slots:
  void on_Connect_clicked();

private:
  Ui::working *ui;
};

#endif // WORKING_H
/**************************************************************************************************/
