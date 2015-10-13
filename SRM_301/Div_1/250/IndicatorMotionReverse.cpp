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

class Node{
    public:    
        char id;
        Node *F;
        Node *L;
        Node *R;
};

class IndicatorMotionReverse{
    public:
        string getMinProgram(vector <string> actions);
};

string IndicatorMotionReverse::getMinProgram(vector <string> actions){
    int i = 0;
    int count = 0;
    char needed_action = '\0';
    char previously_needed_action = '\0';
    stringstream ss;
    string action_string = "";
    string count_string = "";
    string instructions = "";
    Node *bar = NULL;
    Node *forward_slash = NULL;
    Node *back_slash = NULL;
    Node *hyphen = NULL;
    Node *location = NULL;

    // Create graph
    bar = new Node();
    bar->id = '|';

    forward_slash = new Node();
    forward_slash->id = '/';

    back_slash = new Node();
    back_slash->id = 'N';

    hyphen = new Node();
    hyphen->id = '-';

    bar->F = hyphen;
    bar->L = back_slash;
    bar->R = forward_slash;

    forward_slash->F = back_slash;
    forward_slash->L = bar;
    forward_slash->R = hyphen;

    back_slash->F = forward_slash;
    back_slash->L = hyphen;
    back_slash->R = bar;

    hyphen->F = bar;
    hyphen->R = back_slash;
    hyphen->L = forward_slash;

    // Concatenate actions strings
    action_string.clear();
    for (i = 0; i < actions.size(); i++){
        action_string += actions[i];
    }

    // Get starting state
    if (action_string[0] == '|'){
        location = bar;
    } else if (action_string[0] == '-'){
        location = hyphen;
    } else if (action_string[0] == '/'){
        location = forward_slash;
    } else{
        location = back_slash;
    }

    for (i = 1; i < action_string.size(); i++){
        if (location->F->id == action_string[i]){
            needed_action = 'F';
            location = location->F;
        } else if (location->L->id == action_string[i]){
            needed_action = 'L';
            location = location->L;
        } else if (location->R->id == action_string[i]){
            needed_action = 'R';
            location = location->R;
        } else{
            needed_action = 'S';
        }

        if (needed_action == previously_needed_action || previously_needed_action == '\0'){
            count++;
        } else{
            if (count > 99){
                if (count % 99 > 0){
                    instructions.push_back(previously_needed_action);    
                    if (count % 99 < 10){
                        instructions.push_back('0');
                    }
                    instructions += to_string(count % 99);
                    count -= count % 99;
                }
                while (count > 0){
                    instructions.push_back(previously_needed_action);
                    instructions += to_string(99);
                    count -= 99;
                }
            } else{
                instructions.push_back(previously_needed_action);
                if (count < 10){
                    instructions.push_back('0');
                }    
                instructions += to_string(count);    
            }
            count = 1;
        }
        
        previously_needed_action = needed_action;

        if (i == action_string.size() - 1){
            if (count > 99){
                if (count % 99 > 0){    
                    instructions.push_back(previously_needed_action);    
                    if (count % 99 < 10){
                        instructions.push_back('0');
                    }
                    instructions += to_string(count % 99);
                    count -= count % 99;
                }
                while (count > 0){
                    instructions.push_back(previously_needed_action);
                    instructions += to_string(99);
                    count -= 99;
                }
            } else{
                instructions.push_back(previously_needed_action);
                if (count < 10){
                    instructions.push_back('0');
                }
                instructions += to_string(count);
            }
        }
    }
    
    if (instructions.size() > 100){
        instructions = instructions.substr(0, 97);
        instructions += "...";
    }
    
    return instructions;
}
