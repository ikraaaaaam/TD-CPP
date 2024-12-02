#pragma once
#include "card.h"
#include <vector>
#include <tuple>

class PokemonCard : public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks;

public:
    PokemonCard(const string& name, const string& type, const string& family, int evolution,
                int maxHp, int attackCost1, const string& attackDesc1, int attackDmg1,
                int attackCost2, const string& attackDesc2, int attackDmg2);

    void displayInfo() const override;
    void attachEnergy(int attackIndex);
    int useAttack(int attackIndex);
    void takeDamage(int damage);
    void heal();
};
