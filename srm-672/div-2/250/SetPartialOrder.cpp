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

class SetPartialOrder {
    public:
        string compareSets(vector <int> a, vector <int> b);
};
		
string SetPartialOrder::compareSets(vector <int> a, vector <int> b){
    int i = 0; 
    set <int> x;
    set <int> y;
    set <int>::iterator sit_i;
    set <int>::iterator sit_j;
    bool x_subset_of_y = false;
    bool y_subset_of_x = false;

    x.clear();
    y.clear();

    for (i = 0; i < a.size(); i++){
        x.insert(a[i]);
    }

    for (i = 0; i < b.size(); i++){
        y.insert(b[i]);
    }
    
    x_subset_of_y = true;
    for (sit_i = x.begin(); sit_i != x.end(); sit_i++){
        if ((sit_j = y.find(*sit_i)) == y.end()){
            x_subset_of_y = false;
            break;
        }
    }

    y_subset_of_x = true;

    for (sit_i = y.begin(); sit_i != y.end(); sit_i++){
        if ((sit_j = x.find(*sit_i)) == x.end()){
            y_subset_of_x = false;
            break;
        }
    }

    if (x_subset_of_y && y_subset_of_x){
        return "EQUAL";
    } else if (x_subset_of_y && (!y_subset_of_x)){
        return "LESS";
    } else if ((!x_subset_of_y) && y_subset_of_x){
        return "GREATER";
    } else{
        return "INCOMPARABLE";
    }
}
