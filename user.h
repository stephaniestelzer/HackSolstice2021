//
// Created by Stephanie Stelzer on 1/16/21.
//
#ifndef HACKSOLSTICE2021_USER_H
#define HACKSOLSTICE2021_USER_H
#endif //HACKSOLSTICE2021_USER_H
#include <iostream>
#include <string>
#include <vector>
//#include "inspoMessage.h"
//#include "encourageMessage.h"

using namespace std;

//Class of users database
class user{
string firstName, lastName;
string username;
string password;
string genderIdentity;

vector<user> collection;
vector<user> friends;

vector<string> inspirationInput;
vector<string> supportInput;

public:

//constructor
user();

user(string _first, string _last, string _username, string _gender, string _password) {
     //inspoMessage _inspo, encourageMessage _encourage) {
    firstName = _first;
    lastName = _last;
    username = _username;
    password = _password;
    genderIdentity = _gender;
    //inspoMessage();

}


//functions
void newUsers();        //create a new user and add to collection
void
addFriend();       //search collection.firstname and collection.lastname to find user in collection and add to friend vector

void submit(int userchoice);

void relayMessage();


};