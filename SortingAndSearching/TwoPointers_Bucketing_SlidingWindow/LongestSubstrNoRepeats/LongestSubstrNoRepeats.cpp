#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    // условие: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

    string str = "pwwkew";

    unordered_map<char, int> char_ind;

    int max = 0, curr = 0, start = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (char_ind.find(str[i]) == char_ind.end() || char_ind[str[i]] < start)
        {
            char_ind[str[i]] = i;
            curr++;
        }
        else
        {
            start = char_ind[str[i]] + 1;
            char_ind[str[i]] = i;

            curr = i - start + 1;
        }
        max = std::max(max, curr);
    }

    cout << max;

    return 0;
}