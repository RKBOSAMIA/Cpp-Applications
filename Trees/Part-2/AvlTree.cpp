#include <iostream>
#include "AvlTree.h"

using namespace std;

int AvlTree::height(const BinaryNode *ptr) const
{
    /***** Complete this function. *****/
    if(ptr != nullptr)
    {
        return ptr->height;
    }
    return -1;
}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

// Reference - Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    comparison_count++;
    if (ptr == nullptr)
        return ptr;
    
    probe_count += 2; //for left and right node
    if(height(ptr->left) - height(ptr->right) > 1)
    {
        comparison_count++;
        probe_count += 2;
        if (height(ptr->left->left) >= height(ptr->left->right))
        {
            ptr = single_right_rotation(ptr);
        }
        else
        {
            ptr = double_left_right_rotation(ptr);
        }
    }
    else if (height(ptr->right) - height(ptr->left) > 1)
    {
        comparison_count++;
        probe_count += 2;
        if (height(ptr->right->right) >= height(ptr->right->left))
        {
            probe_count++;
            ptr = single_left_rotation(ptr);
        }
        else
        {
            probe_count++;
            ptr = double_right_left_rotation(ptr);
        }
    }
    // Recompute the node's height.
    ptr->height = (max(height(ptr->left), height(ptr->right)) + 1);

    comparison_count++;
    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

// Reference :- Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
    /***** Complete this function. *****/
    BinaryNode *binaryNode = k2;

    probe_count++;
    binaryNode = k2->left;

    probe_count += 2;
    k2->left = binaryNode->right;

    probe_count++;
    binaryNode->right = k2;

    probe_count += 2;
    comparison_count++;
    if(height(k2->left) > height(k2->right))
    {
        probe_count++;
        k2->height = height(k2->left) + 1;
    }
    else
    {
        probe_count++;
        k2->height = height(k2->right) + 1;
    }
    return binaryNode;
    
}

// Reference :- Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
    /***** Complete this function. *****/
    BinaryNode *binaryNode;
    BinaryNode *rightRotation;

    probe_count++;
    binaryNode = k3->left;

    probe_count++;
    k3->left = single_left_rotation(binaryNode);

    probe_count++;
    rightRotation = single_right_rotation(k3);

    return rightRotation;
}

// Reference :- Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
    BinaryNode *binaryNode;
    BinaryNode *leftRotation;

    probe_count++;
    binaryNode = k1->right;

    probe_count++;
    k1->right = single_right_rotation(binaryNode);

    probe_count++;
    leftRotation = single_left_rotation(k1);

    return leftRotation;
}

// Reference :- Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
    /***** Complete this function. *****/
    BinaryNode *binaryNode = k1;

    probe_count++;
    binaryNode = k1->right;

    probe_count += 2;
    k1->right = binaryNode->left;

    probe_count++;
    binaryNode->left = k1;

    comparison_count++;
    probe_count += 2;
    if(height(k1->left) > height(k1->right))
    {
        probe_count++;
        k1->height = height(k1->left) + 1;
    }
    else
    {
        probe_count++;
        k1->height = height(k1->right) + 1;
    }

    return binaryNode;
}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}