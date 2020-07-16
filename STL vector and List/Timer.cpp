#include <chrono>
#include "Timer.h"

/***** Complete this file. *****/

long Timer :: time_it(void f()) throw(string)
{
    steady_clock::time_point start_time = steady_clock::now();

    f();

    steady_clock::time_point end_time = steady_clock::now();
    long ms = duration_cast<milliseconds>(end_time - start_time).count();

    return ms;
}

long Timer :: time_it(SortedVector& sv, const int size, void f(SortedVector&, const int)) throw(string)
{
    steady_clock::time_point start_time = steady_clock::now();

    f(sv,size);

    steady_clock::time_point end_time = steady_clock::now();
    long ms = duration_cast<milliseconds>(end_time - start_time).count();

    return ms;
}

long Timer :: time_it(SortedList& sl, const int size, void f(SortedList&, const int)) throw(string)
{
    steady_clock::time_point start_time = steady_clock::now();

    f(sl,size);

    steady_clock::time_point end_time = steady_clock::now();
    long ms = duration_cast<milliseconds>(end_time - start_time).count();

    return ms;
}
