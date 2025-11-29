#include "../Movie/Movie.hpp"
class UserUI
{
public:
    void printUserMenu();
    void reserveTicket();
    void selectShowtime(Movie& selectedMovie, string date);
    void selectSeats(Movie& selectedMovie, Showtime &selectedShowtime);
    void cancelReservation();
    void viewReservedTickets();
};