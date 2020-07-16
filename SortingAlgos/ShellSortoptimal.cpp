#include "ShellSortoptimal.h"
#define throw(...)

void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this function. *****/
    int h=1;

    while(h<=data.size()/3)
    {
        h = (3 * h) + 1;
    }
    while(h>=1)
    {
        for(int i=data.size()-1;i>=h;i--)
        {
            compare_count++;
            if(data.at(i)<data.at(i-h))
            {
                swap(i,i-h);
            }
        }
    h /= 3;
    }
}