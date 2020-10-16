#pragma once
#ifndef TRANSFER_H
#define TRANSFER_H
/**************************************************************************************************/
#include <QColor>
/**************************************************************************************************/
struct Transfer
{
    Transfer(QColor color_1=Qt::red, QColor color_2=Qt::yellow, QColor color_3=Qt::green):
        color_1(color_1),color_2(color_2),color_3(color_3){}

  QColor color_1;
  QColor color_2;
  QColor color_3;
  int interval;
  int traffic;
  bool mode;
};
/**************************************************************************************************/
#endif // TRANSFER_H
