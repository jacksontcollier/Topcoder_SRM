#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool is_kdouble(string s, int k){
	int i;
	int num_differences;

	num_differences = 0;

	for (i = 0; i < s.size() / 2; i++){
		if (s[i] != s[(s.size() / 2) + i]){
			num_differences ++;
			if (num_differences > k){
				return false;
			}
		}
	}

	return true;
}

class KDoubleSubstrings{
    public:
        int howMuch(vector <string> str, int k);
};

int KDoubleSubstrings::howMuch(vector <string> str, int k){
	int i;
	int j;
	int l;
	int count;
	string tmp;
	string s;

	s.resize(0);

	for (i = 0; i < str.size(); i++){
		s += str[i];
	}

	count = 0;

	for (i = 2; i <= s.size(); i += 2){
		for (j = 0; j + i <= s.size(); j++){
			tmp.resize(0);
			
			for (l = j; l < j + i; l++){
				tmp.push_back(s[l]);
			}

			if (is_kdouble(tmp, k)){
				count++;
			}
		}
	}

	return count;	
}
