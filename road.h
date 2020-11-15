#pragma once
#ifndef ROAD_H
#define ROAD_H
/**************************************************************************************************/
#include "root.h"
#include <QObject>
#include <trafficlights.h>
/**************************************************************************************************/
class Road : public Root
{
  Q_OBJECT
public:
  explicit Road(QObject* parent = nullptr);
  TrafficLights *getLeft(void);
  TrafficLights *getRight(void);
  void setLeft (TrafficLights* left);
  void setRight(TrafficLights* right);
  QLineF getLine(void);
private:
  TrafficLights* left;
  TrafficLights* right;
};
/**************************************************************************************************/
#endif // ROAD_H
