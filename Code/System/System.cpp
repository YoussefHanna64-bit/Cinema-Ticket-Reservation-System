#include "System.hpp"
#include <iomanip>
#include <sstream>
#include <ctime>
#include <vector>

vector<Movie> System::movies;

void initializeMovies()
{
    Movie interstellar("Interstellar", "Don't leave me murph", "Science fiction", 10, 3.00);
    interstellar.getShowTimes().push_back(Showtime("15/01/2025", 14.30, 100));
    interstellar.getShowTimes().push_back(Showtime("15/01/2025", 18.00, 100));
    interstellar.getShowTimes().push_back(Showtime("16/01/2025", 20.00, 100));

    Movie inception("Inception", "Too many dreams", "Science fiction, crime", 9.5, 2.50);
    inception.getShowTimes().push_back(Showtime("15/01/2025", 15.00, 100));
    inception.getShowTimes().push_back(Showtime("16/01/2025", 19.30, 100));

    System::movies.push_back(interstellar);
    System::movies.push_back(inception);
}

Movie System::searchMoviebytitle(string title)
{
    for (auto &movie : movies)
    {
        if (movie.get_title() == title)
        {
            return movie;
        }
    }
    throw runtime_error("Movie not found");
}

string System::getTodayDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_mday << "/"
       << setfill('0') << setw(2) << (1 + ltm->tm_mon) << "/"
       << (1900 + ltm->tm_year);

    return ss.str();
}

vector<Movie> System::searchMoviebydate(string date)
{
    if (date.empty())
    {
        date = getTodayDate();
    }

    vector<Movie> availableMovies;

    for (auto &movie : System::movies)
    {
        if (movie.isAvailableOn(date))
        {
            availableMovies.push_back(movie);
        }
    }

    return availableMovies;
}