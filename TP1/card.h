#pragma once
#include <string>
using namespace std;

class Card {
protected:
    string cardName;

public:
    Card(const string& name) : cardName(name) {}
    virtual ~Card() = default;

    virtual void displayInfo() const = 0;
};
