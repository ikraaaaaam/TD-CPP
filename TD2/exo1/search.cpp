#include "search.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(ostream& os, int result, int target) {
    os << "Recherche de l'élément " << target;
    if (result != -1) {
        os << " trouvé à l'indice " << result << " après " << numberComparisons << " comparaisons." << endl;
    } else {
        os << " non trouvé après " << numberComparisons << " comparaisons." << endl;
    }
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
    os << "Nombre total de comparaisons: " << totalComparisons << endl;
    os << "Nombre total de recherches: " << totalSearch << endl;
    os << "Nombre moyen de comparaisons: " << averageComparisons << endl;
}
