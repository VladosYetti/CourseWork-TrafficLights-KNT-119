#include "TransferGraph.h"
/**************************************************************************************************/
TransferGraph::TransferGraph(QString algorithm,  QVector<QVector<int> > g, QVector<int> prev, int res): algorithm(algorithm), g(g), prev(prev), res(res){}
/**************************************************************************************************/
QVector<QVector<int> > TransferGraph::getG(){return this->g;}
/**************************************************************************************************/
QVector<int> TransferGraph::getPrev(){return this->prev;}
/**************************************************************************************************/
int TransferGraph::getRes() {return this->res;}
/**************************************************************************************************/
void TransferGraph::setG(const QVector<QVector<int> > &other)
{
  this->g = other;
}
/**************************************************************************************************/
void TransferGraph::setPrev(const QVector<int> &other)
{
  this->prev = other;
}
/**************************************************************************************************/
void TransferGraph::setRes(const int other)
{
  this->res = other;
}
/**************************************************************************************************/
void TransferGraph::setAlgorithm(const QString algorithm)
{
  this->algorithm = algorithm;
}
/**************************************************************************************************/
QString TransferGraph::getAlgorithm() const
{
  return this->algorithm;
}
/**************************************************************************************************/
TransferGraph::TransferGraph() = default;
/**************************************************************************************************/
