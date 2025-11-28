#include "Movie/Movie.hpp"
#include "UI/UI.hpp"
#include "AdminUI/AdminUI.hpp"
#include "UserUI/UserUI.hpp"
#include "ShowTime/ShowTime.hpp"

int main()
{   UI ui; 
    ui.login();
    /*Showtime showtime("2020-01-01", 10.00, 100);
    showtime.reserveSeat(6);
    showtime.reserveSeat(5);
    showtime.reserveSeat(3);
    showtime.reserveSeat(2);
    showtime.displaySeats(2,10);
    int x;
    cin >> x;
    return 0;*/
    /* To run on vs code 
    g++ code/main.cpp ^
    code/Movie/*.cpp ^
    code/ShowTime/*.cpp ^
    code/User/*.cpp ^
    code/Admin/*.cpp ^
    code/Person/*.cpp ^
    code/UI/*.cpp ^
    code/Ticket/*.cpp ^
    code/Payment/*.cpp ^
    code/System/*.cpp ^
    code/AdminUI/*.cpp ^
    code/UserUI/*.cpp ^
    -o app.exe
    */
}