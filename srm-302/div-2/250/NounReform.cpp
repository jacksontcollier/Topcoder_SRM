#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class NounReform{
    public:
        vector <string> makePlural(vector <string> nouns);
};

vector <string> NounReform::makePlural(vector <string> nouns){
    int i = 0;    
    char lc = 0;
    string ls = "";

    for (i = 0; i < nouns.size(); i++){
        lc = nouns[i][nouns[i].size() - 1];
        
        if (nouns[i].size() >= 2){
            ls = nouns[i].substr(nouns[i].size() - 2, 2);
        } else{
            ls = "";
        }
        
        if (lc == 's' || lc == 'z' || lc == 'x' || ls == "ch" || ls == "sh" || ls == "es"){
            nouns[i] += "es";;
        } else if (ls == "ay" || ls == "ey" || ls == "iy" || ls == "oy" || ls == "uy"){
            nouns[i].push_back('s');
        } else if (lc == 'y'){
            nouns[i].pop_back();
            nouns[i] += "ies";
        } else{
            nouns[i].push_back('s');
        }
    }

    return nouns;
}
