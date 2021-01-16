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
    
    vector <user> collection;
    vector <user> friends;

    vector <string> inspirationInput;
    vector <string> supportInput;
    
    public:

    //constructor
    user();
    user(string _first, string _last, string _username, string _gender, string _password);

    //functions
    void newUsers();        //create a new user and add to collection
    void addFriend();       //search collection.firstname and collection.lastname to find user in collection and add to friend vector

    void submit(int userchoice);

    void relayMessage();


}