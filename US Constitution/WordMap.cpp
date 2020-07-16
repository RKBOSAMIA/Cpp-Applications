#include "WordMap.h"

void WordMap :: insert(const string text)
{

    steady_clock::time_point start_time = steady_clock::now();
    map<string,Word>:: iterator it = find(text);
    if(find(text) == end())
    {
        map<string, Word>::insert({text,Word(text)});
    }
    else
    {
        at(text).increment_count();
    }
    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time,end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{

    steady_clock::time_point start_time = steady_clock::now();
    map<string,Word>:: iterator it = find(text);
    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time,end_time);
    return it;
}

int WordMap :: get_count(const string text) const
{
    Word word = find(text)->second;
    int count = word.get_count();
    return count;
}