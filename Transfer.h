#pragma once
#ifndef TRANSFER_H
#define TRANSFER_H
/**************************************************************************************************/
#include "root.h"
/**************************************************************************************************/
class Transfer
{
public:
    explicit Transfer(QColor color_1=Qt::red, QColor color_2=Qt::yellow, QColor color_3=Qt::green, int interval = 1000, int traffic = 0, bool mode = false);
    QColor getQColor_1(void);
    QColor getQColor_2(void);
    QColor getQColor_3(void);
    int getInterval(void);
    int getTraffic(void);
    bool getMode(void);
    void setQColor_1(const QColor other);
    void setQColor_2(const QColor other);
    void setQColor_3(const QColor other);
    void setInterval(const int other);
    void setMode(const bool other);
    void setTraffic(const int other);
private:
  QColor color_1;
  QColor color_2;
  QColor color_3;
  int interval;
  int traffic;
  bool mode;
};
/**************************************************************************************************/
#endif // TRANSFER_H
