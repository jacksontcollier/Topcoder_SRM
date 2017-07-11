#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class VoteRigging{
    public:
        int minimumVotes(vector <int> votes);
};

int VoteRigging::minimumVotes(vector <int> votes){
    int i = 0;
    int j = 0;
    int limit = 0;
    int min_votes_needed = 0;
    bool have_enough_votes = true;

    if (votes.size() == 1){
        return 0;
    }

    for (i = 1; i < votes.size(); i++){
        limit += votes[i];
        if (votes[i] >= votes[0]){
            have_enough_votes = false;
        }
    }

    if (have_enough_votes){
        return 0;
    }

    sort(votes.begin() + 1, votes.end());
    reverse(votes.begin() + 1, votes.end());
    limit++;

    for (i = 0; i < limit; i++){
        votes[0]++;
        min_votes_needed++;
        votes[1]--;
        have_enough_votes = true;
            
        for (j = 1; j < votes.size(); j++){
            if (votes[j] >= votes[0]){
                have_enough_votes = false;
                break;
            }
        }
            
        if (have_enough_votes){
            return min_votes_needed;
        }
        sort(votes.begin() + 1, votes.end());
        reverse(votes.begin() + 1, votes.end());
    }

    return -1;
}
