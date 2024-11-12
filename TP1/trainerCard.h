#pragma once 
#include "card.h"
#include <string>

using namespace std;

class TrainerCard : public Card {
protected:
    string trainerEffect;
public:
    TrainerCard(string trainerEffect);
    void displayInfo();
}

