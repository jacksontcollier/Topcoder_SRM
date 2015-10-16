#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Matching{
    public:
        vector <string> findMatch(vector <string> first, vector <string> second);
};

vector <string> Matching::findMatch(vector <string> first, vector <string> second){
	int i;
	set <string> symbols;
	set <string> colors;
	set <string> fill;
	set <string> num_symbols;
	set <string>::iterator sit;
	vector <string> third;
	vector < set <string> > characteristics;

	symbols.clear();
	symbols.insert("CIRCLE");
	symbols.insert("SQUIGGLE");	
	symbols.insert("DIAMOND");

	colors.clear();
	colors.insert("RED");
	colors.insert("BLUE");
	colors.insert("GREEN");

	fill.clear();
	fill.insert("SOLID");
	fill.insert("STRIPED");
	fill.insert("EMPTY");

	num_symbols.clear();
	num_symbols.insert("ONE");
	num_symbols.insert("TWO");
	num_symbols.insert("THREE");

	characteristics.clear();
	characteristics.push_back(symbols);
	characteristics.push_back(colors);
	characteristics.push_back(fill);
	characteristics.push_back(num_symbols);

	third.clear();

	for (i = 0; i < first.size(); i++){
		if (first[i] == second[i]){
			third.push_back(first[i]);
		} else{
			sit = characteristics[i].find(first[i]);
			characteristics[i].erase(sit);
			
			sit = characteristics[i].find(second[i]);
			characteristics[i].erase(sit);
			
			sit = characteristics[i].begin();
			third.push_back(*sit);
		}
	}
	
	return third;
}
