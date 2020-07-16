#include<mpirxx.h>
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
void formatOutput(mpf_class& bigpi,long execution_time_nsec,double execution_time_sec);

int main()
{
    mpf_set_default_prec(8*PRECISION);
    computeBigPi();
    return 0;
}

void computeBigPi()
{
    // declaring variables
    mpf_class bigpi;
    mpf_class a0,y0,a_init,y_init,ai,yi;
    mpf_class dsqrt,fsqrt,sqrt2;
    mpf_class x0,x1,x2,x3,x4,x5,x6,x7,x8,x9;
    mpf_class yi2,yi3,yi4;
    mpf_class numerator,denominator;
    
    // set the initial value for a0 
    // a0 = 6 - 4*sqrt(2)
    
    mpf_sqrt_ui(sqrt2.get_mpf_t(),2);  // sqrt2 = sqrt(2)
    x0 = 4 * sqrt2;
    a0 = 6 - x0;
    
    // set the initial value for y0
    // y0 = sqrt(2) - 1

    y0 = sqrt2 - 1;
    
    // computing the value of pi
    a_init = a0;
    y_init = y0;
    
    auto start_time = steady_clock::now();

    for(int i=1;i<=MAX_ITERATIONS;i++)
    {
        mpf_pow_ui(yi4.get_mpf_t(),y_init.get_mpf_t(),4);  // yi4 = y_init^4
        x1 = 1 - yi4;
        mpf_sqrt(dsqrt.get_mpf_t(),x1.get_mpf_t());        // dsqrt = root of x1
        mpf_sqrt(fsqrt.get_mpf_t(),dsqrt.get_mpf_t());     // fsqrt = 4th root of x1
        numerator = 1 - fsqrt;
        denominator = 1 + fsqrt;
        yi = numerator/denominator;                        // value of yi  

        mpf_pow_ui(yi2.get_mpf_t(),yi.get_mpf_t(),2);      //  yi2 = yi^2                    
        x2 = yi + yi2;
        x3 = 1 + x2;
        x4 = yi*x3;                                        // x4 = yi(1+yi+yi^2)
        
        int x5 = pow(2,((2*i) + 1));                       // x5 = 2^(2i + 1)
        
        x6 = x5 * x4;                                      // x6 = 2^(2i + 1) * yi(1+yi+yi^2)
        x7 = 1 + yi;
        mpf_pow_ui(x8.get_mpf_t(),x7.get_mpf_t(),4);       // x8 = (1 + yi)^4
        x9 = a_init * x8;                                  // x9 = a_init(1 + yi)^4
        ai = x9 - x6;                                      // ai = a_init(1 + yi)^4 - 2^(2i + 1) * yi(1+yi+yi^2)
        a_init = ai;                                       // input ai for next iteration
        y_init = yi;                                       // input yi for next iteration
    }

    decltype(start_time) end_time = steady_clock::now();
    long execution_time_nsec = duration_cast<nanoseconds>(end_time-start_time).count(); // time taken to compute the value of bigpi in nanosec
    double execution_time_sec = duration<double>(end_time-start_time).count();          // time taken to compute the value of bigpi in sec

    bigpi = 1 / ai;
    formatOutput(bigpi,execution_time_nsec,execution_time_sec);
    
}

void formatOutput(mpf_class& bigpi,long execution_time_nsec,double execution_time_sec)
{
    char *bigpi_ptr=0;
	mp_exp_t dec;   // decimal point
    int base = 10;

    // convert pi value to string
    bigpi_ptr = mpf_get_str(bigpi_ptr,&dec,base,PRECISION,bigpi.get_mpf_t());
	cout<<"C++ API: pi to 1,000 places:"<<endl<<endl;

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