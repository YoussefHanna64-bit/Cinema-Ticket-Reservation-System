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
    void createShowTime(Movie* movie, string date, float time,int seats);
    void modifyShowTime(Movie* movie,int index, string Date, string time,string seats);
    bool deleteShowTime(Movie*movie, string date, float time);
};