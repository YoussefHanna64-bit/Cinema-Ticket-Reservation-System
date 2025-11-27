#include <iostream>
#include <vector>

class Ticket
{

private:
    std::string movieTitle;
    std::string date;
    float time;
    float price;
    std::vector<int> seats;

public:
    Ticket(std::string movieTitle, std::string date, float time, float price, std::vector<int> seats);
};