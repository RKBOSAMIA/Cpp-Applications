#include "InsertionSort.h"
#define throw(...)

void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this function. *****/
    for(int i=0;i<size;i++)
    {
        for(int j=i;j>0;j--)
        {
            compare_count++;
            if(data.at(j-1)>data.at(j))
            {
                swap(j,j-1);
            }
            else
            {
                break;
            }
            
        }
    }
}