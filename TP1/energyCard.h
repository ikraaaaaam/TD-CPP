#pragma once
#include "Card.h"

class EnergyCard : public Card {
private:
    string energyType;

public:
    EnergyCard(const string& type);
    void displayInfo() const override;
    const string& getEnergyType() const;
};
