#include <iostream>
#include <../System/System.hpp>
using namespace std;

class Person {
    string username;
    string password;
    System* system;
public:
    bool Authenticate(string uname, string pword);
};
