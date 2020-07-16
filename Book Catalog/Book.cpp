#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <Book.h>
using namespace std;

Book::Book()
{
    this->isbn = "";
    this->last = "";
    this->first = "";
    this->title = "";
    this->category = Category::FICTION;
}

Book::Book(string isbn, string last, string first, string title, Category category)
{
    this->isbn = isbn;
	this->last = last;
	this->first = first;
	this->title = title;
	this->category = category;
}

/* Destructor */
Book::~Book()
{
	//Do nothing
}

string Book::get_isbn()
{
	return isbn;
}

string Book::get_last()
{
	return last;
}

string Book::get_first()
{
	return first;
}

string Book::get_title()
{
	return title;
}

Book::Category Book::get_category()
{
	return category;
}

ostream& operator <<(ostream& output, const Book::Category& obj)
{
    switch (obj)
    {
        case Book::Category::FICTION:
        {
            output << "fiction";      
            break;
        }                  
        case Book::Category::HISTORY:   
        {
            output << "history";      
            break;
        }
        case Book::Category::TECHNICAL: 
        {
            output << "technical";    
            break;
        }
        case Book::Category::NONE:      
        {
            output << "none";         
            break;
        }
    }
    
    return output;
}
ostream& operator <<(ostream& output,const Book& obj)
{
	output << "Book{ISBN="<< obj.isbn<< ", "<< "last="<< obj.last<< ", "<< "first="<< obj.first<< ", "
         << "title="<< obj.title<< ", "<< "category=" << obj.category << "}";
	return output;
}

istream& operator >>(istream& input,Book& obj)
{
    input.get();                         // skip empty space
    char DELIMITER = ',';                // seperating the input values with comma
    string category = "";                // category in string format
    getline(input,obj.isbn,DELIMITER);   
    getline(input,obj.last,DELIMITER);
    getline(input,obj.last,DELIMITER);
    getline(input,obj.last,DELIMITER);
    getline(input,category);

    obj.category = Book::Category::NONE; 
    if(category == "fiction")
    {
        obj.category = Book::Category::FICTION;
    }    
    else if(category == "history")
    {
        obj.category = Book::Category::HISTORY;
    }
    else if(category == "technical")
    {
        obj.category = Book::Category::TECHNICAL; 
    }
}