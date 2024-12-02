#pragma once
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <vector>

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name);
    ~Player();

    void addCardToBench(Card* card);
    void activatePokemonCard(int benchIndex);
    void attachEnergyCard(int energyIndex, int attackIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int attackIndex, int playerAttackIndex, Player& opponent, int opponentActionIndex);
    void useTrainer(int trainerIndex);
};
