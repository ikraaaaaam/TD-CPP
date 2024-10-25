#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    int numbers_size = numbers.size();
    vector<int> freq(numbers_size, 1);
    vector<bool> visited(numbers_size, false);

    for (int i = 0; i < numbers_size; ++i) {
        if (visited[i]) continue;
        for (int j = i + 1; j < numbers_size; ++j) {
            if (numbers[i] == numbers[j]) {
                freq[i]++;
                visited[j] = true;
            }
        }
        cout << "Element " << numbers[i] << " appears " << freq[i] << " times." << endl;
    }
}


map<int,int> countFrequencyOptimal(const vector<int>& numbers){
    map<int, int> countFrequencyOptimal(const vector<int>& vec)
    for(int num=0; num < vec ; num++){
        countFrequencyOptimal[num]++;
    }
    return countFrequencyOptimal;
}
int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);

    return 0;
}
