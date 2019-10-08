// file Complex.cpp
#include "Complex.hpp"
#include <iostream>
 
Complex::Complex()
{
    
}
 
void Complex::setData(double _real, double _imag)
{
  real = _real;
  imag = _imag;
}
void Complex::printComplexNumber()
{
   std::cout << "(" << real << "," << imag << "i)" << std::endl; 
}

double Complex::getReal(){
    
    return real;
    
}

double Complex::getImag(){
    
    return imag;
    
}

/*
Complex Complex::getData(){
    
    Complex c;
    c.real = real;
    c.imag = imag;
    return c;
    
}
*/

Complex Complex::subtract(Complex &complexOther2){
    
    Complex complexSum2;
    complexSum2.real = real - complexOther2.getReal();
    complexSum2.imag = imag - complexOther2.getImag();
    return complexSum2;
}

Complex Complex::add(Complex &complexOther)
{
  Complex complexSum;
  complexSum.real = real + complexOther.getReal();
  complexSum.imag = imag + complexOther.getImag();
  return complexSum;
}


void Complex::setReal(double _real){
    
    real = _real;
    
}