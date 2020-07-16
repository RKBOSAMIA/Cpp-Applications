#include <string>
#include "MergeSort.h"

void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

void MergeSort::mergesort(LinkedList& list)
{
    /***** Complete this function. *****/
    LinkedList list1,list2;
    while(list.get_head()!=list.get_tail())
    {
        list.split(list1,list2);
    }
    if(list1.get_size()!=0)
    {
        mergesort(list1);
    }
    if(list2.get_size()!=0)
    {
        mergesort(list2);
    }
    merge(list,list1,list2);
}

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    /***** Complete this function. *****/
    while(sublist1.get_head()!=nullptr && sublist2.get_head()!=nullptr)
    {
        if(sublist1.get_head()->element < sublist2.get_head()->element)
        {
            list.add(sublist1.remove_head());
        }
        else
        {
            list.add(sublist2.remove_head());
        } 
        compare_count++;
    }
    while(sublist1.get_head()!=nullptr)
    {
        list.concatenate(sublist1);
    }
    while(sublist2.get_head()!=nullptr)
    {
        list.concatenate(sublist2);
    }
}

void MergeSort::clear() { data.clear(); }