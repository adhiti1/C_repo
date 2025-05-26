// LabAssignment8_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex multiply(Complex* a, Complex* b) {
    // formula for multiplying 2 complex numbers
    // (a+ib) and (c+id) is
    // (ac -bd) + i(ad+bc)

    Complex r;

    r.real = (a->real * b->real) - (a->imag * b->imag);
    r.imag = (a->real * b->imag) + (a->imag * b->real);

    return r;
}
int main()
{
    Complex n1, n2;
    Complex result;
    double inpReal, intImag;

    scanf("%lf %lf %lf %lf", &(n1.real), &(n1.imag), &(n2.real), &(n2.imag));
    result = multiply(&n1, &n2);
    printf("%lf %lf", result.real, result.imag);
}
