#pragma once
#ifndef ABSTRACTALGORITHMGRAPH_H
#define ABSTRACTALGORITHMGRAPH_H
/**************************************************************************************************/
#include <QObject>
#include <QVector>
#include <QQueue>
#include "TransferGraph.h"
#include "inputdata.h"
/**************************************************************************************************/
class AbstractAlgorithmGraph : public QObject
{
    Q_OBJECT
public:
    explicit AbstractAlgorithmGraph(QObject *parent = nullptr);
    virtual int Algorithm(InputData&) = 0;
    int max(int a, int b) const;
    int min(int a, int b) const;
    void reverse(QVector<int>& ans);
protected:
    const int inf = 0x3F3F3F3F;
signals:
    void GraphPath(TransferGraph other);
};
/**************************************************************************************************/
#endif // ABSTRACTALGORITHMGRAPH_H
