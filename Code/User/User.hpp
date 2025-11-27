#include <iostream>
#include <ctime>
#include "Movie.hpp"
#include "Showtime.hpp"

using namespace std;

class User
{
    // Ticket ticket;
    // Payment payment;
public:
    Movie &selectMovie(string date);

    // Showtime &selectShowtime(Movie &movie);

    // vector<int> selectSeat(Showtime &showtime);

    // void makeTicket(Movie &movie, Showtime &showtime, vector<int> &seats);

    void deleteTicket();

    // void cancelReservation(Movie movie, Showtime showtime, vector<int> &seats);

    void completeReservation();

    // float calculateTickets(vector<Ticket> &tickets);

    // Payment selectPaymentMethod();
};