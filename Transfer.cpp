#include "Transfer.h"
Transfer::Transfer(QColor color_1, QColor color_2, QColor color_3, int interval, int traffic, bool mode)
  : color_1(color_1),color_2(color_2),color_3(color_3), interval(interval), traffic(traffic), mode(mode){}
/**************************************************************************************************/
QColor Transfer::getQColor_1() { return this->color_1; }
/**************************************************************************************************/
QColor Transfer::getQColor_2() { return this->color_2; }
/**************************************************************************************************/
QColor Transfer::getQColor_3() { return this->color_3; }
/**************************************************************************************************/
int Transfer::getInterval()    { return this->interval;}
/**************************************************************************************************/
int Transfer::getTraffic()     {return this->traffic;  }
/**************************************************************************************************/
bool Transfer::getMode()       {return this->mode;     }
/**************************************************************************************************/
void Transfer::setQColor_1(const QColor other)
{
  this->color_1 = other;
}
/**************************************************************************************************/
void Transfer::setQColor_2(const QColor other)
{
  this->color_2 = other;
}
/**************************************************************************************************/
void Transfer::setQColor_3(const QColor other)
{
  this->color_3 = other;
}
/**************************************************************************************************/
void Transfer::setInterval(const int other)
{
  this->interval = other;
}
/**************************************************************************************************/
void Transfer::setMode(const bool other)
{
  this->mode = other;
}
/**************************************************************************************************/
void Transfer::setTraffic(const int other)
{
  this->traffic = other;
}
/**************************************************************************************************/
