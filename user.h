#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Class of users database
class user
{
    string firstName, lastName;
    string username;
    string password;
    string genderIdentity;


    vector <string> inspirationInput;
    vector <string> supportInput;

public:

    //constructor
    user();
    user(string _first, string _last, string _username, string _gender, string _password);

    //functions
    string getLast();
    string getUsername();
    string getPassword();
    int getMotiveSize();
    int getSupportSize();
    void DisplayMotiveMessage(int x);
    void DisplaySupportMessage(int x);

    void addMotiveVector(string x);
    void addSupportVector(string x);


};