#include<iostream>
#include <vector>
#include <ShowTime.hpp>
using namespace std;

class Movie{

    private:
        string title;
        string desc;
        string genre;
        float rating;
        float duration;
        vector<Showtime>showtimes;
    public:
        Movie(string title,string desc,string genre,float rating,float duration);
        void set_desc(string desc);
        void set_genre(string genre);
        void set_rating(float rating);
        string get_title();
        string get_desc();
        string get_genre();
        float get_rating();

         
};