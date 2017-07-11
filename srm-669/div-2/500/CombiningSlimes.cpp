#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;


class CombiningSlimes{
    public:
        int maxMascots(vector <int> a);
};

int CombiningSlimes::maxMascots(vector <int> a){
	int i;	
	int low_max = 0;
	int high_max = 0;
	int max_mascots = 0;
	list <int> slimes;
	list <int>::iterator lit;
	list <int>::iterator high_pos;
	list <int>::iterator low_pos;

	slimes.clear();
	
	for (i = 0; i < a.size(); i++){
		slimes.insert(slimes.end(), a[i]);
	}

	while (slimes.size() > 1){
		high_max = 0;
		low_max = 0;
		high_pos = slimes.begin();
		low_pos = slimes.end();

		for (lit = slimes.begin(); lit != slimes.end(); lit++){
			if (*lit > high_max){
				low_max = high_max;
				low_pos = high_pos;
				high_max = *lit;
				high_pos = lit;
				continue;
			}

			if (*lit > low_max){
				low_max = *lit;
				low_pos = lit;
				continue;
			}
		}

		slimes.erase(low_pos);
		slimes.erase(high_pos);
		slimes.insert(slimes.end(), low_max + high_max);
		max_mascots += low_max * high_max;
	}

	return max_mascots;
}
