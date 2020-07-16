#include <iostream>

using namespace std;

int* surround_with_zeroes(int numbers[], int size);
   
void print_array(int a[], int n)
{
   if (n == 0) { cout << "{}" << endl; return; }
   cout << "{ ";
   for (int i = 0; i < n; i++)
   {
      if (i > 0) cout << ", ";
      cout << a[i];
   }
   cout << " }" << endl;
}

int* surround_with_zeroes(int numbers[], int size)
{
    int *res = new int[size+2];
    res[0] = 0;
    for(int i=0;i<size;i++)
    {
        res[i+1] = numbers[i];
    }
    res[size+1] = 0;
    return res;
}

int main()
{
   int a[] = { 1, 4, 9, 16, 25, 36, 49, 64};
   int* b = surround_with_zeroes(a, 8);
   print_array(b, 10);
   cout << "Expected: { 0, 1, 4, 9, 16, 25, 36, 49, 64, 0 }" << endl;
   delete[] b;

   int* c = surround_with_zeroes(a, 3);
   print_array(c, 5);
   cout << "Expected: { 0, 1, 4, 9, 0 }" << endl;
   delete[] c;

   int* d = surround_with_zeroes(a, 5);
   print_array(d, 7);
   cout << "Expected: { 0, 1, 4, 9, 16, 25, 0 }" << endl;
   delete[] d;

   int* e = surround_with_zeroes(a, 0);
   print_array(e, 2);
   cout << "Expected: { 0, 0 }" << endl;
   delete[] e;
   
   return 0;
}