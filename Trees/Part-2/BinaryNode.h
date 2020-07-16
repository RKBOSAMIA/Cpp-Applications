#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    /**
     * Constructor.
     * @param data the data item.
     */
    BinaryNode(const int data)
        : data(data), height(0), left(nullptr), right(nullptr) {}

    /**
     * Constructor.
     * @param data the data item.
     * @param left the left link.
     * @param right the right link.
     */
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right)
      : data(data), height(0), left(left), right(right) {}

    /**
     * Destructor.
     */
    virtual ~BinaryNode() {}

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;
    
};

#endif // BINARY_NODE_H