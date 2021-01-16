#include <iostream>
#include <string>
#include <vector>
#include "user.h"


string firstName, lastName;
    string username;
    string password;
    string genderIdentity;
    
    vector <user> collection;
    vector <user> friends;

    vector <string> inspirationInput;
    vector <string> supportInput;

using namespace std;

    //constructor
    user::user()
    {
        firstName = "John";
        lastName = "Doe";
        userName = "JohnDoe123";
        genderIdentity = "NB";
        vector <user> collection;
        vector <user> friends;

        vector <string> inspirationInput;
        vector <string> supportInput;


    }

    user::user(string _first, string _last, string _username, string _gender; string _password)
    {
        firstName = _first;
        lastName = _last;
        userName = _username;
        genderIdentity = _gender;

        vector <user> collection;
        vector <user> friends;

        vector <string> inspirationInput;
        vector <string> supportInput;

    }

    //functions
    void user::newUsers()        //create a new user and add to collection
    {
            
    }

    void user::addFriend()      //search collection.firstname and collection.lastname to find user in collection and add to friend vector
    {

    }
    void user::submit(int userchoice)
    {

    }

    void user::relayMessage()
    {

    }


