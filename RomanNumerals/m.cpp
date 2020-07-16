#include"RomanNumeral.h"

int main()
{
    test1();
    const string INPUT_FILE_NAME = "RomanNumeral.txt";
    ifstream in;
    in.open(INPUT_FILE_NAME);
    if (in.fail())
    {
        cout << "Input file open failed: " << INPUT_FILE_NAME;
        return -1;
    }

    test2(in);
    return 0;
}