#include "SortedLinkedList.h"
/***** Complete this class. *****/


void SortedLinkedList :: insert(Node *node)
{
    // to check which node is greater, overload the > operator to compare row and then col of the nodes
    Node* curr;
    if (head == NULL || *head > *node)
    {
        node->next = head;
        head = node;
    }
    else
    {
        curr = head;
        while (curr->next != NULL && *node > *curr->next)
        {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
    }   
}
ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
    Node* curr = list.head;
     while(curr != nullptr)
     {
         int c = 0;                   //stores the current column position
         int r = curr->get_row();     //stores the current row position
         while(curr->next != NULL && curr->get_row() == r)
         {
             if(curr->get_row() == curr->next->get_row() && curr->get_col() == curr->next->get_col())
             {
                 // check if we the next coordinate is also the same, increment the node position if true
                 curr = curr->next;
             }
             else
             {
                 // print blank spaces from current col position to the next position
                 for(int i = c ;i<curr->get_col();i++)
                 {
                    outs<<" ";
                 }
                 if(c <= curr->get_col())
                 {
                    // calculate the state and city length and overwrite the next nodes if falls within the range of the current city
                    // to print the western most city
                    outs<< *curr;
                 if(curr->get_name().empty())
                    c = curr->get_col()+1;
                 else
                    c = curr->get_name().length() + curr->get_state().length() + curr->get_col() +2;
                 }
                curr = curr->next;
             }      
         }
         if(curr->next == NULL)
         {
             // to print the last coordinate boundary
             cout<< " "<<*curr;
             curr = curr->next;
         }
         while(curr!=nullptr && curr->get_row() - r != 0)
         {
             outs << endl;
             r++;
         }
        
     }

    return outs;
 }

 SortedLinkedList :: ~SortedLinkedList()
 {
     delete head;
 }