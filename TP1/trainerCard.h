#pragma once
#include "Card.h"

class TrainerCard : public Card {
private:
    string trainerEffect;

public:
    TrainerCard(const string& name, const string& effect);
    void displayInfo() const override;
    const string& getEffect() const;
};
