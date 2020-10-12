#pragma once
#ifndef DIJKSTRAALGORITHMGRAPH_H
#define DIJKSTRAALGORITHMGRAPH_H
/**************************************************************************************************/
#include "abstractalgorithmgraph.h"
#include <QObject>
/**************************************************************************************************/
class DijkstraAlgorithmGraph : public AbstractAlgorithmGraph
{
    Q_OBJECT
public:
    explicit DijkstraAlgorithmGraph(QObject *parent = nullptr);
    virtual int Algorithm(QVector<QVector<int>>&g, QVector<int>& prev, int s, int f, int n) override;
};
/**************************************************************************************************/
#endif // DIJKSTRAALGORITHMGRAPH_H
