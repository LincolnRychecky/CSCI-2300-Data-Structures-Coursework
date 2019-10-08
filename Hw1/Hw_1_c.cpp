#include <iostream>
#include "Movie.hpp"
using namespace std;

int main(){
    
    Movie m1("star", 2019, 3.2);
    
    cout << m1.getTitle() << endl;
    cout << m1.getYear() << endl;
    cout << m1.getRating() << endl;
    
}