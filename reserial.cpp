#include <iostream>
#include <fstream>
//#include <complex>
#include <stdlib.h>
#include "common.h"
//#define COMPLEX complex<double>
using namespace std;
void rader_decord(short inv[N])
{
    fstream fs("rader_record.bin");
    for(int i=0;i<N;i++)
    {
	short temp;
	fs >> temp;
	inv[i] = temp;
    }
    return;
}
void W_decord(COMPLEX W[N])
{
    fstream fs("W_record.bin");
    for(int i=0;i<N;i++)
    {
	COMPLEX temp;
	fs >> temp;
	W[i] =temp;
    }
}
void show_row(COMPLEX output[N])
{
    for(int  i =0; i<N;i++)
    {
	cout<<output[i]<<" | ";
    }
}
void get_input(COMPLEX input[N])
{
    cout<<"INPUT |>> | ";
    for(int i=0;i<N;i++)
    {
	if(i%2)
	    input[i] = 0;
	else
	    input[i] = 1;
	cout<<input[i]<<" | ";
    }
    cout<<"\n"<<endl;
}
void conj_output(COMPLEX *output)
{
    for(int i=0;i<N;i++)
    {
	output[i] = conj(output[i]);
    }
}
void normalize(COMPLEX p[N])
{
    for(int i=0;i<N;i++)
    {
	p[i] /=(double)N;
    }
}
COMPLEX *fft(short base[N],COMPLEX input[N],COMPLEX output[N],COMPLEX W[N])
{
    //cout<<"INPUT>>";show_row(input);
    for(int i = 0;i<N;i++)
    //{cout<<endl;cout<<i<<"INPUT>>";show_row(input);cout<<endl;
	output[i] = input[base[i]];
	//cout<<endl;cout<<i<<"INPUT>>";show_row(input);cout<<endl;
	//cout<<base[i]<<" | ";}
    //cout<<endl;cout<<"INPUT>>";show_row(input);cout<<endl;

    //cout<<"inv_order";
    //show_row(output);
    //cout<<endl;
    int block = N;
    short fin = 0;
    short perblock =1;
    for(int i = 0; i<LEVEL ;i++)
    {
	block >>=1;
	fin = 1<<i;
	perblock <<=1;
	for(short b=0;b < block; b++)
	{
	    for(short f= 0;f < fin;f++)
	    {
		COMPLEX temp = output[f+perblock*b] + output[f+perblock*b+fin]*W[f*block];
		output[f+perblock*b+fin] = output[f+perblock*b]+output[f+perblock*b+fin]*W[(f+fin)*block];
		output[f+perblock*b] = temp;
	    }
	    //show_row(output);cout<<"\n"<<"block|>"<<b<<"level|>"<<i<<endl;
	}

    }
    return output;
}
COMPLEX *ifft(short base[N],COMPLEX input[N],COMPLEX output[N],COMPLEX W[N])
{
    conj_output(input);
    fft(base,input,output,W);
    conj_output(input);
    normalize(output);
    return output;
}
int main()
{
    short inv[N];
    COMPLEX W[N];
    W_decord(W);
    rader_decord(inv);
    for (int i=0;i<N;i++)
    {
	cout << inv[i] <<" | ";
    }
    cout<<"\n"<<endl;
    COMPLEX input[N];
    COMPLEX output[N];
    fft(inv,input,output,W);
    get_input(input);
    fft(inv,input,output,W);
    //for (int i=0;i<N;i++)
    //{
	//cout << output[i]<<" | ";
    //}
    //cout<<endl;
    //cout<<"??"<<endl;show_row(output);cout<<endl;
    show_row(output);
    cout<<endl;
    //conj_output(output);
    //fft(inv,output,input,W);
    //conj_output(input);
    //normalize(input);
    ifft(inv,output,input,W);
    cout<<"ifft_result |> \n";show_row(input);cout<<endl;
    return 0;
}
