#include "pokemonCard.h"
#include <iostream>
using namespace std;

PokemonCard::PokemonCard(const string& name, const string& type, const string& family, int evolution,
                         int maxHp, int attackCost1, const string& attackDesc1, int attackDmg1,
                         int attackCost2, const string& attackDesc2, int attackDmg2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution), maxHP(maxHp), hp(maxHp) {
    attacks.emplace_back(attackCost1, 0, attackDesc1, attackDmg1);
    attacks.emplace_back(attackCost2, 0, attackDesc2, attackDmg2);
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
         << ", Evolution Level: " << evolutionLevel << ", HP: " << hp << endl;
    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& [cost, energy, desc, dmg] = attacks[i];
        cout << "Attack #" << i << ": Cost: " << cost
             << ", Current Energy: " << energy << ", Description: " << desc
             << ", Damage: " << dmg << endl;
    }
}

void PokemonCard::attachEnergy(int attackIndex) {
    if (attackIndex < attacks.size()) {
        auto& [cost, energy, desc, dmg] = attacks[attackIndex];
        if (energy < cost) {
            energy++;
        }
    }
}

int PokemonCard::useAttack(int attackIndex) {
    if (attackIndex < attacks.size()) {
        const auto& [cost, energy, desc, dmg] = attacks[attackIndex];
        if (energy >= cost) {
            return dmg;
        }
    }
    return 0;
}

void PokemonCard::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

void PokemonCard::heal() {
    hp = maxHP;
}
