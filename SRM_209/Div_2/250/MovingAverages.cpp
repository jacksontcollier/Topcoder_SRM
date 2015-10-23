#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class MovingAverages{
    public:
        vector <int> calculate(vector <string> times, int n) ;
};

double calc_avg(vector <string> iteration){
    int i = 0;
    int hours = 0;
    int mins = 0;
    int secs = 0;
    int total_secs = 0;
    stringstream ss;

    for (i = 0; i < iteration.size(); i++){
        ss.clear();
        ss << iteration[i].substr(0, 2);
        ss >> hours;

        ss.clear(); 
        ss << iteration[i].substr(3, 2);
        ss >> mins;

        ss.clear();
        ss << iteration[i].substr(6, 2);
        ss >> secs;

        total_secs += (60 * 60 * hours) + (60 * mins) + (secs);
    }

    return total_secs / iteration.size();
}
vector <int> MovingAverages::calculate(vector <string> times, int n){
    int i;
    int j;
    vector <int> mov_avg;
    vector <string> iteration;

    mov_avg.clear();
    iteration.resize(n, "");

    for (i = 0; i < (times.size() - n) + 1; i++){
        for (j = i; j < (n + i); j++){
            iteration[j-i] = times[j];
        }
        mov_avg.push_back(calc_avg(iteration));
    }
            
    return mov_avg;
}
