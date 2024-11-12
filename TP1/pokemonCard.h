#pragma once
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card{
protected:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks;
public:
    PokemonCard::PokemonCard(const string name, const string type, const string family, int evolution, int max_hp, int current_hp,
                         const vector<tuple<int, int, string, int>>& attacks);
}