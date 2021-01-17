#include <iostream>
#include <string>
#include <vector>
using namespace std;
void createAccount();
void printMenu();
void signIn();
void printMenu() {
    cout << "Hello! Please select an option: " << endl;
    cout << "1. Support/Encouragement" << endl;
    cout << "2. Inspiration/Motivation" << endl;
    cout << "3. Write a message" << endl;
}
void signIn (){
    cout << "Press 1 to sign in." << endl;
    cout << "Press 2 to make an account." << endl;
    string userChoice;
    int userChoiceInt;
    bool validInput = false;
    string userName;
    string password;

    while (validInput == false) {
        cin >> userChoice;

        try {
            userChoiceInt = stoi(userChoice);
        }
        catch (const invalid_argument &ia) {
            cout << "Please enter a number 1-2" << endl;
            continue;
        }

        if (userChoiceInt > 2 || userChoiceInt < 1) {
            cout << "Please enter a number 1-2" << endl;
        }
        else {
            validInput = true;
        }

    }
    // make different options happen
    if(userChoiceInt == 1){
        // prompt sign-in
        cout << "Please enter your username: " << endl;
        cin >> userName;
        cout << "Please enter your password: " << endl;
        cin >> password;
        // reference function to make sure these values exist and match
    }
    else if (userChoiceInt ==2){
        // this will prompt the user to create an account
        createAccount();
    }
}
void createAccount(){
    string firstName;
    string lastName;
    string username;
    string password;
    string genderIdentity;

     cout << "Please enter your first name." << endl;
     cin >> firstName;
     cout << "Please enter your last name." << endl;
     cin >> lastName;
     cout << "Please create a username." << endl;
     cin >> username;
     cout << "Please create a password." << endl;
     cin >> password;
     cout << "Please select your gender identity" << endl;
     cin >> genderIdentity;
     // user(firstName, lastName, username, genderIdentity, password);
     // add variables into a user constructor
}
void supportEncouragement(){
    //have a database full of messages from friends for the computer
    // to sort into the two categories and choose based off of the
    // user category chosen. implement random factor so that it will be different
}
void inspirationMotivation(){

}
string writeMessage() {
    string input;
    int inputInt;
    string message;
    bool validInput;

    cout << "Which category would you like to write a message for?" << endl;
    cout << "1. Support and Encouragement" << endl;
    cout << "2. Inspiration and Motivation" << endl;

    while (validInput == false) {
        cin >> input;

        try {
            inputInt = stoi(input);
        }
        catch (const invalid_argument &ia) {
            cout << "Please enter a number 1-2" << endl;
            continue;
        }

        if (inputInt > 2 || inputInt < 1) {
            cout << "Please enter a number 1-2" << endl;
        }
        else {
            validInput = true;
        }

    }

    if (inputInt == 1) {
        cout << "What would you like to say for support and encouragement?" << endl;
        cin.ignore();
        getline(cin, message);
    }
    else if (inputInt == 2) {
        cout << "What would you like to say for inspiration and motivation?" << endl;
        cin.ignore();
        getline(cin, message);
    }

    return message;

    //database would sort the message into the correct category

}

int main() {
    // begin with if statements that log the user in to their account
    // if they can't be logged in, prompt them to make an account
    // if successfully logged in, prompt the user with 3 options

    // go into printing out options
    signIn();
    printMenu();
    int userChoiceInt;
    string userChoice;
    bool validInput = false;

    while (validInput == false) {
        cin >> userChoice;

        try {
            userChoiceInt = stoi(userChoice);
        }
        catch (const invalid_argument &ia) {
            cout << "Please enter a number 1-3" << endl;
            continue;
        }

        if (userChoiceInt > 3 || userChoiceInt < 1) {
            cout << "Please enter a number 1-3" << endl;
        }
        else {
            validInput = true;
        }

    }

    if (userChoiceInt == 1) {
        supportEncouragement();
    }
    else if (userChoiceInt == 2) {
        inspirationMotivation();
    }
    else if (userChoiceInt == 3) {
        writeMessage();
    }


    //
    return 0;
}
