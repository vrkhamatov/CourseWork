#ifndef COURSE_4_ITERATOR_H
#define COURSE_4_ITERATOR_H


template <class T>
class Iterator
{
public:
    virtual T next() = 0;

    virtual bool has_next() = 0;

    virtual ~Iterator() {};
};


#endif //COURSE_4_ITERATOR_H
