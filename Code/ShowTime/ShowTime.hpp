#ifndef SHOWTIME_HPP
#define SHOWTIME_HPP
#include<iostream>
#include <map>
using namespace std;

class Showtime{
    private:
        string date;
        float time;
        map<int,bool> seats;
    public:
        Showtime(string date, float time, int seats);
        string getDate();
        float getTime();
        void setTime(float time);
        void setDate(string date);
        void displaySeats(int row, int column);
        void reserveSeat(int seat);
};
#endif