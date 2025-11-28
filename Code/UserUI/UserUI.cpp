#include "UserUI.hpp"
#include "../Movie/Movie.hpp"
#include "../System/System.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <conio.h>
using namespace std;

void UserUI:: printUserMenu()
{
    array<string, 4> menuItems = {"Reserve Ticket", "Cancel Reservation", "View Reserved Tickets", "Exit"};
    int selected = 0;
    bool flag = true;

    system("");

    while (flag)
    {
        system("cls");
        cout << "\033[38m" << "Main Menu" << "\033[0m" << endl;
        cout << "--------------" << endl;

        for (int i = 0; i < menuItems.size(); ++i)
        {
            if (i == selected)
            {
                cout << "\033[32m" << "> " << menuItems[i] << "\033[0m" << endl;
            }
            else
            {
                cout << "  " << menuItems[i] << endl;
            }
        }

        int key = _getch();

        switch (key)
        {
        case 72:
        {
            selected = (selected - 1) % menuItems.size();
            break;
        }
        case 80:
        {
            selected = (selected + 1) % menuItems.size();
            break;
        }
        case 13:
        {
            system("cls");

            switch (selected)
            {
            case 0:
                reserveTicket();
                break;
            case 1:
                cancelReservation();
                break;
            case 2:
                viewReservedTickets();
                break;
            case 3:
                cout << "Cya!" << endl;
                flag = false;
                break;
            }

            if (flag)
            {
                cout << endl;
                cout << "\033[32m" << "Press any key to return to menu!" << "\033[0m" << endl;
                _getch();
            }
            break;
        }
        case 27:
        {
            cout << "Cya!" << endl;
            flag = false;
            break;
        }
        }
    }
}

///////////////////// User Functions ///////////////
void UserUI::reserveTicket()
{
    cout << "Reserve Ticket Function Called" << endl;
}
void UserUI:: cancelReservation()
{
    cout << "Cancel Reservation Function Called" << endl;
}
void UserUI:: viewReservedTickets()
{
    cout << "View Reserved Tickets Function Called" << endl;
}
