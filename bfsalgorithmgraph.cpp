#include "bfsalgorithmgraph.h"
/**************************************************************************************************/
BFSAlgorithmGraph::BFSAlgorithmGraph(QObject *parent) : AbstractAlgorithmGraph(parent) {}
/**************************************************************************************************/
int BFSAlgorithmGraph::Algorithm(InputData& data)
{
    QVector<bool>dist(data.getN() + 1, false);
    QQueue<int>q;
    q.push_back(data.getStart());
    /**************************************************************************************************/
    while(!q.empty())
    {
        int tmp = q.front();
        dist[tmp] = true;
        q.pop_front();
        for(int i = 0 ; i < data.getN(); ++i)
        {
            if(!dist[i] and data.getG()[tmp][i] > 0)
            {
                q.push_back(i);
                data.getPrev()[i] = tmp;
            }
        }
    }
    /**************************************************************************************************/
    QVector<int>path;
    int curr = data.getFinish();
    while(curr != -1)
    {
        path.push_back(curr);
        curr = data.getPrev()[curr];
    }
    /**************************************************************************************************/
    this->reverse(path);
    /**************************************************************************************************/
    emit this->GraphPath(TransferGraph("BFS", data.getG(), path, dist[data.getFinish()]));
    /**************************************************************************************************/
    return dist[data.getFinish()] == true;
}
/**************************************************************************************************/
