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

class Cyberline{
    public:
        set <char> cyberchars;
        string lastCyberword(string cyberline);
        bool is_cyberword(string s);
        string get_cyberword(string s);
};

bool Cyberline::is_cyberword(string s){
    int i;    
    set <char>::iterator sit;

    for (i = 0; i < s.size(); i++){
        if ((sit = cyberchars.find(s[i])) != cyberchars.end()){
            return true;
        }
    }

    return false;
}

string Cyberline::get_cyberword(string s){
    int i;
    string cyberword;
    string reverse;
    set <char>::iterator sit;

    cyberword = "";

    for (i = s.size() - 1; i >= 0; i--){
        if ((sit = cyberchars.find(s[i])) != cyberchars.end()){
            cyberchars.insert('-');

            while ((i >= 0) && ((sit = cyberchars.find(s[i])) != cyberchars.end())){
                if (s[i] != '-'){    
                    cyberword.push_back(s[i]);
                }
                i--;
            }
            
            for (i = cyberword.size() - 1; i >= 0; i--){
                reverse.push_back(cyberword[i]);
            }

            return reverse;
        }
    }

    return "";
}


string Cyberline::lastCyberword(string cyberline){
    int i;
    string s;
    stringstream ss;
    vector <string> cybertext;

    cybertext.clear();

    for (i = 'a'; i != 'z' + 1; i++){
        cyberchars.insert(i);
    }

    for (i = 'A'; i != 'Z' + 1; i++){
        cyberchars.insert(i);
    }

    for (i = '0'; i != '9' + 1; i++){
        cyberchars.insert(i);
    }

    cyberchars.insert('@');
    ss.str(cyberline);

    while (ss >> s){
        cybertext.push_back(s);
    }

    for (i = cybertext.size() - 1; i >= 0; i--){
        if (is_cyberword(cybertext[i])){
            return get_cyberword(cybertext[i]);
        }
    }

    return "NAN";
}
