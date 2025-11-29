#include "Admin.hpp"

void Admin::AddMovie(Movie &movie)
{
    System::movies.push_back(movie);
    cout << "Movie Added Successfully!" << endl;
}
void Admin::modifyMovie(Movie *movie, string newDesc, string newGenre, float newRating)
{
    movie->set_desc(newDesc);
    movie->set_rating(newRating);
    movie->set_genre(newGenre);
}

void Admin::deleteMovie(Movie *movie)
{
    for (auto it = System::movies.begin(); it != System::movies.end(); ++it)
    {
        if (it->get_title() == movie->get_title())
        {
            System::movies.erase(it);
            break;
        }
    }
}

void Admin::createShowTime(string movieTitle, string date, float time)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            Showtime newShowtime(date, time, 40);
            movie.getShowTimes().push_back(newShowtime);
            break;
        }
    }
}
void Admin::modifyShowTimeDate(string movieTitle, string oldDate, string newDate, float time)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            for (auto &showtime : movie.getShowTimes())
            {
                if (showtime.getDate() == oldDate && showtime.getTime() == time)
                {
                    showtime.setDate(newDate);
                    break;
                }
            }
        }
    }
}
void Admin::modifyShowTimeTime(string movieTitle, string date, float oldTime, float newTime)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            for (auto &showtime : movie.getShowTimes())
            {
                if (showtime.getDate() == date && showtime.getTime() == oldTime)
                {
                    showtime.setTime(newTime);
                    break;
                }
            }
        }
    }
}
void Admin::deleteShowTime(string movieTitle, string date, float time)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            for (auto it = movie.getShowTimes().begin(); it != movie.getShowTimes().end(); ++it)
            {
                if (it->getDate() == date && it->getTime() == time)
                {
                    movie.getShowTimes().erase(it);
                    break;
                }
            }
        }
    }
}