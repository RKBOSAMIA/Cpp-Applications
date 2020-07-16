#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;


class Book
{
public:

    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    Book();                                                                           //default constructor
    Book(string isbn, string last, string first, string title, Category category);    //parameterized constructor
   ~Book();                                                                           //destructor
    string get_isbn();                                                                //function to get isbn
    string get_last();                                                                //function to get last name  
    string get_first();                                                               //function to get first name
    string get_title();                                                               //function to get the book title  
    Category get_category();                                                          //function to get the category  
    friend ostream &operator <<(ostream&,const Book&);                                //overload << to display class object  
    friend istream &operator >>(istream&,Book&);                                      //overload >> to read input
    friend ostream &operator <<(ostream&, const Book::Category&);                     //overload << to output category

private:
    
    string isbn;
    string last;
    string first;
    string title;
    Category category;
};

#endif /* EMPLOYEE_H_ */