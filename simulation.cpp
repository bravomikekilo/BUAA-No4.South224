#include <iostream>
#include <fstream>
#include <complex>
#include <string>
#define G 6.67259e-11
#define COMPLEX complex<double>
using namespace std;
inline COMPLEX f(COMPLEX position);
int main(void)
{
    //init
    double M0;
    cout<< "输入中心天体质量|> ";cin >> M0;
    double M1;
    cout<< "输入环绕天体质量|> ";cin >> M1;
    double T ;
    cout<< "输入时间间隔|> ";cin >> T;
    COMPLEX X0;
    cout<< "输入第一基准点|> ";cin >> X0;
    COMPLEX X1;
    cout<< "输入第二基准点|> ";cin >> X1;
    double rows;
    cout<< "输入循环次数|> ";cin >> rows;
    string filename;
    cout<< "输入结果文件名|> ";cin >> filename;
    fstream fs(filename.c_str());
    COMPLEX F = 0;
    for(int i = 0;i<rows;i++)
    {
	F = G*M0*M1*f(X0);
	cout<< "F |>"<<F<<endl;
	COMPLEX temp = X1;
	X1 = (T*T/M1)+2.0*X1-X0;
	cout<< "X |>"<<X1<<endl;
	fs<<X0<<endl;
	X0 = temp;
    }
    return 0;
}
inline COMPLEX f(COMPLEX position)
{
    double mod = abs(position);
    mod = mod*mod*mod;
    COMPLEX F(-position.real()/mod,-position.imag()/mod);
    return F;
}
