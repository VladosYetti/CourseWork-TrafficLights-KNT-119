#include "abstractalgorithmgraph.h"
/**************************************************************************************************/
AbstractAlgorithmGraph::AbstractAlgorithmGraph(QObject *parent) : QObject(parent) {}
/**************************************************************************************************/
int AbstractAlgorithmGraph::max(int a, int b) const { return a < b ? b : a; }
/**************************************************************************************************/
int AbstractAlgorithmGraph::min(int a, int b) const { return a < b ? a : b; }
/**************************************************************************************************/
void AbstractAlgorithmGraph::reverse(QVector<int> &ans)
{
    for(size_t i = 0; i < ans.size() / 2; ++i)
    {
        int tmp = ans[i];
        ans[i] = ans[ans.size() - i - 1];
        ans[ans.size() - i - 1] = tmp;
    }
}
/**************************************************************************************************/
