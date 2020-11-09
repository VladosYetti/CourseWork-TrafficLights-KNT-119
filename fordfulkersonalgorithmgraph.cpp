#include "fordfulkersonalgorithmgraph.h"
/**************************************************************************************************/
FordFulkersonAlgorithmGraph::FordFulkersonAlgorithmGraph(QObject *parent) : AbstractAlgorithmGraph(parent) { this->bfs = new BFSAlgorithmGraph(nullptr); }
/**************************************************************************************************/
int FordFulkersonAlgorithmGraph::Algorithm(InputData& data)
{
    TransferGraph obj; obj.setG(data.getG());
    int flow, path = 0;
    /**************************************************************************************************/
    while(bfs->Algorithm(data))
    {
        flow = this->inf;
        for(int i = data.getFinish(); i != data.getStart(); i = data.getPrev()[i]) { flow = this->min(flow, data.getG()[data.getPrev()[i]][i]); }
        for(int i = data.getFinish(); i != data.getStart(); i = data.getPrev()[i])
        {
            data.getG()[data.getPrev()[i]][i] -= flow;
            data.getG()[i][data.getPrev()[i]] += flow;
        }
        path += flow;
    }
    obj.setIs(false);
    obj.setRes(path);
    obj.setPrev(data.getPrev());
    /**************************************************************************************************/
    emit GraphPath(obj);
    /**************************************************************************************************/
    return path;
}
/**************************************************************************************************/
FordFulkersonAlgorithmGraph::~FordFulkersonAlgorithmGraph() { delete this->bfs;}
/**************************************************************************************************/
