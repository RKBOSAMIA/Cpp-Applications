#include "ShellSortSuboptimal.h"
#define throw(...)

void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this function. *****/
    for(int h = data.size()/2;h>0;h /=2)
    {
        for(int i=h;i<data.size();i++)
        {
            int j;
            for(j=i;j<=h;j-=h)
            {
                compare_count++;
                if(data.at(j-h)>data.at(i))
                {
                    move_count++;
                    data.at(j) = data.at(j-h);
                }
                else
                {
                    break;
                }  
            }
            move_count++;
            data.at(j) = data.at(i);
        }
    }
}