#include "card.h"
#include <iostream>

PokemonCard::PokemonCard(const string cardName, const string typeName, 
const string familyName, int evolutionLevel, int maxHP, int hp, 
const vector<tuple<int, int, string, int>> attacks):typeName(typeName), 
familyName(familyName), evolutionLevel(evolutionLevel), maxHP(maxHP), 
hp(hp), attacks(attacks)
{
    this->cardName=cardName;
}

void PokemonCard::displayInfo() const{
    cout<< "Pokemon Name:" << cardName << endl;
    cout<< "Pokemon Type:" << cardType << endl;
    cout<< "Family Name:" << familyName << endl;
    cout<< "Evolution Level:" << evolutionLevel << endl;
    cout<< "Maximum Health Point:" << maxHP << endl;
    cout<< "Health Point:" << hp << endl;
    cout<< "\nAttacks:" <<  endl;

    
    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& [energyCost, currentEnergyCost, description, damage] = attacks[i];
        cout << "  Attaque " << (i + 1) << " :" << endl;
        cout << "    Coût en énergie : " << energyCost << endl;
        cout << "    Coût en énergie actuel : " << currentEnergyCost << endl;
        cout << "    Description : " << description << endl;
        cout << "    Dégâts : " << damage << endl;
    }
}