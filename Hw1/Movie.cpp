#include <iostream>
#include "Movie.hpp"
using namespace std;

Movie::Movie(){
    title = "unknown";
    year = 2016;
    rating = 0.0;
}

Movie::Movie(string ti, int ye, double ra){
    title = ti;
    year = ye;
    rating = ra;
}

void Movie::setTitle(string newTitle){
    title = newTitle;
}

void Movie::setYear(int newYear){
    year = newYear;
}

void Movie::setRating(double newRating){
    rating = newRating;
}

string Movie::getTitle(){
    return title;
}

int Movie::getYear(){
    return year;
}

double Movie::getRating(){
    return rating;
}

