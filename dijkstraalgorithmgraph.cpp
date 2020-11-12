#include "dijkstraalgorithmgraph.h"
/**************************************************************************************************/
DijkstraAlgorithmGraph::DijkstraAlgorithmGraph(QObject *parent) : AbstractAlgorithmGraph(parent) {}
/**************************************************************************************************/
int DijkstraAlgorithmGraph::Algorithm(InputData& data)
{
    int min_dist, vertex;
    QVector<int>dist(data.getN() + 1, this->inf);
    QVector<bool>color(data.getN() + 1, false);
    min_dist = 0;
    vertex = data.getStart();
    dist[data.getStart()] = 0;
    /**************************************************************************************************/
    while(min_dist != this->inf)
    {
        color[vertex] = true;
        for(int i = 0; i < data.getN(); ++i)
        {
            if(dist[i] > dist[vertex] + data.getG()[vertex][i] and data.getG()[vertex][i] > 0)
            {
                dist[i] = dist[vertex] + data.getG()[vertex][i];
                data.getPrev()[i] = vertex;
            }
        }
        min_dist = this->inf;
        for(int i = 0; i < data.getN(); ++i)
        {
            if(!color[i] and min_dist > dist[i])
            {
                min_dist = dist[i];
                vertex = i;
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
    emit GraphPath(TransferGraph("DIJKSTRA", data.getG(), path, dist[data.getFinish()]));
    /**************************************************************************************************/
    return dist[data.getFinish()];
}
