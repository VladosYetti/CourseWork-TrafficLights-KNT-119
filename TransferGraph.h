#pragma once
#ifndef TRANSFERGRAPH_H
#define TRANSFERGRAPH_H
/**************************************************************************************************/
#include <QVector>
/**************************************************************************************************/
class TransferGraph
{
public:
    TransferGraph(bool is, QVector<QVector<int>>g, QVector<int>prev, int res);
    TransferGraph(void);
    bool getIs(void) const;
    QVector<QVector<int>> getG(void);
    QVector<int> getPrev(void);
    int getRes(void);
    void setIs(const bool other);
    void setG(const QVector<QVector<int>>&other);
    void setPrev(const QVector<int>&prev);
    void setRes(const int other);
private:
    bool is;
    QVector<QVector<int>>g;
    QVector<int>prev;
    int res;
};
/**************************************************************************************************/
#endif // TRANSFERGRAPH_H
