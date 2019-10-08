//file Main.cpp
#include "Complex.hpp"
#include <iostream>
 
using namespace std;
int main()
{
  Complex c1,c2; // Objects of “complex” class
  c1.setData(2, 3);
  c2.setData(14.3, 22.1);
 
  Complex c3,c4;
  c3.setData(5,10);
  c4.setData(3,4);
  
  cout << "First complex: "; c1.printComplexNumber();
  cout << "Second complex: ";c2.printComplexNumber();
  
  cout << "Third complex: "; c3.printComplexNumber();
  cout << "Fourth complex: ";c4.printComplexNumber();
  
  cout << "c1 and c2 after adding"; c1.add(c2).printComplexNumber();
  
  cout << "c3 and c4 after subtracting"; c3.subtract(c4).printComplexNumber();
  
  
  return 0;
}
