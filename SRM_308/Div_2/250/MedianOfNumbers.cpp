#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MedianOfNumbers{
    public:
        int findMedian(vector <int> numbers);
};

int MedianOfNumbers::findMedian(vector <int> numbers){
	if (numbers.size() % 2 == 0){
		return -1;
	}

	sort(numbers.begin(), numbers.end());

	return numbers[numbers.size() / 2];
}
