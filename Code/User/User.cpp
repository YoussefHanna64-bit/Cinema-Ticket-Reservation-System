#include "User.hpp"
#include <vector>

// Movie User::selectMovie(string movieTitle)
// {
//     for (auto &movie : System::movies)
//     {
//         if (movie.get_title() == movieTitle)
//         {
//             return movie;
//         }
//     }
// }

Showtime User::selectShowtime(Movie &movie, float time)
{
    for (auto &showtime : movie.getShowTimes())
    {
        if (showtime.getTime() == time)
        {
            return showtime;
        }
    }
}

vector<int> User::selectSeat(Showtime &showtime, int numberOfSeats) // numberOfSeats: store number of seats he want to reserve
{
    vector<int> seats; // store selected seats
    for (int i = 1; i <= numberOfSeats; i++)
    {
        seats.push_back(i);
        showtime.reserveSeat(i);
    }
    return seats;
}

void User::makeTicket(Movie &movie, Showtime &showtime, vector<int> &seats)
{
    Ticket newTicket(movie.get_title(), showtime.getDate(), showtime.getTime(), 250, seats);
}

// void User::deleteTicket()
// {

// }

// void User::cancelReservation(Movie movie, Showtime showtime, vector<int> &seats)
// {

// }

void User::completeReservation()
{
}

float User::calculateTickets(vector<Ticket> &tickets)
{
    float total = 0;
    for (auto &ticket : tickets)
    {
        total += ticket.getrice();
        // Assuming Ticket class has a method getPrice()
        // total += ticket.getPrice();
    }
    return total;
}

// Payment User::selectPaymentMethod()
// {
// }