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

class Participant{
    public:
        int num_times_received;
        Participant();
};

class ThrowTheBall{
    public:
        int timesThrown(int N, int M, int L);
};

Participant::Participant(){
    num_times_received = 0;
}

int ThrowTheBall::timesThrown(int N, int M, int L){
    int i = 0;
    int j = 0;
    int num_times_passed = 0;
    int ball_index = 0;
    Participant *p = NULL;
    vector <Participant *> players;

    players.clear();

    for (i = 0; i < N; i++){
        p = new Participant();
        players.push_back(p);
    }

    while (1){
        players[ball_index]->num_times_received++;

        if (players[ball_index]->num_times_received == M){
            for (j = 0; j < players.size(); j++){
                delete players[j];
            }
            return num_times_passed;
        } else if (players[ball_index]->num_times_received % 2 == 0){
            if (ball_index - L < 0){
                ball_index = (ball_index - L) + players.size();
            } else{
                ball_index = ball_index - L;
            }
        } else{
            ball_index = (ball_index + L) % players.size();
        }
        
        num_times_passed++;
    }
    
    return 0;
}
