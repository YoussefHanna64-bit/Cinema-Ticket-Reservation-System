#include "UI.hpp"
#include "../Movie/Movie.hpp"
#include "../System/System.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <conio.h>
using namespace std;

void login()
{
    cout << "\033[38m" << "Login" << "\033[0m" << endl;
    cout << "-----------" << endl;

    cout << "Username: ";
    string username;
    cin >> username;
    while (username != "admin")
    {
        cout << "\033[31m" << "Invalid username. Please try again." << "\033[0m" << endl;
        cout << "Username: ";
        cin >> username;
    }
    system("cls");

    cout << "Welcome, " << username << "!" << endl;
    cout << "--------------" << endl;

    cout << "Password: ";
    string password;
    cin >> password;

    while (password != "password")
    {
        cout << "\033[31m" << "Invalid password. Please try again." << "\033[0m" << endl;
        cout << "Password: ";
        cin >> password;
    }

    if (username == "admin" && password == "password")
    {
        system("cls");
        cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        printAdminMenu();
    }
    else if (username == "user" && password == "password")
    {
        system("cls");
        cout << "\033[32m" << "Login successful!" << "\033[0m" << endl;
        cout << "Press any key to continue..." << endl;
        _getch();
        printUserMenu();
    }
    else
    {
        cout << "\033[31m" << "Login failed! Invalid username or password." << "\033[0m" << endl;
    }
}

void printUserMenu()
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

void printAdminMenu()
{
    array<string, 8> menuItems = {"Add Movie", "Edit Movie", "Delete Movie", "List all Movies", "Create Showtime", "Edit Showtimes", "Delete Showtimes", "Exit"};
    int selected = 0;
    bool flag = true;

    system("");

    while (flag)
    {
        system("cls");
        cout << "\033[38m" << "Dashboard" << "\033[0m" << endl;
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
                addMovie();
                break;
            case 1:
                editMovie();
                break;
            case 2:
                deleteMovie();
                break;
            case 3:
                displayAllMovies();
                break;
            case 4:
                createShowtime();
                break;
            case 5:
                editShowtime();
                break;
            case 6:
                deleteShowtime();
                break;
            case 7:
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
///////////////////// Admin Functions ///////////////
void addMovie()
{
    string title, description, genre;
    float rating, duration;

    cout << "Add Movie" << endl;
    cout << "-----------------" << endl;
    cout << "Title:                             Description:" << endl;
    cout << "Genre:                             Rating:" << endl;
    cout << "Duration: " << endl;

    cout << "\033[3A";
    cout << "\033[7C";
    getline(cin, title);

    cout << "\033[1A";
    cout << "\033[48C";
    getline(cin, description);

    cout << "\033[7C";
    cin >> genre;
    cin.get();

    cout << "\033[1A";
    cout << "\033[43C";
    cin >> rating;
    cin.get();

    cout << "\033[10C";
    cin >> duration;

    cin.get();

    Movie movie(title, description, genre, rating, duration);
    System::movies.push_back(movie);
}
void editMovie()
{
    cout << "Edit Movie Function Called" << endl;
}
void deleteMovie()
{
    cout << "Delete Movie Function Called" << endl;
}
void displayAllMovies()
{
    cout << "All Movies:" << endl;
    for (auto &movie : System::movies)
    {

        cout << "Title: " << movie.get_title() << "                           Description: " << movie.get_desc() << endl;
        cout << "Genre: " << movie.get_genre() << "                        Rating: " << movie.get_rating() << endl;
        // cout << "Duration: " << movie.get_duration() << " mins " << endl;
        cout << "----------------------------------------" << endl;
    }
}
void createShowtime()
{
    cout << "Create Showtime Function Called" << endl;
}
void editShowtime()
{
    cout << "Edit Showtime Function Called" << endl;
}
void deleteShowtime()
{
    cout << "Delete Showtime Function Called" << endl;
}
///////////////////// User Functions ///////////////
void reserveTicket()
{
    cout << "Reserve Ticket Function Called" << endl;
}
void cancelReservation()
{
    cout << "Cancel Reservation Function Called" << endl;
}
void viewReservedTickets()
{
    cout << "View Reserved Tickets Function Called" << endl;
}
