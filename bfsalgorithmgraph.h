#pragma once
#ifndef BFSALGORITHMGRAPH_H
#define BFSALGORITHMGRAPH_H
/**************************************************************************************************/
#include "abstractalgorithmgraph.h"
#include <QObject>
/**************************************************************************************************/
class BFSAlgorithmGraph : public AbstractAlgorithmGraph
{
    Q_OBJECT
public:
    explicit BFSAlgorithmGraph(QObject *parent = nullptr);
    virtual int Algorithm(QVector<QVector<int>>& g, QVector<int>& prev, int s, int f, int n) override;
};
/**************************************************************************************************/
#endif // BFSALGORITHMGRAPH_H
