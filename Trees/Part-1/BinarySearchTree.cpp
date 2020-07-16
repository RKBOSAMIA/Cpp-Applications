#include <string>
#include "BinarySearchTree.h"

using namespace std;

int BinarySearchTree::height(const BinaryNode *ptr) const
{
    /***** Complete this function. *****/
    if(ptr == NULL)
    {
        return -1;
    }
    if(height(ptr->left) < height(ptr->right))
    {
        return (height(ptr->right) + 1);
    }
    else
    {
        return (height(ptr->left) + 1);
    }
    
}
// Reference:- Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
    /***** Complete this function. *****/
    while(ptr->left !=nullptr && ptr != nullptr)
    {
        ptr = ptr->left;
    }
    return ptr;
}

// Reference:- Book: Data Structures and Algorithms Analysis in C++, 4th edition
BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
    /***** Complete this function. *****/
    while(ptr->right !=nullptr && ptr != nullptr)
    {
        ptr = ptr->right;
    }
    return ptr;

}

// Reference:- Book: Data Structures and Algorithms Analysis in C++, 4th edition
bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{
    /***** Complete this function. *****/
    while(ptr != nullptr)
    {
        if(ptr->data == data)
        {
            return true;
        }
        else if(ptr->data > data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }     
    }
    return false;
}

// Reference:- Book: Data Structures and Algorithms Analysis in C++, 4th edition
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else
    {
        if(data < ptr->data)
        {
            insert(data,ptr->left);
        }
        else
        {
            insert(data,ptr->right);
        }
        
    }
    
}

// Reference:- Book: Data Structures Using C++, 2nd edition Author: D.S Malik
void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    if (ptr == nullptr)
        return;
    
    if(data < ptr->data)
    {
        remove(data,ptr->left);
    }
    else if(data > ptr->data)
    {
        remove(data,ptr->right);
    }
    else if ((ptr->left != nullptr) && (ptr->right != nullptr))
    {
        ptr->data = find_min(ptr->right)->data;
        remove(ptr->data, ptr->right);
    }
    else
    {
        BinaryNode *prev = ptr;
        if(ptr->left != nullptr)
        	ptr = ptr->left;
        else
        	ptr = ptr->right;
        delete prev;
    }
}