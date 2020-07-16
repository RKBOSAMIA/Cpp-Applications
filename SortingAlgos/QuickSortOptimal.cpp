#include "QuickSortOptimal.h"

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
    /***** Complete this function. *****/
    
    int mid = (left+right)/2;
    compare_count++;
    if(data.at(mid) < data.at(left))
    {
        swap(left,mid);
    }
    compare_count++;
    if(data.at(right) < data.at(left))
    {
        swap(right,left);
    }
    compare_count++;
    if(data.at(right) < data.at(mid))
    {
        swap(right,mid);
    }
    swap(left,mid);
    return data.at(left);
}
