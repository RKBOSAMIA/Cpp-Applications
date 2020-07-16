#include <string>
#include <time.h>
#include <chrono>
#include "BinarySearchTree.h"

using namespace std;

long BinarySearchTree :: get_comparison_count()
{
    return comparison_count;
}

long BinarySearchTree :: get_probe_count()
{
    return probe_count;
}

long BinarySearchTree :: get_elapsed_time()
{
    return elapsed_time;
}

void BinarySearchTree :: increment_elapsed_time(long time)
{
    elapsed_time += time;
}

void BinarySearchTree:: reset()
{
    comparison_count = 0;
    probe_count = 0;
    elapsed_time = 0;
}

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
bool BinarySearchTree::contains(const int data, BinaryNode *ptr)
{
    /***** Complete this function. *****/
    while(ptr != nullptr)
    {
        comparison_count += 2; // counts for while loop and the conditional statements
        if(ptr->data == data)
        {
            return true;
        }
        else if(ptr->data > data)
        {
            probe_count++;
            ptr = ptr->left;
        }
        else
        {
            probe_count++;
            ptr = ptr->right;
        }     
    }
    return false;
}

// Reference:- Book: Data Structures and Algorithms Analysis in C++, 4th edition
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    /***** Complete this function. *****/
    comparison_count++;
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else
    {
        comparison_count++;
        if(data < ptr->data)
        {
            probe_count++;
            insert(data,ptr->left);
        }
        else
        {
            probe_count++;
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