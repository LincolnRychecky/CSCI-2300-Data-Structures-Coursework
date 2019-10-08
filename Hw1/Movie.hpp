#ifndef MOVIE_HPP
#define MOVIE_HPP
#include <string>


class Movie
{
    private:
        
        std::string title;   //title
        int year;   //year int
        double rating;  //rating double
    public:
        Movie();
        Movie(std::string ti, int ye, double ra);
        void setTitle(std::string newTitle);
        void setYear(int newYear);
        void setRating(double newRating);
        std::string getTitle();
        int getYear();
        double getRating();
    
};

#endif