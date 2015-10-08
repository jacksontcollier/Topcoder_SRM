#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class TrueSpace{
    public:
        long long calculateSpace(vector <int> sizes, int clusterSize);
};

long long TrueSpace::calculateSpace(vector <int> sizes, int clusterSize){
	int i = 0;
	long long total_size = 0;

	for (i = 0; i < sizes.size(); i++){
		if (sizes[i] % clusterSize == 0){	
			total_size += sizes[i];
		} else{
			total_size += ((sizes[i] / clusterSize) + 1) * clusterSize;
		}
	}

	return total_size;
}
