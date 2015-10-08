#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class SquareOfDigits{
    public:
        int getMax(vector <string> data);
};

int SquareOfDigits::getMax(vector <string> data){
	int i = 0;					// Arbitrary iteration variable
	int j = 0;					// Arbitrary iteration variable
	int k = 0;					// Arbitrary iteration variable
	int max_area = 1;			// Area of largest square with same corner pieces

	for (i = 0; i < data.size(); i++){
	   for (j = 0; j < data[i].size(); j++){
	     for (k = j + 1; k < data[i].size(); k++){
	       if (data[i][j] == data[i][k]){
	         if (i + (k - j) < data.size()){
		   if ((data[i + (k-j)][j] == data[i][j]) && (data[i + (k-j)][k] == data[i][j])){
		     if (((k - j) + 1) * ((k - j) + 1) > max_area){
		       max_area = ((k - j) + 1) * ((k - j) + 1);
		     }
		   }
	         }
	       }
	     }
	   }
	 }

	return max_area;
}
