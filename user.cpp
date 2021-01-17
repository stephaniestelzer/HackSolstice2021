#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

    //constructor
    user::user()
    {
     firstName = "John";
     lastName = "Doe";
     username = "JohnDoe123";
     genderIdentity = "NB";
     vector <string> inspirationInput;
     vector <string> supportInput;

    }

    user::user(string _first, string _last, string _username, string _gender, string _password)
    {
        firstName = _first;
        lastName = _last;
        username = _username;
        genderIdentity = _gender;


        vector <string> inspirationInput;
        vector <string> supportInput;

    }

    //functions
    string user::getLast()
    {
        return lastName;
    }

    string user::getUsername()
    {
        return username;
    }

    string user::getPassword()
    {
        return password;
    }


    void user::addMotiveVector(string x)
    {
        inspirationInput.push_back(x);
    }

    void user::addSupportVector(string x)
    {
        supportInput.push_back(x);
    }

    int user::getMotiveSize()
    {
        return inspirationInput.size();
    }

    int user::getSupportSize()
    {
        return supportInput.size();
    }

    void user::DisplayMotiveMessage(int x)
    {
        cout << inspirationInput.at(x) << endl;
    }

    void user::DisplaySupportMessage(int x)
    {
        cout << supportInput.at(x) << endl;
    }


