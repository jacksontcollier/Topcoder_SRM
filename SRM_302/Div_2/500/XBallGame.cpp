#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class XBallGame{
    public:
        vector <string> newStatistics(vector <string> placeboard);
};

vector <string> XBallGame::newStatistics(vector <string> placeboard){
    int i = 0;    
    int j = 0;    
    int dash_index = 0;
    string name = "";
    string position = "";
    vector <string> *player_positions = NULL;
    map <string, vector <string> * > new_format;
    map <string, vector <string> * >::iterator mit;

    for (i = 0; i < placeboard.size(); i++){
        dash_index = 0;
        for (j = 0; j < placeboard[i].size(); j++){
            if (placeboard[i][j] == '-'){
                dash_index = j;    
                break;
            }
        }

        name = placeboard[i].substr(0, dash_index);
        position = placeboard[i].substr(dash_index + 1, placeboard[i].size() - (dash_index + 1));

        if ((mit = new_format.find(name)) != new_format.end()){
            (mit->second)->push_back(position);
        } else{
            player_positions = new vector <string>();
            player_positions->clear();
            player_positions->push_back(position);
            new_format.insert(make_pair(name, player_positions));
        }
    }

    for (mit = new_format.begin(); mit != new_format.end(); mit++){
        sort((*(mit->second)).begin(), (*(mit->second)).end());
    }

    for (i = 0; i < placeboard.size(); i++){
        dash_index = 0;
        for (j = 0; j < placeboard[i].size(); j++){
            if (placeboard[i][j] == '-'){
                dash_index = j;    
                break;
            }
        }

        name = placeboard[i].substr(0, dash_index);
        position = placeboard[i].substr(dash_index + 1, placeboard[i].size());    
        mit = new_format.find(name);
        
        name += "-" + position;;
        for (j = 0; j < (mit->second)->size(); j++){
            if ((*(mit->second))[j] != position){
                name += "," + (*(mit->second))[j];
            }
        }

        placeboard[i] = name;
    }

    return placeboard;    
}
