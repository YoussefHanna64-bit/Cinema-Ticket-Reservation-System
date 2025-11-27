#include "User.hpp"
#include <vector>

Movie &User::selectMovie(string date = "")
{
    Movie movie;
    if (date.empty())
    {
    }
    return movie;
}

// Showtime &User::selectShowtime(Movie &movie)
// {
//     return showtime;
// }

// vector<int> User::selectSeat(Showtime &showtime)
// {
//     vector<int> seats;
//     return seats;
// }

// void User::makeTicket(Movie &movie, Showtime &showtime, vector<int> &seats)
// {

// }

void User::deleteTicket()
{
}

// void User::cancelReservation(Movie movie, Showtime showtime, vector<int> &seats)
// {

// }

void User::completeReservation()
{
}

// float User::calculateTickets( vector<Ticket> &tickets)
// {
// }

// Payment User::selectPaymentMethod()
// {
// }