#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class RGBColor{
    public:
        vector <int> getComplement(vector <int> rgb);
};

vector <int> RGBColor::getComplement(vector <int> rgb){
	int i;	
	int j;
	const int MAXCOLOR = 255;
	const int SPECIAL_COMP = 128;
	const int MIN_DIFF = 32;
	bool switch_complement;
	vector <int> complement;

	complement.clear();
	
	for (i = 0; i < rgb.size(); i++){
		complement.push_back(MAXCOLOR - rgb[i]);
	}

	switch_complement = true;

	for (i = 0; i < rgb.size(); i++){
		for (j = 0; j < complement.size(); j++){
			if (abs(rgb[i] - complement[i]) > MIN_DIFF){
				switch_complement = false;
				break;
			}
		}
	}

	if (switch_complement){
		for (i = 0; i < rgb.size(); i++){
			if (rgb[i] >= SPECIAL_COMP){
				complement[i] = rgb[i] - SPECIAL_COMP;
			} else{
				complement[i] = rgb[i] + SPECIAL_COMP;
			}
		}
	}

	return complement;
}
