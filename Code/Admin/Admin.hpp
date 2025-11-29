#include <iostream>
#include "../Person/Person.hpp"

using namespace std;

class Admin : public Person
{
public:
    void AddMovie(Movie &movie);
    void modifyMovie(Movie *movie, string newDesc, string newGenre, float newRating);
    void deleteMovie(Movie *movie);
    void createShowTime(string movieTitle, string date, float time);
    void modifyShowTimeDate(string movieTitle, string oldDate, string newDate, float time);
    void modifyShowTimeTime(string movieTitle, string date, float oldTime, float newTime);
    void deleteShowTime(string movieTitle, string date, float time);
};