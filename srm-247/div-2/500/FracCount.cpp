#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

class FracCount {
    public:
        int position(int numerator, int denominator);
};
		
int FracCount::position(int numerator, int denominator){
    int i = 0;
    int j = 0;
    int limit;
    set <double> irreducible;
    set <double>::iterator sit;
    int position = 0;
    
    irreducible.clear();

    for (i = 2; i <= denominator; i++){
        if (i < denominator){
            limit = i;
        } else{
            limit = numerator + 1;
        }

        for (j = 1; j < limit; j++){
            if ((sit = irreducible.find((double) j / (double) i)) == irreducible.end()){
                irreducible.insert((double) j / (double) i);
                position++;
            }
        }
    }

    return position;
}
