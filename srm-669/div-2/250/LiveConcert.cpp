#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class LiveConcert{
    public:
        int maxHappiness(vector <int> h, vector <string> s);
};

int LiveConcert::maxHappiness(vector <int> h, vector <string> s){
	int i = 0;
	int max_happiness = 0;
	map <string, int> set_list;
	map <string, int>::iterator mit;

	for (i = 0; i < s.size(); i++){
		if ((mit = set_list.find(s[i])) != set_list.end()){
			if (h[i] > mit->second) mit->second = h[i];
		} else{
			set_list.insert(make_pair(s[i], h[i]));
		}
	}

	for (mit = set_list.begin(); mit != set_list.end(); mit++){
		max_happiness += mit->second;
	}

	return max_happiness;
}
