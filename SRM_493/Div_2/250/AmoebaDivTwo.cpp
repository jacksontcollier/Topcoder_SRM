#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class AmoebaDivTwo{
    public:
        int count(vector <string> table, int K);
};

int AmoebaDivTwo::count(vector <string> table, int K){
	int i = 0;
	int j = 0;
	int amsl = 0;			// anti-matter sequence length
	int num_ways = 0;		// number of ways amoeba can be place
	bool nams = false;		// new anti-matter sequence

	if (K == 1){
		for (i = 0; i < table.size(); i++){
			for (j = 0; j < table[i].size(); j++){
				if (table[i][j] == 'A'){
					num_ways++;
				}
			}
		}

		return num_ways;
	}

	for (i = 0; i < table.size(); i++){
		nams = false;
		amsl = 0;
		for (j = 0; j < table[i].size(); j++){
			if (table[i][j] == 'A'){
				if (nams == false){
					nams = true;
				}
				amsl++;	
			} else{
				if (nams){
					if (amsl >= K){
						num_ways += (amsl - K) + 1;
					}
					amsl = 0;
					nams = false;
				}
			}
		}
		if (amsl >= K){
			num_ways += (amsl - K) + 1;
		}
	}

	for (i = 0; i < table[0].size(); i++){
		nams = false;
		amsl = 0;
		for (j = 0; j < table.size(); j++){
			if (table[j][i] == 'A'){
				if (nams == false){
					nams = true;
				}
				amsl++;
			} else{
				if (nams){
					if (amsl >= K){
						num_ways += (amsl - K) + 1;
					}
					amsl = 0;
					nams = false;
				}
			}
		}
		if (amsl >= K){
			num_ways += (amsl - K) + 1;
		}
	}

	return num_ways;	
}
