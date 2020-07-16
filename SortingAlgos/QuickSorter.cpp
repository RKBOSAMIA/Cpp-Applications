#include <iostream>
#include "QuickSorter.h"
#define throw(...)
using namespace std;

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

void QuickSorter::quicksort(const int left, const int right)
{
    // Continue the recursive calls until the indexes cross.
    if (left <= right)
    {
        // Choose the pivot and partition this subrange.
        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements <  pivot
        quicksort(p+1, right); // Sort elements >= pivot
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
    /***** Complete this function. *****/
    int i = right - 1;
    for(int j=left; j<=right-1;j++)
    {
        compare_count++;
        if(data.at(j)<pivot)
        {
            i++;
            swap(i,j);
        }
    }
    swap(i+1,right);
    return (i+1);
}