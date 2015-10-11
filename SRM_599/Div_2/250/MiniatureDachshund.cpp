#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MiniatureDachshund{
    public:
        int maxMikan(vector <int> mikan, int weight);
};

int MiniatureDachshund::maxMikan(vector <int> mikan, int weight){
	int i = 0;
	int num_oranges_eaten = 0;
	int THRESHOLD = 5000;

	sort(mikan.begin(), mikan.end());

	for (i = 0; i < mikan.size(); i++){
		if (weight + mikan[i] <= THRESHOLD){
			weight += mikan[i];
			num_oranges_eaten++;
		} else{
			return num_oranges_eaten;
		}
	}
	
	return num_oranges_eaten;
}
