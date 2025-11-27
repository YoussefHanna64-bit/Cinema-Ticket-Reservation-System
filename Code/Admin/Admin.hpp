#include <iostream>
#include "../Person/Person.hpp"

using namespace std;

class Admin : public Person
{
public:
    void AddMovie(Movie &movie);
    void modifyMovieDesc(string movieTitle, string newDesc);
    void modifyMovieRating(string movieTitle, float newRating);
    void modifyMovieGenre(string movieTitle, string newGenre);
    void deleteMovie(string movieTitle);
    void viewAllMovies();
    void createShowTime(string movieTitle, string date, float time);
    void modifyShowTimeDate(string movieTitle, string oldDate, string newDate ,float time);
    void modifyShowTimeTime(string movieTitle, string date, float oldTime, float newTime);
    void deleteShowTime(string movieTitle, string date, float time);
};