#pragma once
#ifndef TRANSFER_H
#define TRANSFER_H
#include <QColor>
struct Transfer
{
    Transfer(QColor color1=Qt::red, QColor color2=Qt::yellow, QColor color3=Qt::green):
        color1(color1),color2(color2),color3(color3){}

  QColor color1;
  QColor color2;
  QColor color3;
  int interval;
  int traffic;
  bool mode;
};
#endif // TRANSFER_H
