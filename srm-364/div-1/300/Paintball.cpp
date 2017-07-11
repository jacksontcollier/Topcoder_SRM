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

class Team;
class Player;

class Team{
    private:
        string name;
        int score;
        vector <Player *> players;
        map <string, Player *> ordered_players;
    public:
        Team(string n);
        string get_name();
        int get_score();
        void increment_score();
        void decrement_score();
        void add_player(Player *p);
        bool has_player(string player);
        void sort_players();
        vector <string> get_lb_entry();
};

class Player{
    private:
        string name;
        int score;
        Team *team;
    public:
        Player(string n, Team *t);
        int get_score(); 
        void increment_score();
        void decrement_score();
        string get_name();
        Team *get_team();
};

class Paintball {
    public:
        vector <string> getLeaderboard(vector <string> players, vector <string> messages);
};

Team::Team(string n){
    name = n;
    score = 0;
}

string Team::get_name(){
    return name;
}

int Team::get_score(){
    return score;
}

void Team::increment_score(){
    score++;
}

void Team::decrement_score(){
    score--;
}

void Team::add_player(Player *p){
    players.push_back(p);
    ordered_players.insert(make_pair(p->get_name(), p));
}

bool Team::has_player(string player){
    map <string, Player *>::iterator mit;

    mit = ordered_players.find(player);

    if (mit == ordered_players.end()){
        return false;
    } 

    return true;
}

void Team::sort_players(){
    int i;
    int j;
    Player *tmp;

    for (i = 1; i < players.size(); i++){
        for (j = i; j > 0 && players[j]->get_score() >= players[j-1]->get_score(); j--){
            if (players[j]->get_score() > players[j-1]->get_score() || players[j]->get_name() < players[j-1]->get_name()){
                tmp = players[j-1];
                players[j-1] = players[j];
                players[j] = tmp;
            }
        }
    }
}

vector <string> Team::get_lb_entry(){
    int i; 
    vector <string> entry;

    sort_players();
    entry.resize(0);

    entry.push_back(name + " " + to_string(score));

    for (i = 0; i < players.size(); i++){
        entry.push_back("  " + players[i]->get_name() + " " + to_string(players[i]->get_score()));
    }

    return entry;
}

Player::Player(string n, Team *t){
    name = n;
    team = t;
    score = 0;
}

int Player::get_score(){
    return score;
}

void Player::increment_score(){
    score++;
    team->increment_score();
}

void Player::decrement_score(){
    score--;
    team->decrement_score();
}

string Player::get_name(){
    return name;
}

Team *Player::get_team(){
    return team;
}

vector <string> Paintball::getLeaderboard(vector <string> players, vector <string> messages){
    int i = 0; 
    int j = 0;
    string player_name = "";
    string team_name = "";
    string shooter = "";
    string target = "";
    string junk = "";
    stringstream ss;
    Team *t = NULL;
    Team *tmp_team = NULL;
    Player *p = NULL;
    vector <string> lb;
    vector <string> entry;
    vector <Team *> teams;
    vector <Player *> list_players;
    map <string, Team *> ordered_teams;
    map <string, Team *>::iterator mit;
    map <string, Player *> ordered_players;
    map <string, Player *>::iterator pmit;
    
    lb.resize(0);
    entry.resize(0);
    teams.resize(0);
    list_players.resize(0);
    ordered_teams.clear();
    ordered_players.clear();
    
    for (i = 0; i < players.size(); i++){
        ss.clear();
        ss.str(players[i]);
        ss >> player_name;
        ss >> team_name;

        if ((mit = ordered_teams.find(team_name)) == ordered_teams.end()){
            t = new Team(team_name); 
            p = new Player(player_name, t);
            t->add_player(p);
            ordered_teams.insert(make_pair(team_name, t));
            teams.push_back(t);
            list_players.push_back(p);
            ordered_players.insert(make_pair(player_name, p));
        } else{
            p = new Player(player_name, (mit->second));
            (mit->second)->add_player(p);
            list_players.push_back(p);
            ordered_players.insert(make_pair(player_name, p));
        }
    }
    
    for (i = 0; i < messages.size(); i++){
        ss.clear();
        ss.str(messages[i]);
        ss >> shooter;
        ss >> junk;
        ss >> target;
        
        if ((pmit = ordered_players.find(shooter)) == ordered_players.end()){
            lb.push_back("ERROR: Player not found");
            return lb;
        }

        if (((pmit->second)->get_team())->has_player(target)){
            (pmit->second)->decrement_score();
        } else{
            (pmit->second)->increment_score();
            pmit = ordered_players.find(target);
            (pmit->second)->decrement_score();
        }
    }
    
    for (i = 1; i < teams.size(); i++){
        for (j = i; j > 0 && teams[j]->get_score() >= teams[j-1]->get_score(); j--){
            if (teams[j]->get_score() > teams[j-1]->get_score() || teams[j]->get_name() < teams[j-1]->get_name()){
                tmp_team = teams[j-1];
                teams[j-1] = teams[j];
                teams[j] = tmp_team;
            }
        }
    }
    
    lb.resize(0);
    for (i = 0; i < teams.size(); i++){
        entry.resize(0);
        entry = teams[i]->get_lb_entry();
        for (j = 0; j < entry.size(); j++){
            lb.push_back(entry[j]);
        }
    }

    return lb;
}
