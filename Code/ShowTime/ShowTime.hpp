#include<iostream>
#include <map>
using namespace std;
class Showtime{
    private:
        string date;
        float time;
        map<int,bool> seats;
    public:
        Showtime(string date, float time, map<int,bool> seats);
        string getDate();
        float getTime();
        void setTime(float time);
        void setDate(string date);
        void displaySeats();
        void reserveSeat(int seat);
};