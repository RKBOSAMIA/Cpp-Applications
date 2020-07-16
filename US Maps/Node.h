#ifndef NODE_H_
#define NODE_H_

#include "City.h"
#include "Coordinate.h"

/**
 * A node of a linked list.
 */
class Node
{
public:
    

    Node *next;  // pointer to the next node in the list

    /**
     * Default Constructor
     */
     Node();

     /**
      * Constructor to set the coordinates
      * @param coordinate sets the row and column
      */
     Node(Coordinate coordinate);

     /**
      * Constructor to read the cities from the city-data file
      * @param coordinate sets the row and column
      */
     Node(City city);

    /**
     * Overloaded > operator to compare two nodes.
     */
    bool operator >(const Node& other);

    /**
     * Overloaded stream output insertion operator
     * to output a node to the output stream.
     * @param outs the output stream.
     * @param node the node to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const Node& node);

    //getter methods
    int get_row();
    int get_col();
    string get_name();
    string get_state();

    //destructor
    ~Node();

private:
    string name;   // city name,  or the empty string for a border location
    string state;  // city state, or the empty string for a border location
    int row;       // print row
    int col;       // print column

    /**
     * Convert a coordinate to a row and a column.
     * @param coordinate the coordinate to convert.
     */
    void convert_coordinate(const Coordinate& coordinate);
};

#endif /* NODE_H_ */