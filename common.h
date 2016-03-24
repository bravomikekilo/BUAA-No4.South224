#include <complex>
#define N 8
#define LEVEL 3
#define COMPLEX std::complex<double>
COMPLEX *fft(COMPLEX base[N] ,COMPLEX input[N],COMPLEX output[N]);
COMPLEX *ifft(COMPLEX base[N] ,COMPLEX input[N] ,COMPLEX output[N]);
void normalize(COMPLEX input[N]);
