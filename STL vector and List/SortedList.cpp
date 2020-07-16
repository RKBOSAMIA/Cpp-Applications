#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

/***** Complete this file. *****/

void SortedList::prepend(const long value)
{
    this->push_front(value);
}

void SortedList::append(const long value)
{
    this->push_back(value);
}

void SortedList::insert(const long value)
{
    list<Node>::iterator it = begin();
    list<Node>::iterator prev = it;
    it++;

    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }
    list<Node>::insert(it,value);
}

void SortedList::remove(const int index)
{
    list<Node>::iterator it = begin();
    advance(it,index);
    this->erase(it);
}

void SortedList::reverse()
{
    list<Node>::iterator it = begin();
    it++;
    while(it!=end())
    {
        push_front(*it);
        erase(it);
        it++;
    }
}

Node& SortedList::operator[](const int index)
{
    list<Node>::iterator it = begin();
    int idx = 0;
    while(idx!=index)
    {
        it++;
        idx++;
    }
    return *it;
}
bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}