// file Complex.hpp
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
 
class Complex
{
  private:
     double real;
     double imag;
  public:
	Complex( );
 	void setData(double _real, double _imag); 
 	void printComplexNumber();
 	double getReal();
 	double getImag();
 	//Complex getData();
 	Complex add(Complex &complexOther);
 	Complex subtract(Complex &complexOther2);
 	void setReal(double _real);
 	void setImag(double _imag);
 	
};
#endif
