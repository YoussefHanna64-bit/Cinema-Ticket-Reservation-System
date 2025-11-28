#include "../Movie/Movie.hpp"
class UserUI
{
public:
    void printUserMenu();
    void reserveTicket();
    void selectShowtime(Movie selectedMovie, string date);
    void cancelReservation();
    void viewReservedTickets();
};