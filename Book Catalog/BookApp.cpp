#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Inserts a book in the catalog.
 * @param index is for the index at which the book is to be inserted
 * @param input for input data.
 * @param bookCatalog for the book records.
 * @return Status of the command executed.
 */
StatusCode insertBook(int& index,istream& input,vector<Book>& bookCatalog);

/**
 * Removes a book from the catalog.
 * @param book book object that is to be deleted
 * @param input for input data.
 * @param bookCatalog for the book records.
 * @return Status of the command executed.
 */
StatusCode removeBook(Book& book,istream& input,vector<Book>& bookCatalog);

/**
 * Function to determine the correctness of the command.
 * @param input for input data.
 * @return Status of the command executed.
 */
StatusCode invalidCommand(istream& input);

/**
 * Function to display appropriate error message
 * @param status enum status
 * @return Error in string format.
 */
string errorMessage(StatusCode status);

/**
 * Executes each command from the file
 * @param command is for command.
 * @param input for input data.
 * @param bookCatalog for the book records.
 * @return Status of the command executed.
 */
StatusCode Runner(char command,istream& input,vector<Book>& bookCatalog);

/**
 * Removes a book from the catalog.
 * @param book book object that is to be deleted
 * @param input for input data.
 * @param bookCatalog for the book records.
 * @return Status of the command executed.
 */
StatusCode removeBook(Book& book,istream& input,vector<Book>& bookCatalog);

/**
 * Function to make a linear search based on the different search criterias
 * 
 * 
 */
vector<int> linearSearch(istream &input, vector<Book>& bookCatalog); 

/**
 * Displays all the books from the book catalog.
 * @param bookCatalog for the book records.
 * @return vector of indices.
 */
vector<int> displayAllBooks(vector<Book>& bookCatalog);

/**
 * Displays all the books from the book catalog matching with the mentioned lastname
 * @param last for author's last name
 * @param bookCatalog for the book records.
 * @return vector of indices.
 */
vector<int> searchByAuthor(string last,vector<Book>& bookCatalog);

/**
 * Displays all the books from the book catalog matching with the mentioned lastname
 * @param category for book category.
 * @param bookCatalog for the book records.
 * @return vector of indices.
 */
vector<int> searchByCategory(string category,vector<Book>& bookCatalog);

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& bookCatalog);


const string INPUT_FILE_NAME = "commands.in";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Book> catalog;  // book catalog

    char command;
    input >> command;  // read the first command

    while (!input.fail())
    {
        cout << endl << command << " ";
        StatusCode status = Runner(command, input, catalog);
        if (status != StatusCode::OK) 
            errorMessage(status);
        input >> command;
    }

    return 0;
}

StatusCode insertBook(int& index,istream& input,vector<Book>& bookCatalog)
{
    Book book;
    input >> book;
    index = 0;
    string isbn = book.get_isbn();
    int catalogSize = bookCatalog.size(); 
    while((index < bookCatalog.size()) && (isbn > bookCatalog[index].get_isbn())) 
    index++;


    // Condition to insert the book at its appropriate position
    if (index >= bookCatalog.size())
    {
        bookCatalog.push_back(book); 
        return StatusCode::OK;
    }
    else if (isbn == bookCatalog[index].get_isbn()) // to check the duplicate entry
    {
        return StatusCode::DUPLICATE;
    }
    else                                            // make an insert
    {
        bookCatalog.insert(bookCatalog.begin() + index, book);
        return StatusCode::OK;
    }
}

StatusCode removeBook(Book& book,istream& input,vector<Book>& bookCatalog)
{
    string isbn = "";
    input >> isbn; 
    int index = find(isbn, bookCatalog);
    if (index == -1)
    {
        //book = Book(isbn, "", "", "", Book::Category::NONE);
        return StatusCode::NOT_FOUND;
    }
    book = bookCatalog[index];
    bookCatalog.erase(bookCatalog.begin() + index);
    return StatusCode::OK;
}

StatusCode invalidCommand(istream& input)
{
    string invalidCommand;
    getline(input, invalidCommand); 
    return StatusCode::INVALID_COMMAND;
}

string errorMessage(StatusCode status)
{
    switch (status)
    {
        case StatusCode::DUPLICATE:
            {
                cout << "*** Duplicate ISDN ***" << endl;
                break;
            }
        case StatusCode::NOT_FOUND:
            {
                cout << "*** Book not found ***" << endl;
                break; 
            }
        case StatusCode::INVALID_COMMAND:
            {
                cout << "*** Invalid command ***" << endl;
                break; 
            }
    }
}

vector<int> linearSearch(istream &input, vector<Book>& bookCatalog)
{
    vector<int> result;
    string line = "";
    getline(input, line); 
    if (line == "")
    {
        result = displayAllBooks(bookCatalog);
    }
    else if (strstr(line.c_str(),"isbn="))
    {
        // get the isbn value using string substring
        string isbn = line.substr(line.find("=") + 1);
        cout << "Book with ISBN " << isbn << ":" << endl;
        int index = find(isbn, bookCatalog);
        if (index != -1) 
        {
            result.push_back(index);
        }
    }
    else if (strstr(line.c_str(),"author="))
    {
        string last = line.substr(line.find("=") + 1);
        result = searchByAuthor(last, bookCatalog);
    }
    else if (strstr(line.c_str(),"category="))
    {
        string category = line.substr(line.find("=") + 1);
        result = searchByCategory(category,bookCatalog);
    }
    return result;
}

vector<int> displayAllBooks(vector<Book>& bookCatalog)
{
    vector<int> result;
    cout << "All books in the catalog:" << endl;
    for (int i = 0; i < bookCatalog.size(); i++) 
    {
        result.push_back(i);
    }
    return result;
}

vector<int> searchByAuthor(string last,vector<Book>& bookCatalog)
{
    vector<int> result;
    cout << "Books by author " << last << ":" << endl; 
    for (int i = 0; i < bookCatalog.size(); i++)
    {
        Book book = bookCatalog[i];
        if (last == book.get_last())
        { 
            result.push_back(i);
        }
    }
    return result;
}

vector<int> searchByCategory(string category,vector<Book>& bookCatalog)
{
    vector<int> result;
    Book::Category cat;
    if (category=="fiction")
    {
        cat = Book::Category::FICTION;
    }
    else if(category=="technical")
    {
        cat = Book::Category::TECHNICAL;
    }
    else if(category=="history")
    {
        cat = Book::Category::HISTORY;
    }
    else
    {
        cat = Book::Category::NONE;
    } 
    cout << "Books by author " << cat << ":" << endl; 
    for (int i = 0; i < bookCatalog.size(); i++)
    {
        Book book = bookCatalog[i];
        if (cat == book.get_category())
        { 
            result.push_back(i);
        }
    }
    return result;
}

int find(const string isbn, const vector<Book>& bookCatalog)
{
    int low = 0;
    int high = bookCatalog.size();

    while (low <= high)
    {
        int mid = (low + high)/2;
        Book book = bookCatalog[mid];

        if (isbn == book.get_isbn())
        {
            return mid; 
        }
        else if (isbn < book.get_isbn())
        {
            high = mid - 1;
        }
        else
        {
            low  = mid + 1;
        }
    }
    return -1;
}

StatusCode Runner(char command,istream& input,vector<Book>& bookCatalog)
{
    int index;
    Book book;
    StatusCode status; 
    switch (command)
    {
        case '+':
        {
            status = insertBook(index,input,bookCatalog);
            book = bookCatalog[index];
            cout << "Inserted at index " << index << ": " << book << endl;
            break;
        }
        case '-':
        {
            status = removeBook(book,input,bookCatalog);
            cout << "Removed " << book << endl;
            break;
        }
        case '?':
        {
            vector<int> matches = linearSearch(input, bookCatalog);
            for (int i=0;i<matches.size();i++) 
                cout << bookCatalog[matches.at(i)] << endl;
            status = StatusCode::OK;
            break;
        }
        default:
            status = invalidCommand(input);
            break;
    }
    return status;
}

