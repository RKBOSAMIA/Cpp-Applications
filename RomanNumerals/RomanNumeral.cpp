#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "RomanNumeral.h"

using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0) {}

int RomanNumeral:: to_decimal(string roman)
{
    //assigning values in an array for each roman breakpoint
    int nums[128];
    nums['I'] = 1;
    nums['V'] = 5;
    nums['X'] = 10;
    nums['L'] = 50;
    nums['C'] = 100;
    nums['D'] = 500;
    nums['M'] = 1000;
    int decimal = 0;
    for(int i=0;i<roman.length();++i)
    {
        if(i + 1 < roman.length() && nums[roman[i+1]] > nums[roman[i]])
        {
            decimal -= nums[roman[i]];
        }
        else
        {
            decimal += nums[roman[i]];
        }
    }
    return decimal;
}

string RomanNumeral:: to_roman(int decimal)
{ 
    // array with roman breakpoints
    string rom[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    // array with decimal breakpoints
    int dec[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int i=12;
    string roman="";   
    while(decimal>0) 
    { 
      int temp = decimal/dec[i]; 
      decimal = decimal%dec[i]; 
      while(temp--) 
      { 
        roman += rom[i]; 
      } 
      i--; 
    }
    return roman;
}
RomanNumeral::RomanNumeral(int input_decimal)
{
    decimal = input_decimal;
    roman = this->to_roman(input_decimal);
}
RomanNumeral::RomanNumeral(string input_roman)
{
    roman = input_roman;
    decimal = this->to_decimal(input_roman);
}
RomanNumeral RomanNumeral::getValues()
{
    RomanNumeral rn;
    rn.decimal = this->decimal;
    rn.roman = this->roman;
    return rn;
}
RomanNumeral operator +(const RomanNumeral& obj1,const RomanNumeral& obj2)
{
    RomanNumeral sum;
    sum.decimal = obj1.decimal + obj2.decimal;
    
    int dec1 = sum.to_decimal(obj1.roman);
    int dec2 = sum.to_decimal(obj2.roman);
    int temp_sum = dec1 + dec2;
    sum.roman = sum.to_roman(temp_sum);
    return sum;
}
RomanNumeral operator -(const RomanNumeral& obj1,const RomanNumeral& obj2)
{
    RomanNumeral diff;
    diff.decimal = obj1.decimal - obj2.decimal;
    
    int dec1 = diff.to_decimal(obj1.roman);
    int dec2 = diff.to_decimal(obj2.roman);
    int temp_diff = dec1 - dec2;
    diff.roman = diff.to_roman(temp_diff);
    return diff;
}
RomanNumeral operator *(const RomanNumeral& obj1,const RomanNumeral& obj2)
{
    RomanNumeral mul;
    mul.decimal = obj1.decimal * obj2.decimal;
    
    int dec1 = mul.to_decimal(obj1.roman);
    int dec2 = mul.to_decimal(obj2.roman);
    int temp_mul = dec1 * dec2;
    mul.roman = mul.to_roman(temp_mul);
    return mul;
}
RomanNumeral operator /(const RomanNumeral& obj1,const RomanNumeral& obj2)
{
    RomanNumeral div;
    div.decimal = obj1.decimal / obj2.decimal;
    
    int dec1 = div.to_decimal(obj1.roman);
    int dec2 = div.to_decimal(obj2.roman);
    int temp_div = dec1 / dec2;
    div.roman = div.to_roman(temp_div);
    return div;
}

bool operator ==(const RomanNumeral& obj1,const RomanNumeral& obj2)
{
    return (obj1.roman == obj2.roman && obj1.decimal == obj2.decimal);
}
bool operator !=(const RomanNumeral& obj1,const RomanNumeral& obj2)
{
    return (obj1.roman != obj2.roman || obj1.decimal != obj2.decimal);
}
ostream &operator <<(ostream &output,RomanNumeral &obj)
{
    output<<"["<<obj.decimal<<":"<<obj.roman<<"]";
    return output;
}
istream &operator >>(istream &input,RomanNumeral &obj)
{
    input >> obj.roman;
    obj.decimal = obj.to_decimal(obj.roman);
    return input;
}
void test1();
void test2(ifstream &in);
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
void test1()
{
    cout << "Test 1" << endl << endl;

    RomanNumeral r1(53);
    RomanNumeral r2("MCMXLIX");
    RomanNumeral r3("XXXIV");
    RomanNumeral r4(1949);

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;
    cout << "r4 = " << r4 << endl;

    RomanNumeral result = r1 + r2/r3;
    cout << "result = r1 + r2/r3 = "
         << r1 << " + " << r2 << "/" << r3
         << " = " << result << endl;

    cout << endl;

    cout << r1 << " and " << r3 << " are equal: "
         << boolalpha << (r1 == r3) << endl;
    cout << r1 << " and " << r4 << " are not equal: "
         << boolalpha << (r1 != r4) << endl;
    cout << r2 << " and " << r4 << " are equal: "
         << boolalpha << (r2 == r4) << endl;
    cout << r3 << " and " << r4 << " are not equal: "
         << boolalpha << (r3 != r4) << endl;
}
void test2(ifstream& in)
{
    cout << endl;
    cout << "Test 2" << endl << endl;

    RomanNumeral r1, r2, result;
    char op;

    // Read and evaluate each expression, one per line,
    // in the form r1 op r2
    while (in >> r1 >> op >> r2)
    {
        //performing operator wise operations
        if(op=='+')
            result = r1 + r2;
        else if(op=='-')
            result = r1 - r2;
        else if(op=='*')
            result = r1 * r2;
        else if(op=='/')
            result = r1 / r2;

        // Output the operands, the operator, and the result.
        cout << r1 << " " << op << " " << r2
             << " = " << result << endl;
    }
}

