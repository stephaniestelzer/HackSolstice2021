#include <iostream> 
#include <string> 
#include <vector>
#include <map>
#include "user.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;


map<string, user> database;
string currentUser;

void createAccount();
void printMenu();
void signIn();
void printMenu() {
    cout << "Hello! Please select an option: " << endl;
    cout << "1. Support/Encouragement" << endl;
    cout << "2. Inspiration/Motivation" << endl;
    cout << "3. Write a message" << endl;
}
void signIn() {
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
        catch (...) {
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
    if (userChoiceInt == 1) {       //user wishes to login to their account
        // prompt sign-in
        cout << "Please enter your username: " << endl;
        cin >> userName;

        if (database.find(userName) != database.end())      //true if a username exists in the map
        {
            //we can prompt the user to provide their password
           
            cout << "Please enter your password: " << endl;
            cin >> password;
            
            if (database[userName].getPassword() != password)       //true if password does not match username
            {
                int tries = 3;
                while (database[userName].getPassword() != password && tries > 1)   //user gets 3 tries at password
                {
                    tries--;
                    cout << "Your password is Incorrect. Retries Left:  " << tries << endl;
                    cin >> password;
                    
                }

                if (tries == 1)
                {
                    cout << "Error: password is not valid. Please make a new account." << endl;
                    createAccount();
                }
            }
            else
            {
                currentUser = userName;
            }

        }
        else    //true if username does not exist 
        {
            cout << "Error: Unable to find inputted username. Please try again" << endl;
            cin >> userName;

            if (database.find(userName) == database.end())  //still can't find username
            {
                cout << "Error: username is not valid. Please make a new account." << endl;
                createAccount();
            }
            else        //able to find username (prompt password)
            {
                cout << "Please enter your password: " << endl;
                cin >> password;

                if (database[userName].getPassword() != password)       //true if password does not match username
                {
                    int tries = 3;
                    while (database[userName].getPassword() != password && tries > 1)   //user gets 3 tries at password
                    {
                        tries--;
                        cout << "Your password is Incorrect. Retries Left:  " << tries << endl;
                        cin >> password;

                    }

                    if (tries == 1)
                    {
                        cout << "Error: password is not valid. Please make a new account." << endl;
                        createAccount();
                    }
                }
                else
                {
                    currentUser = userName;
                }
            }
        }

        // reference function to make sure these values exist and match 
    }
    else if (userChoiceInt == 2) {
        // this will prompt the user to create an account
        createAccount();
    }
}
void addToMap(user temp)
{
    database.emplace(temp.getUsername(),temp);
}
void createAccount() {
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

    user temp(firstName, lastName, username, genderIdentity, password);
    addToMap(temp);
    currentUser = username;
    ofstream outFile;
    outFile.open("User Profiles (2).csv", ios_base::app);
    outFile << endl << firstName << "," << lastName << "," << username << "," << password << ",0" << endl;

    // add variables into a user constructor
}
void supportEncouragement() {

    if (database[currentUser].getSupportSize() > 0)
    {
        srand(time(nullptr));
        int random = rand() % (database[currentUser].getSupportSize());

        database[currentUser].DisplaySupportMessage(random);
    }

    else
    {
        cout << "A message has not been sent. Oscar Wilde once said '/Be Yourself; everyone else is already taken.'/" << endl;
    }
    //have a database full of messages from friends for the computer
    // to sort into the two categories and choose based off of the
    // user category chosen. implement random factor so that it will be different
}
void inspirationMotivation() 
{
    if (database[currentUser].getMotiveSize() > 0)
    {
        srand(time(nullptr));
        int random = rand() % (database[currentUser].getMotiveSize());

        database[currentUser].DisplayMotiveMessage(random);
    }

    else
    {
        cout << "A message has not been sent. Eleanor Roosevelt once said '/No one can make you feel inferior without your consent'/" << endl;
    }
}
void writeMessage() {
    string input;
    int inputInt;
    string message;
    bool validInput = false;

    cout << "Please enter a message for support and encouragement" << endl;
        cin.ignore();
        getline(cin, message);

    
        cout << "Please enter a message for Inspiration and motivation" << endl;
        cin.ignore();
        getline(cin, message);

    //assign to random user
    
    srand(time(nullptr));
    int random = rand() % (database.size());
    map<string, user>::iterator iter;

    int counter = 0;
    for (iter = database.begin(); iter != database.end(); iter++)
    {
        if (counter == random)
        {
            iter->second.addMotiveVector(message);
            iter->second.addSupportVector(message);
        }
        else
        {
            counter++;
        }
    }
    
    //database would sort the message into the correct category

}
void readUserFile()
{
    ifstream inFS;
    inFS.open("User Profiles (2).csv");

    if (inFS.is_open())
    {

        while (!inFS.eof())
        {
            //at beginning of a new row
            string tempFirst;
            string tempLast;
            string tempUsername;
            string tempGender;
            string tempPass;

            string token;

            int numMessages = 0;

            for (int i = 1; i <7; i++)     //goes through each row
            {
                if (i == 1)       //on the first cell of the row (first name)
                {
                    getline(inFS, tempFirst, ',');
                    cout << tempFirst << endl;
                }
                else if (i == 2)      //on the second cell of the row (last name)
                {
                    getline(inFS, tempLast, ',');
                    cout << tempFirst << endl;
                }
                else if (i == 3)        //on the third cell of the row (user name)
                {
                    getline(inFS, tempUsername, ',');
                    cout << tempFirst << endl;
                }
                else if (i == 4)        //on the fourth cell of the row (gender)
                {
                    getline(inFS, tempGender, ',');
                    cout << tempFirst << endl;
                }
                else if (i == 5)        //on the 5th cell of the row (password)
                {
                    getline(inFS, tempPass,',');
                    cout << tempFirst << endl;
                }

                else if (i == 6)        //on the 6th cell of the row (# of messages)
                {
                    getline(inFS, token);
                    cout << tempFirst << endl;
                    try
                    {
                       numMessages = stoi(token);
                    }
                    catch (...)
                    {
                        cout << "Error: Can't convert string to integer" << endl;
                    }
                }
              

                user temp(tempFirst, tempLast, tempUsername, tempGender, tempPass);

                //create user and add to map

                addToMap(temp);

                for (int i = 1; i <= numMessages; i++)
                {
                    getline(inFS, token);

                    if (i <= (numMessages / 2))
                    {
                        temp.addMotiveVector(token);
                    }
                    else
                    {
                        temp.addSupportVector(token);
                    }
                    

                }
                
                

            }


        }
    }
   
}



int main() {
    // begin with if statements that log the user in to their account
    // if they can't be logged in, prompt them to make an account
    // if successfully logged in, prompt the user with 3 options

        // go into printing out options
      // begin with if statements that log the user in to their account
    // if they can't be logged in, prompt them to make an account
    // if successfully logged in, prompt the user with 3 options

    readUserFile();
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
        catch (const invalid_argument& ia) {
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
