#include <math.h>
#include "Node.h"

/***** Complete this class. *****/

void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

Node :: Node()
{

}
Node :: Node(Coordinate coordinate)
{
    this->name = "";
    this->state = "";
    this->convert_coordinate(coordinate);
    this->next = NULL;
}
Node :: Node(City city)
{
    this->name = city.get_name();
    this->state = city.get_state();
    this->convert_coordinate(city.get_coordinate());
    this->next = NULL;
}

bool Node :: operator >(const Node& other)
{
    if (this->row > other.row)
        return true; 
    else if (this->row == other.row && this->col >= other.col)
        return true;
    else
        return false;
}

ostream& operator <<(ostream& outs, const Node& node)
{ 
    //Returns # if boundary else returns state and city names
    if(node.name.empty())
        outs<<"#";
    else
        outs<<"*"<<node.name<<" "<<node.state;
    return outs;
}

int Node:: get_row()
{
    return row;
}

int Node:: get_col()
{
    return col;
}

string Node:: get_name()
{
    return name;
}

string Node:: get_state()
{
    return state;
}
Node :: ~Node()
{

}