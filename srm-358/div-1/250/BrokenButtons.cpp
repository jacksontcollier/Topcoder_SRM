#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class BrokenButtons{
    public:
        set <int> buttons;
        int minPresses(int page, vector <int> broken);
        bool reachable(string s);
};

bool BrokenButtons::reachable(string s){
    int i = 0;    
    bool can_reach = true;
    set <int>::iterator sit;
    
    for (i = 0; i < s.size(); i++){
        if ((sit = buttons.find(s[i] - 48)) == buttons.end()){
            can_reach = false;
            break;
        }
    }

    return can_reach;
}

int min(int A, int B){
    if (A < B){
        return A;
    }

    return B;
}

int BrokenButtons::minPresses(int page, vector <int> broken){
    int i;
    string below;
    string above;
    set <int>::iterator sit;

    if (page == 100){
        return 0;
    }

    for (i = 0; i < 10; i++){
        buttons.insert(i);
    }

    for (i = 0; i < broken.size(); i++){
        if ((sit = buttons.find(broken[i])) != buttons.end()){
            buttons.erase(sit);
        }
    }

    for (i = 0; i <= max(page - 0, 500000 - page); i++){
        if (i >= abs(page - 100)){
            return abs(page - 100);
        }

        if (page - i >= 0){
            below = to_string(page - i);
            if (reachable(below)){
                return min(below.size() + i, abs(page - 100));
            }
        }

        if (page + i >= 0){
            above = to_string(page + i);
            if (reachable(above)){
                return min(above.size() + i, abs(page - 100));
            }
        }
    }

    return 0;
}
