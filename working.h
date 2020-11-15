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
  void setMaxSizeAlgorithm(int, QString);
signals:
  void getConnect(int a, int b);
  void getAlgorithm(int a, int b, QString str);
private slots:
  void on_Connect_clicked();

  void on_Apply_clicked();

private:
  Ui::working *ui;
  QString str;
};

#endif // WORKING_H
/**************************************************************************************************/
