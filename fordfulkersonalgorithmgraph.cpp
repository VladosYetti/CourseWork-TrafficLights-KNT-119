#include "fordfulkersonalgorithmgraph.h"
/**************************************************************************************************/
FordFulkersonAlgorithmGraph::FordFulkersonAlgorithmGraph(QObject *parent) : AbstractAlgorithmGraph(parent) { this->bfs = new BFSAlgorithmGraph(nullptr); }
/**************************************************************************************************/
int FordFulkersonAlgorithmGraph::Algorithm(QVector<QVector<int>> g, QVector<int> &prev, int s, int f, int n)
{
    TransferGraph obj; obj.g = g;
    int flow, path = 0;
    /**************************************************************************************************/
    while(bfs->Algorithm(g, prev, s, f, n))
    {
        flow = this->inf;
        for(int i = f; i != s; i = prev[i]) { flow = this->min(flow, g[prev[i]][i]); }
        for(int i = f; i != s; i = prev[i])
        {
            g[prev[i]][i] -= flow;
            g[i][prev[i]] += flow;
        }
        path += flow;
    }
    obj.is = false;
    obj.res = path;
    obj.prev = prev;
    /**************************************************************************************************/
    emit GraphPath(obj);
    /**************************************************************************************************/
    return path;
}
/**************************************************************************************************/
FordFulkersonAlgorithmGraph::~FordFulkersonAlgorithmGraph() { delete this->bfs;}
/**************************************************************************************************/
