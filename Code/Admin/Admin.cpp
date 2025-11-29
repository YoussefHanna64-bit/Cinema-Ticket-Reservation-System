#include "Admin.hpp"

void Admin::AddMovie(Movie &movie)
{
    System::movies.push_back(movie);
    cout << "Movie Added Successfully!" << endl;
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
            cout << "Movie deleted successfully!" << endl;
            return;
        }
    }
    cout << "Movie not found!" << endl;
}

void Admin::createShowTime(Movie* movie, string date, float time,int seats)
{
            Showtime newShowtime(date, time, seats);
            movie->getShowTimes().push_back(newShowtime);
}
void Admin::modifyShowTime(Movie* movie,int index, string Date, string time,string seats){
    if(Date != "") {
    movie->getShowTimes()[index].setDate(Date);
    }
    if(time != "") {
        movie->getShowTimes()[index].setTime(stof(time));
    }
    if(seats != "") {
        movie->getShowTimes()[index].setSeats(stoi(seats));
    }
}
bool Admin::deleteShowTime(Movie* movie, string date, float time)
{
    for(int i=0;i<movie->getShowTimes().size();i++){
       if(movie->getShowTimes()[i].getDate() == date && movie->getShowTimes()[i].getTime() == time){
           movie->getShowTimes().erase(movie->getShowTimes().begin()+i);
          return true;
       }
   }
   return false;
}