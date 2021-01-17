//
// Created by Stephanie Stelzer on 1/16/21.
//

#ifndef HACKSOLSTICE2021_MESSAGES_H
#define HACKSOLSTICE2021_MESSAGES_H

#endif //HACKSOLSTICE2021_MESSAGES_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// making a class message
class inspoMessage{
    int numInspoMessages;
    //int numEncourageMessages;
    vector<string> inspoMessageVec;
    //string insertInspoMessage;
    //vector<string> encourageMessage;
    // now we are going to make a constructor

    inspoMessage(int _numInspoMessage, vector<string> _inspoMessage); {
        numInspoMessages = _numInspoMessage;
        inspoMessage = _inspoMessage;
    }

    insertinspoMessageVec(string _inspoMessage); {
        inspoMessage.insert(inspoMessage.begin() + numInspoMessages, _inspoMessage);
        numInspoMessages++;
    }


};