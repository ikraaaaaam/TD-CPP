#include "trainerCard.h"
#include <iostream>
using namespace std;

TrainerCard::TrainerCard(const string& name, const string& effect)
    : Card(name), trainerEffect(effect) {}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << endl;
}

const string& TrainerCard::getEffect() const {
    return trainerEffect;
}
