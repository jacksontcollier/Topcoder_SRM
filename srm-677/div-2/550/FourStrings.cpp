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

string generate_min(string super, string a, string b, string c, string d){
    int i; 
    int j; 
    string min;
    
    for (i = 1; i < super.size(); i++){
        j = 0;
        while (j + i < super.size()){
            min = super;
            min.erase(j, i);
            if (min.find(a) == string::npos){
                j++;
                continue;
            } else if (min.find(b) == string::npos){
                j++;
                continue;
            } else if (min.find(c) == string::npos){
                j++;
                continue;
            } else if (min.find(d) == string::npos){
                j++;
                continue;
            } else{
                super.erase(j, i);
            }
        }
    }

    return super;
}

class FourStrings {
    public:
        int shortestLength(string a, string b, string c, string d);
};
		
int FourStrings::shortestLength(string a, string b, string c, string d){
    int min; 
    string super_supremum;
    vector <string> sub_list; 

    sub_list.resize(0);
    sub_list.push_back(a);
    sub_list.push_back(b);
    sub_list.push_back(c);
    sub_list.push_back(d);
    
    min = -1;
    sort(sub_list.begin(), sub_list.end());

    do {
        super_supremum = sub_list[0] + sub_list[1] + sub_list[2] + sub_list[3];
        super_supremum = generate_min(super_supremum, a, b, c, d);
        if ((min < 0) || (super_supremum.size() < min)){
            min = super_supremum.size();
        }
    } while (next_permutation(sub_list.begin(), sub_list.begin() + 4));

    return min;
}


// Powered by FileEdit


// Powered by FileEdit


// Powered by FileEdit
