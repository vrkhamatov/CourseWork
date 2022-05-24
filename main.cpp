#include <iostream>
#include "headers/maxFlowProblem/maxFlowCalculation.h"

using namespace std;

int main()
{
    List<Edge> listOfEdge = getEdgeList("Graph.txt");

     double flow = findMaxFlow(listOfEdge, "A", "D");

    cout << "Maximum flow is: " << flow;

    return 0;
}