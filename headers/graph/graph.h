#ifndef COURSE_4_GRAPH_H
#define COURSE_4_GRAPH_H

using namespace std;
#include <string>

struct Graph
{
    double** matrix;
    int size;

    Graph(int size);
    ~Graph();
};

void configurationForStartMatrix(int size,double** matrix, double** matrix2);
void SearchMin(const Graph& rGraph,double path_flow,const int* parent,int startNumberOfSymbol,int finishNumberOfSymbol);
void Transplant(const Graph& rGraph, double currentFlow, int i, int j);
double FordFulkersonAlgo(Graph& currentGraph, int startNumberOfSymbol, int finishNumberOfSymbol);


#endif //COURSE_4_GRAPH_H
