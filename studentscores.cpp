#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";

/*
function to store details in the dynamic arrays
@param1 - name array, @param2 - rows for marks, @param3 - cols for marks, @param4 - count of students
@param5 - input file object
*/
void storeDetails(string*,int**,int*,int,string,ifstream&);

/*
function to print all the details
@param1 - name array, @param2 - rows, @param3 - row count, @param4 - column count
*/
void readLineWords(string,int,string*,int**,int*);

/*
function to read a line word by word
@param1 - current line, @param2 - row inex, @param3 - name array
@param4 - array to store the column count of each row
*/
void printScores(string*,int**,int,int*);

int main()
{
    ifstream input;
    string line = ""; // to store the current line
    int student_count = 0;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    getline(input,line);
    istringstream firstLine(line); // tp read the first line word by word
    firstLine>>line;
    cout << "STUDENT SCORES for "<<line<<endl<<endl;
    firstLine>>line;
    student_count = stoi(line);
    int* col_count = new int[student_count];
    string* studentNames=new string[student_count];
    int** rows = new int*[student_count];
    storeDetails(studentNames,rows,col_count,student_count,line,input);
    printScores(studentNames,rows,student_count,col_count);
}


void storeDetails(string* names,int** row,int* col_count,int studentCounts,string currLine,ifstream& in)
{
    for(int r=0;r<studentCounts;r++)
    {
        getline(in,currLine);
        readLineWords(currLine,r,names,row,col_count);
    }
}
void printScores(string* names,int** rows,int row_count,int* col_count)
{

    for (int r=0;r<row_count;r++)
    {
        cout<<names[r]<<endl;
        int* row = rows[r];
        for(int c=0;c<col_count[r];c++)
        {
            cout<<"    "<<row[c]<<" ";
        }
        cout<<endl;
    }
}

void readLineWords(string curr,int row_index,string* name,int** rows,int* col_count)
{
    istringstream ss(curr);
    int colsCount = 0;
    ss >> curr;
    string temp_name = curr;
    ss >> curr;
    temp_name = temp_name + " " + curr;
    name[row_index] = temp_name;
    ss >> curr;
    colsCount = stoi(curr);
    rows[row_index] = new int[colsCount];
    for(int cols=0;cols<colsCount;cols++)
    {
        ss >> curr;
        rows[row_index][cols] = stoi(curr);
    }
    col_count[row_index] = colsCount;
}