#include "Admin.hpp"

void Admin::AddMovie(Movie &movie)
{
    System::movies.push_back(movie);
}
void Admin::modifyMovieDesc(string movieTitle, string newDesc)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            movie.set_desc(newDesc);
            break;
        }
    }
}
void Admin::modifyMovieRating(string movieTitle, float newRating)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            movie.set_rating(newRating);
            break;
        }
    }
}
void Admin::modifyMovieGenre(string movieTitle, string newGenre)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            movie.set_genre(newGenre);
            break;
        }
    }
}
void Admin::deleteMovie(string movieTitle)
{
    for (auto it = System::movies.begin(); it != System::movies.end(); ++it)
    {
        if (it->get_title() == movieTitle)
        {
            System::movies.erase(it);
            break;
        }
    }
}
void Admin::viewAllMovies()
{
    for (auto &movie : System::movies)
    {
        cout << "Title: " << movie.get_title() << endl;
        cout << "Description: " << movie.get_desc() << endl;
        cout << "Genre: " << movie.get_genre() << endl;
        cout << "Rating: " << movie.get_rating() << endl;
        cout << "------------------------" << endl;
    }
}
void Admin::createShowTime(string movieTitle, string date, float time)
{
    for (auto &movie : System::movies)
    {
        if (movie.get_title() == movieTitle)
        {
            Showtime newShowtime(date, time, 40);
            // movie.showtimes.push_back(newShowtime);
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
            for(auto &showtime : movie.getShowTimes())
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
            for(auto &showtime : movie.getShowTimes())
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
            for(auto it = movie.getShowTimes().begin(); it != movie.getShowTimes().end(); ++it)
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

int main()
{
    Admin admin;
    Admin admin2;
    if (admin2.Authenticate("admin", "admin123"))
    {
        cout << "Admin authenticated successfully." << endl;
    }
    else
    {
        cout << "Authentication failed." << endl;
    }
    admin.viewAllMovies();
    Movie m("ex.title","ex.desc","ex.genre",5,2.00);
    admin.AddMovie(m);
    admin.viewAllMovies();
}