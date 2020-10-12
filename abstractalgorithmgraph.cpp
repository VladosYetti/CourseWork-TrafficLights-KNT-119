#include "abstractalgorithmgraph.h"
/**************************************************************************************************/
AbstractAlgorithmGraph::AbstractAlgorithmGraph(QObject *parent) : QObject(parent) {}
/**************************************************************************************************/
int AbstractAlgorithmGraph::max(int a, int b) const { return a < b ? b : a; }
/**************************************************************************************************/
int AbstractAlgorithmGraph::min(int a, int b) const { return a < b ? a : b; }
/**************************************************************************************************/
