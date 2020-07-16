#include <iostream>
#include "Node.h"

/***** Complete this file. *****/

long Node::constructor_count = 0;
long Node::destructor_count = 0;
long Node::assign_count = 0;
long Node::copy_count = 0;

Node::Node(const long the_value)
{
    this->value = the_value;
    Node::constructor_count++;
}

Node::Node(const Node& other)
{
    this->value = other.value;
    Node::copy_count++;
}

Node& Node:: operator=(const Node& rhs)
{
    this->value = rhs.value;
    Node::assign_count++;
}

Node :: ~Node()
{
    Node::destructor_count++;
}

long Node :: get_value() const
{
    return this->value;
}

long Node :: get_constructor_count()
{
    return Node::constructor_count;
}

long Node :: get_copy_count()
{
    return Node::copy_count;
}

long Node :: get_assign_count()
{
    return Node::assign_count;
}

long Node :: get_destructor_count()
{
    return Node::destructor_count;
}

void Node :: reset()
{
    Node::constructor_count = 0;
    Node::copy_count = 0;
    Node::assign_count = 0;
    Node::destructor_count = 0;
}

bool Node :: operator == (const Node& other) const
{
    if(this->value == other.value)
    {
        return true;
    }
    return false;
}

bool Node :: operator >= (const Node& other) const
{
    if(this->value >= other.value)
    {
        return true;
    }
    return false;
}

bool Node :: operator <= (const Node& other) const
{
    if(this->value <= other.value)
    {
        return true;
    }
    return false;
}
