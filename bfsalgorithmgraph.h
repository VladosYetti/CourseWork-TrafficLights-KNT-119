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
    virtual int Algorithm(InputData&) override;
};
/**************************************************************************************************/
#endif // BFSALGORITHMGRAPH_H
