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

class CatsOnTheLineDiv2 {
    public:
        string getAnswer(vector <int> position, vector <int> count, int time);
};
		
string CatsOnTheLineDiv2::getAnswer(vector <int> position, vector <int> count, int time){
    int i; 
    int j;
    int k;
    int intersecting_cats;
    vector <int> intersecting_positions;
    set <int> point_set;
    
    intersecting_cats = 0;
    point_set.clear();

    for (i = 0; i < position.size(); i++){
        intersecting_positions.resize(0);
        intersecting_positions.push_back(i);
        for (j = 0; j < position.size(); j++){
            if (j != i){
                if (position[j] < position[i]){
                    if ((position[j] + time) >= (position[i]  - time)){
                        intersecting_positions.push_back(j);
                    }
                } else{
                    if ((position[i] + time) >= (position[j] - time)){
                        intersecting_positions.push_back(j);
                    }
                }
            }
        }
        intersecting_cats = 0;
        point_set.clear();
        for (j = 0; j < intersecting_positions.size(); j++){
            intersecting_cats += count[intersecting_positions[j]];
            point_set.insert(position[intersecting_positions[j]]);
            for (k = 1; k <= time; k++){
                point_set.insert(position[intersecting_positions[j]] + k);
                point_set.insert(position[intersecting_positions[j]] - k);
            }
        }
        if (intersecting_cats > point_set.size()){
            return "Impossible";
        }
    }

    return "Possible";
}
