#include <iostream> <string> <vector>
using namespace std;

void menu() {
    cout << "Hello! Please select an option: " << endl;
    cout << "1. Support/Encouragement" << endl;
    cout << "2. Inspiration/Motivation" << endl;
    cout << "3. Write a message" << endl;
}

int main() {
    // begin with if statements that log the user in to their account
    // if they can't be logged in, prompt them to make an account
    // if successfully logged in, prompt the user with 3 options

        // go into printing out options
        menu();

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


    //
    return 0;
}
