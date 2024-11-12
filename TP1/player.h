#pragma once 
#include "card.h"
#include <string>
#include <vector>

using namespace std;

class Player : public Card {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
public:
    Player(string playerName);
    void displayBench();
    void displayAction();
}