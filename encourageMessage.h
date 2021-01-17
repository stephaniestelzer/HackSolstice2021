//
// Created by Stephanie Stelzer on 1/16/21.
//

#ifndef HACKSOLSTICE2021_ENCOURAGEMESSAGE_H
#define HACKSOLSTICE2021_ENCOURAGEMESSAGE_H

#endif //HACKSOLSTICE2021_ENCOURAGEMESSAGE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// making a class message
class encourageMessage{
public:
    int numEncourageMessages;
    vector<string> encourageMessageVec;
    // now we are going to make a constructor
    encourageMessage(int _numEncourageMessage, vector<string> _encourageMessage); {
        numEncourageMessages = _numEncourageMessage;
        encourageMessage = _encourageMessage;
    }

    insertEncourageMessageVec(string _encourageMessage); {
        inspoMessage.insert(encourageMessage.begin() + numEncourageMessage, _ncourageMessage);
        numEncourageMessages++;
    }


}
