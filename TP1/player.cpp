#include "player.h"
#include <iostream>
#include <algorithm>
using namespace std;

Player::Player(const string& name) : playerName(name) {}

Player::~Player() {
    for (auto card : benchCards) {
        delete card;
    }
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex < benchCards.size()) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + benchIndex);
        }
    }
}

void Player::attachEnergyCard(int energyIndex, int attackIndex) {
    if (energyIndex < benchCards.size()) {
        EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
        if (energy) {
            if (!actionCards.empty()) {
                actionCards[0]->attachEnergy(attackIndex);
                benchCards.erase(benchCards.begin() + energyIndex);
                delete energy;
            }
        }
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (auto card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (auto pokemon : actionCards) {
        pokemon->displayInfo();
    }
}

void Player::attack(int attackIndex, int playerAttackIndex, Player& opponent, int opponentActionIndex) {
    if (attackIndex < actionCards.size() && opponentActionIndex < opponent.actionCards.size()) {
        int damage = actionCards[attackIndex]->useAttack(playerAttackIndex);
        opponent.actionCards[opponentActionIndex]->takeDamage(damage);

        cout << playerName << " is attacking " << opponent.playerName << "'s Pokemon with "
             << actionCards[attackIndex]->getName() << endl;
    }
}
void Player::useTrainer(int trainerIndex) {
    if (trainerIndex < benchCards.size()) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[trainerIndex]);
        if (trainer) {
            for (auto pokemon : actionCards) {
                pokemon->heal();
            }
        }
    }
}
