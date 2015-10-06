#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class PouringWater{
    public:
        int getMinBottles(int N, int K);
};

int PouringWater::getMinBottles(int N, int K){
	int i;
	int j;
	int power_two;
	int num_subtracted = 0;
	int num_bottles = N;
	int num_needed = 0;
	vector <int> powers;

	if (N < K){
		return 0;
	}

	powers.clear();
	powers.push_back(1);
	power_two = 1;

	while (power_two < 10000000){	
		power_two *= 2;	
		powers.push_back(power_two);
	}

	for (i = 0; i < K - 1; i++){
		for (j = powers.size() - 1; j >= 0; j--){
			if (powers[j] <= num_bottles){
				num_bottles -= powers[j];
				num_subtracted++;
				break;
			}
		}
	}

	if (num_bottles == 0){
		return 0;
	}

	for (i = 0; i < powers.size(); i++){
		if (powers[i] >= num_bottles){
			num_needed = powers[i] - num_bottles;
			break;
		}
	}
	
	if (num_subtracted < K - 1){
		return 0;
	}

	return num_needed;
}
