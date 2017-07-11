#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class ChangingSounds{
    public:
        int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel);
};

int ChangingSounds::maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel){
    int i = 0;
    int max_volume = -1;
    set <int> prev_set;
    set <int> new_set;
    set <int>::iterator sit;

    new_set.insert(beginLevel);

    for (i = 0; i < changeIntervals.size(); i++){
        prev_set = new_set;
        new_set.clear();
        for (sit = prev_set.begin(); sit!= prev_set.end(); sit++){
            if (i == changeIntervals.size() - 1){
                if ((*sit + changeIntervals[i] <= maxLevel) && (*sit + changeIntervals[i] > max_volume)){
                    max_volume = *sit + changeIntervals[i];
                }
                
                if ((*sit - changeIntervals[i] >= 0) && (*sit - changeIntervals[i] > max_volume)){
                    max_volume = *sit - changeIntervals[i];
                }
            } else{
                if (*sit + changeIntervals[i] <= maxLevel){
                    new_set.insert(*sit + changeIntervals[i]);
                } 

                if (*sit - changeIntervals[i] >= 0){
                    new_set.insert(*sit - changeIntervals[i]);
                }
            }
        }
    }

    return max_volume;
}
