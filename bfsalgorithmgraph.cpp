#include "bfsalgorithmgraph.h"
/**************************************************************************************************/
BFSAlgorithmGraph::BFSAlgorithmGraph(QObject *parent) : AbstractAlgorithmGraph(parent) {}
/**************************************************************************************************/
int BFSAlgorithmGraph::Algorithm(QVector<QVector<int>> g, QVector<int>& prev, int s, int f, int n)
{
    QVector<bool>dist(n, false);
    QQueue<int>q;
    q.push_back(s);
    /**************************************************************************************************/
    while(!q.empty())
    {
        int tmp = q.front();
        dist[tmp] = true;
        q.pop_front();
        for(int i = 0 ; i < n; ++i)
        {
            if(!dist[i] and g[tmp][i] > 0)
            {
                q.push_back(i);
                prev[i] = tmp;
            }
        }
    }
    /**************************************************************************************************/
    QVector<int>path;
    int curr = f - 1;
    while(curr != -1)
    {
        path.push_back(curr);
        curr = prev[curr];
    }
    /**************************************************************************************************/
    this->reverse(path);
    /**************************************************************************************************/
    emit this->GraphPath(TransferGraph(true, g, path, dist[f]));
    /**************************************************************************************************/
    return dist[f] == true;
}
/**************************************************************************************************/
