#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool can_win(vector <double> scores, double difficulty, double need){
    int i = 0;
    double sum = 0;
    double MAX_ERR = .0001;
    
    sort(scores.begin(), scores.end());

    for (i = 1; i < scores.size() - 1; i++){
        sum += scores[i];
    }

    if ((difficulty * sum) >= need || abs((difficulty * sum) - need) < MAX_ERR){
        return true;
    }

    return false;
}

class Diving{
    public:
        string needed(string difficulty, string need, string ratings) ;
};

string Diving::needed(string difficulty, string need, string ratings){
    int i = 0;
    int j = 0;
    int prev_i = 0;
    double unknown_score_counter = 0;
    double want = 0;
    double diff = 0;
    double arb_num = 0;
    string *arb_string;
    string answer;
    stringstream ss;    
    vector <double> scores;
    vector <string> judge_scores;

    scores.clear(); 
    
    ss.clear();
    ss << difficulty;
    ss >> diff;

    ss.clear(); 
    ss << need;
    ss >> want;

    scores.push_back(0.0);

    for (i = 0; i < ratings.size(); i++){
        if (ratings[i] == ' ' || i == ratings.size() - 1){
            arb_string = new string;
            arb_string->clear();
            
            if (i == ratings.size() - 1){
                i++;
            }

            for (j = prev_i; j < i; j++){
                arb_string->push_back(ratings[j]);
            }
            judge_scores.push_back(*arb_string);
            prev_i = i + 1;
        }
    }

    for (i = 0; i < judge_scores.size(); i++){
        if (judge_scores[i] != "?.?"){
            ss.clear(); 
            ss << judge_scores[i];
            ss >> arb_num;
            scores.push_back(arb_num);
        }
    }
    

    for (unknown_score_counter = 0; unknown_score_counter <= 10.0; unknown_score_counter += .5){
        scores[0] = unknown_score_counter;
        if (can_win(scores, diff, want)){
            answer = to_string(scores[0]);
            if (unknown_score_counter == 10.00){
                answer = answer.substr(0, 4);
            } else{
                answer = answer.substr(0, 3);
            }
            return answer;
        }
    }
    
    return "-1.0";
}
