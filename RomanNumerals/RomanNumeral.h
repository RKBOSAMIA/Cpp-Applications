#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
using namespace std;

class RomanNumeral
{
    // declaring private variables and private member functions
private:
    string roman;
    int decimal;
    string to_roman(int);
    int to_decimal(string);
public:
    RomanNumeral();                                                              // default constructor
    RomanNumeral(int);                                                           // constructor with int decimal as parameter
    RomanNumeral(string);                                                        // constructor with string roman as parameter
    RomanNumeral getValues();                                                    // getter function to get values of the private variables
    friend RomanNumeral operator + (const RomanNumeral&,const RomanNumeral&);    // + operator overloading
    friend RomanNumeral operator - (const RomanNumeral&,const RomanNumeral&);    // - operator overloading
    friend RomanNumeral operator * (const RomanNumeral&,const RomanNumeral&);    // * opeartor overloading
    friend RomanNumeral operator / (const RomanNumeral&,const RomanNumeral&);    // / operator overloading
    friend bool operator ==(const RomanNumeral&,const RomanNumeral&);            // == to compare two RomanNumeral objects
    friend bool operator !=(const RomanNumeral&,const RomanNumeral&);            // != to compare inequality
    friend ostream &operator <<(ostream&,RomanNumeral&);                         // output stream operator overloading
    friend istream &operator >>(istream&,RomanNumeral&);                         // input stream operator overloading
    void test1();
    void test2(ifstream &in);
            
};

#endif /* ROMANNUMERAL_H_ */