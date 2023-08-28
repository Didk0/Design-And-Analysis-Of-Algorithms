#include <vector>
#include <iostream>
using namespace std;


int main() {
    string word;
    cin >> word;
    size_t symbs[27] = { 0, };
    size_t odds = 0;

    for (size_t i = 0; i < word.size(); i++) {
        symbs[word[i] - 'a']++;
    }

    for (size_t i = 0; i < 27; i++) {
        if (symbs[i] % 2 != 0)
            odds++;
    }

    if (odds > 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    size_t ind = 0;
    for (size_t i = 0; i < 27; i++)
    {
        while (symbs[i] > 1)
        {
            word[ind] = i + 'a';
            word[word.size() - 1 - ind] = i + 'a';
            symbs[i] -= 2;
            ind++;
        }
        if (symbs[i] == 1) {
            word[word.size() / 2] = i + 'a';
            symbs[i]--;
        }
    }

    cout << word;
    return 0;
}