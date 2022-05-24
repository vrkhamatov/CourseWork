using namespace std;
#include <string>
#include <climits>
#include <cfloat>
#include "../../headers/graph/graph.h"
#include "../../headers/queue/queue.h"

void Transplant(const Graph& rGraph, double currentFlow, int i, int j){
    rGraph.matrix[j][i] -= currentFlow;
    rGraph.matrix[i][j] += currentFlow;
}

void configurationForStartMatrix(int size,const Graph& rGraph, const Graph& graph){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            rGraph.matrix[i][j] = graph.matrix[i][j];
}

Graph::Graph(int size)
{
    this->size = size;
    matrix = new double* [size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    }
}

Graph::~Graph()
{
    delete [] matrix;
}


bool breadthFirstSearch(Graph& rGraph, int s, int t, int* parent)
{
    bool* marked = new bool[rGraph.size];
    for (int i = 0; i < rGraph.size; i++)
        marked[i] = false;

    Queue<int> queue;
    queue.push(s);
    marked[s] = true;
    parent[s] = -1;

    while (!queue.empty()) {
        int i = queue.front();
        queue.pop();

        for (int j = 0; j < rGraph.size; j++) {
            if (!marked[j] && rGraph.matrix[i][j] > 0) {
                if (j == t) {
                    parent[j] = i;
                    return true;
                }

                queue.push(j);
                parent[j] = i;
                marked[j] = true;
            }
        }
    }

    return false;
}



double FordFulkersonAlgo(Graph& currentGraph, int startNumberOfSymbol, int finishNumberOfSymbol)
{
    size_t size = currentGraph.size;
    Graph rGraph(size);

    configurationForStartMatrix(size, rGraph, currentGraph);

    auto maximumFlow = DBL_MIN;
    int* parent = new int[size];
    while (breadthFirstSearch(rGraph, startNumberOfSymbol, finishNumberOfSymbol, parent))
    {
        double currentFlow = INT_MAX;

        for (int i = finishNumberOfSymbol; i != startNumberOfSymbol; i = parent[i])
        {
            int j = parent[i];
            if (currentFlow <= rGraph.matrix[j][i])
                currentFlow = currentFlow;
            else { currentFlow = rGraph.matrix[j][i]; }
        }

        for (int i = finishNumberOfSymbol; i != startNumberOfSymbol; i = parent[i])
        {
            int j = parent[i];
            Transplant(rGraph, currentFlow, i, j);
        }

        maximumFlow += currentFlow;
    }

    return maximumFlow;
}
