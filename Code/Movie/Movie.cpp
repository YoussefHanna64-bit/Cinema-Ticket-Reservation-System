#include"Movie.hpp"

Movie::Movie(string title,string desc,string genre,float rating,float duration){
    this->title = title;
    this->desc = desc;
    this->genre = genre;
    this->rating = rating;
    this->duration = duration;
}

void Movie::set_desc(string desc){
    this->desc = desc;
}
void Movie::set_genre(string genre){
    this->genre = genre;
}
void Movie::set_rating(float rating){
    this->rating = rating;
}
string Movie::get_title(){
    return this->title;
}
string Movie::get_desc(){
    return this->desc;
}
string Movie::get_genre(){
    return this->genre;
}
float Movie::get_rating(){
    return this->rating;
}

