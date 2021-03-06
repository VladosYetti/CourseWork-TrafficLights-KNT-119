#pragma once
#ifndef FORDFULKERSONALGORITHMGRAPH_H
#define FORDFULKERSONALGORITHMGRAPH_H
/**************************************************************************************************/
#include "abstractalgorithmgraph.h"
#include <bfsalgorithmgraph.h>
#include <QObject>
/**************************************************************************************************/
class FordFulkersonAlgorithmGraph : public AbstractAlgorithmGraph
{
    Q_OBJECT
public:
    explicit FordFulkersonAlgorithmGraph(QObject *parent = nullptr);
    virtual int Algorithm(InputData&) override;
    ~FordFulkersonAlgorithmGraph(void);
private:
    BFSAlgorithmGraph* bfs;
};
/**************************************************************************************************/
#endif // FORDFULKERSONALGORITHMGRAPH_H
