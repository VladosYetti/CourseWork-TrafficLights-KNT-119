#include "dijkstraalgorithmgraph.h"
/**************************************************************************************************/
DijkstraAlgorithmGraph::DijkstraAlgorithmGraph(QObject *parent) : AbstractAlgorithmGraph(parent) {}
/**************************************************************************************************/
int DijkstraAlgorithmGraph::Algorithm(QVector<QVector<int>> g, QVector<int>& prev, int s, int f, int n)
{
    int min_dist, vertex;
    QVector<int>dist(n, this->inf);
    QVector<bool>color(n, false);
    min_dist = 0;
    vertex = s;
    dist[s] = 0;
    /**************************************************************************************************/
    while(min_dist != this->inf)
    {
        color[vertex] = true;
        for(int i = 0; i < n; ++i)
        {
            if(dist[i] > dist[vertex] + g[vertex][i] and g[vertex][i] > 0)
            {
                dist[i] = dist[vertex] + g[vertex][i];
                prev[i] = vertex;
            }
        }
        min_dist = this->inf;
        for(int i = 0; i < n; ++i)
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
    int curr = f;
    while(curr != -1)
    {
        path.push_back(curr);
        curr = prev[curr];
    }
    /**************************************************************************************************/
    this->reverse(path);
    /**************************************************************************************************/
    emit GraphPath(TransferGraph(true, g, path, dist[f]));
    /**************************************************************************************************/
    return dist[f];
}
