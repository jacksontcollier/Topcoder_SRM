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

class TriangleType {
    public:
        string type(int a, int b, int c);
};
		
string TriangleType::type(int a, int b, int c){
    vector <int> lengths;

    lengths.push_back(a);
    lengths.push_back(b);
    lengths.push_back(c);

    sort(lengths.begin(), lengths.end());

    if (pow(lengths[0], 2) + pow(lengths[1], 2) == pow(lengths[2], 2)){
        return "RIGHT";
    } else if (pow(lengths[0], 2) + pow(lengths[1], 2) > pow(lengths[2], 2)){
        return "ACUTE";
    } else if (lengths[0] + lengths[1] <= lengths[2]){
        return "IMPOSSIBLE";
    }

    return "OBTUSE";
}
