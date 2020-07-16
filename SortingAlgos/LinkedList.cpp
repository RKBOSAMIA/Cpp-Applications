#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

    // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
    /***** Complete this function. *****/
    int SIZE = size;
    for(int i=0;i<SIZE;i++)
    {
        if(i % 2 == 1)
        {
            list2.add(remove_head());
        }
        else
        {
            list1.add(remove_head());
        }
        
    }
}

void LinkedList::concatenate(LinkedList& other_list)
{
    /***** Complete this function. *****/
    tail->next = other_list.head;
    set(head,other_list.get_tail(),other_list.size+size);
    other_list.reset();
}