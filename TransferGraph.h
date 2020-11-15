#pragma once
#ifndef TRANSFERGRAPH_H
#define TRANSFERGRAPH_H
/**************************************************************************************************/
#include "root.h"
/**************************************************************************************************/
class TransferGraph
{
public:
    explicit TransferGraph(QString algorithm, QVector<QVector<int>>g, QVector<int>prev, int res);
    explicit TransferGraph(void);
    QVector<QVector<int>> getG(void);
    QVector<int> getPrev(void);
    int getRes(void);
    void setG(const QVector<QVector<int>>&other);
    void setPrev(const QVector<int>&prev);
    void setRes(const int other);
    void setAlgorithm(const QString algorithm);
    QString getAlgorithm(void) const;
private:
    QString algorithm;
    QVector<QVector<int>>g;
    QVector<int>prev;
    int res;
};
/**************************************************************************************************/
#endif // TRANSFERGRAPH_H
