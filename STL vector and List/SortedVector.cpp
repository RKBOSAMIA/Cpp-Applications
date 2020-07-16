#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

/***** Complete this file. *****/

void SortedVector::prepend(const long value)
{
    vector<Node>::insert(begin(),value);
}

void SortedVector::append(const long value)
{
    push_back(value);
}

void SortedVector::insert(const long value)
{
    vector<Node>::iterator it = begin();
    vector<Node>::iterator prev = it;

    it++;

    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }
    vector<Node>::insert(it,value);
}

void SortedVector::remove(const int index)
{
    vector<Node>::iterator it = begin();
    advance(it,index);
    erase(it);
}

void SortedVector::reverse()
{
    vector<Node>::iterator it = begin();
    it++;
    while(it!=end())
    {
        vector<Node>::insert(begin(),*it);
        erase(it);
        it++;
    }
}

bool SortedVector::check() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}