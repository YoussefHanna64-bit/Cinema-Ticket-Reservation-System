#include <iostream>
#include "AdminUI.hpp"
#include <array>
#include <cstdlib>
#include <conio.h>
#include "../Movie/Movie.hpp"
#include "../System/System.hpp"
using namespace std;
void AdminUI::printAdminMenu()
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
void AdminUI::addMovie()
{
    string title, description, genre;
    float rating, duration;

    cout << "Add Movie" << endl;
    cout << "-----------------" << endl;
    cout << "\033[3;0H" << "Title: ";
    getline(cin, title);
    cout << "\033[3;" << 15 + title.length() << "H" << "Description: ";
    getline(cin, description);
    cout << "\033[4;0H" << "Genre: ";
    getline(cin, genre);
    cout << "\033[4;" << 15 + title.length() << "H" << "Rating: ";
    cin >> rating;
    cout << "\033[5;0H" << "Duration: ";
    cin >> duration;
    cin.get();

    Movie movie(title, description, genre, rating, duration);
    System::movies.push_back(movie);
}
void AdminUI::editMovie()
{
    string title;
    cout << "Edit Movie" << endl;
    cout << "-----------------" << endl;
    cout << "\033[3;0H" << "Enter Movie Name: ";
    getline(cin, title);

    for (auto &movie : System::movies)
    {
        if (movie.get_title() == title)
        {
            string newDesc = movie.get_desc();
            string newGenre = movie.get_genre();
            float newRating = movie.get_rating();

            int selected = 0;
            bool editing = true;

            while (editing)
            {
                system("cls");
                cout << "Edit Movie" << endl;
                cout << "-----------------" << endl;
                cout << "Title: " << movie.get_title() << endl;
                cout << (selected == 0 ? "\033[32m> " : "  ") << "Description: " << newDesc << "\033[0m" << endl;
                cout << (selected == 1 ? "\033[32m> " : "  ") << "Genre: " << newGenre << "\033[0m" << endl;
                cout << (selected == 2 ? "\033[32m> " : "  ") << "Rating: " << newRating << "\033[0m" << endl;
                cout << "\nPress ESC to save" << endl;

                int key = _getch();

                switch (key)
                {
                case 72: // UP arrow
                    selected = (selected - 1 + 3) % 3;
                    break;
                case 80: // DOWN arrow
                    selected = (selected + 1) % 3;
                    break;
                case 13: // ENTER - edit selected field
                {
                    system("cls");
                    cout << "Edit Movie" << endl;
                    cout << "-----------------" << endl;

                    if (selected == 0)
                    {
                        cout << "New Description: ";
                        getline(cin, newDesc);
                    }
                    else if (selected == 1)
                    {
                        cout << "New Genre: ";
                        getline(cin, newGenre);
                    }
                    else if (selected == 2)
                    {
                        cout << "New Rating: ";
                        cin >> newRating;
                        cin.ignore();
                    }
                    break;
                }
                case 27: // ESC - save and exit
                {
                    movie.set_desc(newDesc);
                    movie.set_genre(newGenre);
                    movie.set_rating(newRating);

                    system("cls");
                    cout << "\033[32mMovie Updated Successfully!\033[0m" << endl;
                    editing = false;
                    break;
                }
                }
            }
            return;
        }
    }
    cout << "Movie not found!" << endl;
}
void AdminUI::deleteMovie()
{
    string title;
    cout << "Delete Movie" << endl;
    cout << "-----------------" << endl;
    cout << "\033[3;0H" << "Enter Movie Name: ";
    getline(cin, title);

    for (auto it = System::movies.begin(); it != System::movies.end(); ++it)
    {
        if (it->get_title() == title)
        {
            System::movies.erase(it);
            cout << "\033[32mMovie Deleted Successfully!\033[0m" << endl;
            return;
        }
    }
    cout << "Movie not found!" << endl;
}
void AdminUI::displayAllMovies()
{
    cout << "All Movies" << endl;
    cout << "-----------------" << endl;
    for (auto &movie : System::movies)
    {
        cout << "Title: " << movie.get_title() << endl;
        cout << "Description: " << movie.get_desc() << endl;
        cout << "Genre: " << movie.get_genre() << endl;
        cout << "Rating: " << movie.get_rating() << endl;
        cout << "-----------------" << endl;
    }
}
void AdminUI::createShowtime()
{
    cout << "Create Showtime Function Called" << endl;
}
void AdminUI::editShowtime()
{
    cout << "Edit Showtime Function Called" << endl;
}
void AdminUI::deleteShowtime()
{
    cout << "Delete Showtime Function Called" << endl;
}