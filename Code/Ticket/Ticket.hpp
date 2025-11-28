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
    Ticket() = default;
    Ticket(std::string movieTitle, std::string date, float time, float price, std::vector<int> seats);
    ///////////////////////////////////////
    float getrice()
    {
        return price;
    }
};