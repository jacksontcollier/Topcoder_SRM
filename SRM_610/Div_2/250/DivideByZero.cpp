#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class DivideByZero{
    public:
        int CountNumbers(vector <int> numbers);
};

int DivideByZero::CountNumbers(vector <int> numbers){
	int i;	
	int original_size;
	set <int> nums;
	set <int>::iterator sit_inner;
	set <int>::iterator sit_outer;

	for (i = 0; i < numbers.size(); i++){
		nums.insert(numbers[i]);
	}
		
	do{
		original_size = nums.size();;
		for (sit_outer = nums.begin(); sit_outer != nums.end(); sit_outer++){
			sit_inner = sit_outer;
			sit_inner++;
			while (sit_inner != nums.end()){
				if ((*sit_inner) > (*sit_outer)){
					nums.insert((*sit_inner) / (*sit_outer));
				}

				if ((*sit_outer) > (*sit_inner)){
					nums.insert((*sit_outer) / (*sit_inner));
				}
				sit_inner++;
			}
		}
	} while (original_size != nums.size());

	return nums.size();
}
