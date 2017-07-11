#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class MonotoneSequence{
    public:
        int longestMonotoneSequence(vector <int> seq);
};

int MonotoneSequence::longestMonotoneSequence(vector <int> seq){
    int i = 0;
    int longest_length = 1;
    int incr_length = 1;
    int decr_length = 1;

    for (i = 1; i < seq.size(); i++){
        if (seq[i] > seq[i-1]){
            incr_length++;
            if (decr_length > longest_length){
                longest_length = decr_length;
            }
            decr_length = 1;
        } else if(seq[i] < seq[i-1]){
            decr_length++;
            if (incr_length > longest_length){
                longest_length = incr_length;
            }
            incr_length = 1;
        } else{
            if (max(incr_length, decr_length) > longest_length){
                longest_length = max(incr_length, decr_length);
            }
            incr_length = decr_length = 1;
        }
    }
    
    if (max(incr_length, decr_length) > longest_length){
        longest_length = max(incr_length, decr_length);
    }

    return longest_length;
}
