#include "WordVector.h"

int WordVector :: find(const string text, int low, int high) const
{
    auto it = begin();
    if(high >= low)
    {
        int mid = (low + high) / 2;
        if (at(mid).get_text() == text)
            return mid;
        if(at(mid).get_text() > text)
            return find(text,low,mid-1);
        if(at(mid).get_text() < text)
            return find(text,mid+1,high);
    }
    // make the value negative to indicate if its not present
     return -(low+1);
}

void WordVector :: insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();
    int word_idx = find(text, 0, size()-1);
    vector<Word>::iterator it = begin();
	if(word_idx >= 0)
	{
		advance(it, word_idx);
		it->increment_count();
	}
	else
	{
        word_idx = word_idx * -1;
        advance(it, word_idx-1);
        vector<Word>::insert(it, Word(text));
	}
    
    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time,end_time);
}

vector<Word>::iterator WordVector::search(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();

    int word_idx = this->find(text,0,size()-1);
    vector<Word>:: iterator it = end();
    if(word_idx >= 0)
    {
        it = begin();
        advance(it,word_idx);
    }

    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time,end_time);
    return it;
}

int WordVector :: get_count(const string text) const
{

    int word_idx = this->find(text,0,size()-1);
    cout<< word_idx <<endl;
    if(word_idx > 0)
    {
        return this->at(word_idx).get_count();
    }
    return 0;
}