#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

class MarbleNecklace {
    public:
        string normalize(string necklace);
};
		
string MarbleNecklace::normalize(string necklace){
    int i;
    char min;
    string first;
    string second;
    vector <string> min_substrings;

    min = necklace[0];
    for (i = 1; i < necklace.size(); i++){
        if (necklace[i] < min) min = necklace[i];
    }

    min_substrings.resize(0);
    for (i = 0; i < necklace.size(); i++){
        if (necklace[i] == min){
            /* Add forward going string */
            first = necklace.substr(i, necklace.size() - i);
            second = necklace.substr(0, i);
            min_substrings.push_back(first + second);

            /* Add backward going string */
            first = necklace.substr(0, i + 1);
            second = necklace.substr(i + 1, necklace.size() - (i + 1));
            reverse(first.begin(), first.end());
            reverse(second.begin(), second.end());
            min_substrings.push_back(first + second);
        }
    }

    sort(min_substrings.begin(), min_substrings.end());

    return min_substrings[0];
}


// Powered by FileEdit
