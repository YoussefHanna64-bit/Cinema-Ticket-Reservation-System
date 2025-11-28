#include <iostream>
#include "AdminUI.hpp"
#include <array>
#include <cstdlib>
#include <conio.h>
#include "../Movie/Movie.hpp"
#include "../System/System.hpp"
using namespace std;
void AdminUI:: printAdminMenu()
{
    array<string, 8> menuItems = {"Add Movie", "Edit Movie", "Delete Movie",
         "List all Movies", "Create Showtime", "Edit Showtimes", "Delete Showtimes", "Exit"};
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
void AdminUI:: addMovie()
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
void AdminUI:: editMovie()
{
    cout << "Edit Movie Function Called" << endl;
}
void AdminUI:: deleteMovie()
{
    cout << "Delete Movie Function Called" << endl;
}
void AdminUI::displayAllMovies()
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
void AdminUI::createShowtime()
{
    cout << "Create Showtime Function Called" << endl;
}
void AdminUI:: editShowtime()
{
    cout << "Edit Showtime Function Called" << endl;
}
void AdminUI:: deleteShowtime()
{
    cout << "Delete Showtime Function Called" << endl;
}