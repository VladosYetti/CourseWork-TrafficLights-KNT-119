#pragma once
#ifndef INPUTDATA_H
#define INPUTDATA_H
#include <QVector>
/**************************************************************************************************/
class InputData
{
public:
  InputData(QVector<QVector<int>>&g, QVector<int>&prev, int& s, int& f, int& n);
  InputData(void);
  QVector<QVector<int>>& getG(void);
  void setG(QVector<QVector<int>>&g);
  QVector<int>& getPrev(void);
  void setStart(const int s);
  void setFinish(const int f);
  void setN(const int n);
  int& getN(void);
  int& getStart(void);
  int& getFinish(void);
private:
  QVector<QVector<int>> g;
  QVector<int> prev;
  int s;
  int f;
  int n;
};
/**************************************************************************************************/
#endif // INPUTDATA_H
