#include<mpir.h>
#include<iostream>
#include<string.h>
#include<chrono>
#include<iomanip>
#include<stdlib.h>
#include<math.h>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 5;
const int PRECISION = 1001;  // 1000 for decimal point and 1 for the value 3 before the decimal

/***
 * computes the value of pi using Borwein's Quartic Algorithm
***/
void computeBigPi();

/***
 * formatting the decimal places
 * @param bigpi value
 * @param execution_time_nsec elapsed time in nano seconds
 * @param execution_time_sec elased time in seconds
 ***/
void formatOutput(mpf_t& bigpi,long execution_time_nsec,double execution_time_sec);

int main()
{
    mpf_set_default_prec(8*PRECISION);
    computeBigPi();
    return 0;
}

void computeBigPi()
{
    // declaring variables
    mpf_t bigpi;
    mpf_t a0,y0,a_init,y_init,ai,yi;
    mpf_t yi2,yi4;
    mpf_t six,four,two,one;
    mpf_t sqrt2,dsqrt,fsqrt;
    mpf_t mult,sub;
    mpf_t x1,x2,x3,x4,mpf_x5,x6,x7,x8,x9;
    mpf_t numerator,denominator;

    // intializing the variables

    mpf_init(bigpi);
    mpf_init(a0);
    mpf_init(y0);
    mpf_init(six);
    mpf_init(four);
    mpf_init(two);
    mpf_init(one);
    mpf_init(sqrt2);
    mpf_init(mult);
    mpf_init(sub);
    mpf_init(a_init);
    mpf_init(y_init);
    mpf_init(x1);
    mpf_init(x2);
    mpf_init(x3);
    mpf_init(x4);
    mpf_init(x6);
    mpf_init(x7);
    mpf_init(x8);
    mpf_init(x9);
    mpf_init(yi);
    mpf_init(ai);
    mpf_init(yi2);
    mpf_init(yi4);
    mpf_init(numerator);
    mpf_init(denominator);
    mpf_init(dsqrt);
    mpf_init(fsqrt);
    mpf_init(mpf_x5);

    // set values for the digits

    mpf_init_set_ui(six,6);   // value 6
    mpf_init_set_ui(four,4);  // value 4
    mpf_init_set_ui(two,2);   // value 2
    mpf_init_set_ui(one,1);   // value 1

    // set the initial value for a0 
    // a0 = 6 - 4*sqrt(2)

    mpf_sqrt(sqrt2,two);      // sqrt(2)
    mpf_mul(mult,four,sqrt2); // 4 * sqrt(2)
    mpf_sub(a0,six,mult);     // 6 - 4 * sqrt(2)

    // set the initial value for y0
    // y0 = sqrt(2) - 1

    mpf_sub(y0,sqrt2,one);    // sqrt(2) - 1
    
    // computing the value of pi
    mpf_set(a_init,a0);
    mpf_set(y_init,y0);

    auto start_time = steady_clock::now();

    for(int i=1;i<=MAX_ITERATIONS;i++)
    {
        mpf_pow_ui(yi4,y_init,4);           // y_init^4
        mpf_sub(x1,one,yi4);                // x1 = 1 - yi^4
        mpf_sqrt(dsqrt,x1);                 // dsqrt = root of x1
        mpf_sqrt(fsqrt,dsqrt);              // fsqrt = 4th root of x1
        mpf_sub(numerator,one,fsqrt);       // numerator = 1 - fsqrt
        mpf_add(denominator,one,fsqrt);     // denominator = 1 + fsqrt
        mpf_div(yi,numerator,denominator);  // value of yi  

        mpf_pow_ui(yi2,yi,2);               // yi^2
        mpf_add(x2,yi,yi2);                 // x2 = yi + yi^2
        mpf_add(x3,one,x2);                 // x3 = 1 + yi + yi^2
        mpf_mul(x4,yi,x3);                  // x4 = yi(1+yi+yi^2)
        
        double x5 = pow(2,((2*i) + 1));     // x5 = 2^(2i + 1)
        mpf_init_set_ui(mpf_x5,x5);
        mpf_mul(x6,mpf_x5,x4);              // x6 = 2^(2i + 1) * yi(1+yi+yi^2)
        mpf_add(x7,one,yi);                 // x7 = 1 + yi
        mpf_pow_ui(x8,x7,4);                // x8 = (1 + yi)^4
        mpf_mul(x9,a_init,x8);              // x9 = a_init(1 + yi)^4
        mpf_sub(ai,x9,x6);                  // ai = a_init(1 + yi)^4 - 2^(2i + 1) * yi(1+yi+yi^2)
        mpf_set(a_init,ai);                 // input ai for next iteration
        mpf_set(y_init,yi);                 // input yi for next iteration
    }

    decltype(start_time) end_time = steady_clock::now();
    long execution_time_nsec = duration_cast<nanoseconds>(end_time-start_time).count(); // time taken to compute the value of bigpi in nanosec
    double execution_time_sec = duration<double>(end_time-start_time).count(); // time taken to compute the value of bigpi in sec

    mpf_div(bigpi,one,ai);                  // bigpi = 1 / ai
    formatOutput(bigpi,execution_time_nsec,execution_time_sec);
    
}

void formatOutput(mpf_t& bigpi,long execution_time_nsec,double execution_time_sec)
{
    char *bigpi_ptr=0;
	mp_exp_t dec;   // decimal point
    int base = 10;

    // convert pi value to string
	bigpi_ptr = mpf_get_str(bigpi_ptr,&dec,base,PRECISION,bigpi);   
	cout<<"C API: pi to 1,000 places:"<<endl<<endl;

	cout << bigpi_ptr[0]<<"."; // print "3."

    for(int i=1;i<PRECISION;i++)
    {
		cout<<bigpi_ptr[i];
		if(i % 10 == 0)             //space after every 10th digit
			cout<<" ";
        if(i % 100 == 0)            //new line after 100 digits
            cout<<endl<<"  ";
        if(i == 500)               //extra new line after 500th digit
            cout<<endl<<"  ";
	}
    cout<<endl;
	cout<<"Elapsed time : "<<execution_time_nsec<<" nsecs = ";
    cout<<setprecision(6)<<fixed;
    cout<<execution_time_sec<<" seconds"<<endl;
}