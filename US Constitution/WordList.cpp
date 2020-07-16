#include "WordList.h"

using namespace std;
list<Word>::iterator WordList:: find(const string text)
{
    list<Word>:: iterator it = begin();
    while(it != end())
    {
        if (it->get_text() == text)
        {
            return it;
        }
        ++it;
    }
    return end();

}

list<Word>::iterator WordList:: search(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();
    list<Word>:: iterator it = this->find(text);
    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time,end_time);

    return it;
}

void WordList:: insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();
    
    list<Word>::iterator it = this->find(text);
    if(it == end())
    {
       int flag = 0;
       for(list<Word>::iterator it = begin();it!=end();it++)
       {
          if(it->get_text() > text)
          {
            list<Word>::insert(it,Word(text));
            flag = 1;
            break;
          }
       }
       //for the last element
        if(flag == 0)
            push_back(Word(text));
    }
    else
    {
        it->increment_count();
    }

    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time,end_time);
}
int WordList :: get_count(string text)
{
    list<Word>::iterator it = this->find(text);
    if(it != end())
        return it->get_count();
    return 0;
}


