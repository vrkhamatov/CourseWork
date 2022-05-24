#ifndef COURSE_4_MAXFLOWCALCULATION_H
#define COURSE_4_MAXFLOWCALCULATION_H

using namespace std;
#include <string>

#include "../list/list.h"
#include "../graph/edge.h"

double findMaxFlow(List<Edge>& edgeList, string s, string t);

List<Edge> getEdgeList(string fileName);

#endif //COURSE_4_MAXFLOWCALCULATION_H
