#pragma once
#ifndef TRANSFERGRAPH_H
#define TRANSFERGRAPH_H
/**************************************************************************************************/
#include <QVector>
/**************************************************************************************************/
struct TransferGraph
{
    TransferGraph(bool is, QVector<QVector<int>>g, QVector<int>prev, int res) : is(is), g(g), prev(prev), res(res){}
    TransferGraph() = default;
    bool is;
    QVector<QVector<int>>g;
    QVector<int>prev;
    int res;
};
/**************************************************************************************************/
#endif // TRANSFERGRAPH_H
