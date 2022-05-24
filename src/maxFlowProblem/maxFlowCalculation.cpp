#include "../../headers/maxFlowProblem/maxFlowCalculation.h"
#include "../../headers/graph/graph.h"
#include "../../headers/map/map.h"
#include <string>
#include <fstream>


List<string> tokenizator(string line, string separator = " ")
{
    int start = 0;
    int end = line.find(separator);
    List<string> splittedLines;

    while (end != -1)
    {
        splittedLines.push_back(line.substr(start, end - start));
        start = end + separator.size();
        end = line.find(separator, start);
    }

    splittedLines.push_back(line.substr(start, end - start));

    return splittedLines;
}

List<Edge> getEdgeList(string fileName)
{
    List<Edge> edgeList;

    ifstream finput;
    finput.open(fileName);

    string line;
    while (getline(finput, line))
    {
        List<string> newEdgeSrting = tokenizator(line, " ");

        auto newEdge_itr = newEdgeSrting.create_iterator();
        string token1 = newEdge_itr->next();
        string token2 = newEdge_itr->next();
        string token3 = newEdge_itr->next();;
        delete newEdge_itr;

        Edge newEdge(token1, token2, stod(token3));
        edgeList.push_back(newEdge);
    }

    finput.close();
    return edgeList;
}

Map<string, int> UniqueVertex(List<Edge>& edgeList)
{
    Map<string, int>* vertexUniqueNumbers  = new Map<string, int>();

    auto itr = edgeList.create_iterator();
    int vertexCount = 0;

    while (itr->has_next())
    {
        Edge edge = itr->next();

        try
        {
            vertexUniqueNumbers->Insert(edge.start_, vertexCount);
            vertexCount++;
        }
        catch (const std::exception&) {}

        try
        {
            vertexUniqueNumbers->Insert(edge.finish_, vertexCount);
            vertexCount++;
        }
        catch (const std::exception&) {}
    }
    delete itr;

    return *vertexUniqueNumbers;
}

Graph buildGraphWithVertex(List<Edge>& edgeList, Map<string, int>& mapOfVertexNumerics)
{
    auto* graph = new Graph(mapOfVertexNumerics.size);

    auto itr = edgeList.create_iterator();
    while (itr->has_next())
    {
        Edge edge = itr->next();
        int numVertex1 = mapOfVertexNumerics.Find(edge.start_);
        int numVertex2 = mapOfVertexNumerics.Find(edge.finish_);
        graph->matrix[numVertex1][numVertex2] = edge.capacity_;
    }
    delete itr;

    return *graph;
}

double findMaxFlow(List<Edge>& edgeList, string s, string t)
{
    Map<string, int> vertexUniqueNumbers = UniqueVertex(edgeList);

    int startNumberOfSymbol = vertexUniqueNumbers.Find(s);
    int finishNumberOfSymbol = vertexUniqueNumbers.Find(t);

    Graph graph = buildGraphWithVertex(edgeList, vertexUniqueNumbers);

    double max_path = FordFulkersonAlgo(graph, startNumberOfSymbol, finishNumberOfSymbol);

    return max_path;
}