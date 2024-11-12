#pragma once
#include <string>

using namespace std;

class Card{
protected:
    string cardName;
public:
    virtual void displayInfo() const=0;
}