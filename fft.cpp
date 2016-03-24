#include <iostream>
#include <fstream>
#include <complex>
#include <math.h>
#include "common.h"
#define COMPLEX complex<double> 
using namespace std;
int rader(int i)
{
    int r = 0;
    for(char j=0;j<LEVEL;j++)
    {
    int temp = i & 1;
    i >>= 1;
    r <<= 1;
    r |= temp; 
    }

    return r;
}
void rader_record(void)
{
    fstream fs("rader_record.bin",ios::out);
    for(int i=0;i<N;i++)
    {
	fs <<rader(i)<<"\n";
    }
    fs.close();
}
COMPLEX W(int i)
{
    COMPLEX x(cos((2*M_PI*i)/N),sin((2*M_PI*i)/N));
    return x;
}
void W_record(void)
{
    fstream fs("W_record.bin",ios::out);
    for(int i = 0;i<N;i++)
    {
	fs <<W(i)<<"\n";
    }
    fs.close();
}
int main()
{
    rader_record();
    W_record();
    return 0;

}
