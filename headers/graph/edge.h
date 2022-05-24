#ifndef COURSE_4_EDGE_H
#define COURSE_4_EDGE_H

using namespace std;
#include <string>
#include <utility>
#include <cfloat>
struct Edge
{
public:
    std::string start_;
    std::string finish_;
    size_t capacity_;



    Edge(string start_, string finish_, size_t capacity_)
    {
        this->start_ = std::move(start_);
        this->finish_ = std::move(finish_);
        this->capacity_ = capacity_;
    }

    Edge()
    {
        this->start_ = "";
        this->finish_ = "";
        this->capacity_ = DBL_MIN;
    }
};

#endif //COURSE_4_EDGE_H
