#include"ShowTime.hpp"

Showtime::Showtime(string date, float time, map<int,bool> seats){
    this->date = date;
    this->time = time;
    this->seats = seats;
}
string Showtime::getDate(){
    return this->date;
}
float Showtime::getTime(){
    return this->time;
}
void Showtime::setTime(float time){
    this->time = time;
}
void Showtime::setDate(string date){
    this->date = date;
}
void Showtime::reserveSeat(int seat){
    this->seats[seat] = true;
}
void Showtime::displaySeats(){
    map<int,bool>::iterator it;
    for(it = this->seats.begin(); it != this->seats.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}