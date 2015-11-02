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

class Number{
    private:
        string name;
        int value;
    public:
        Number(string n, int v);
        string get_name();
        int get_value();
};

class Speller {
    public:
        int value(string number);
};

Number::Number(string n, int v){
    name = n;
    value = v;
}

string Number::get_name(){
    return name;
}

int Number::get_value(){
    return value;
} 

int string_comparer(string s1, string s2){
    int i = 0;
    int num_differences = 0;

    for (i = 0; i < s1.size(); i++){
        if (s1[i] != s2[i]){
            num_differences++;
        }
    }

    return num_differences;
}

int Speller::value(string number){
    int i = 0;
    int j = 0;
    int min_difference = -1;
    int difference = 0;
    int num_collisions = -1;
    int return_index = 0;
    int value = 0;
    vector <string> ones;
    vector <string> tens;
    vector <Number *> nums;
    
    ones.resize(0);
    tens.resize(0);
    nums.resize(0);
    
    ones.push_back("one");
    ones.push_back("two");
    ones.push_back("three");
    ones.push_back("four");
    ones.push_back("five");
    ones.push_back("six");
    ones.push_back("seven");
    ones.push_back("eight");
    ones.push_back("nine");

    tens.push_back("twenty");
    tens.push_back("thirty");
    tens.push_back("forty");
    tens.push_back("fifty");
    tens.push_back("sixty");
    tens.push_back("seventy");
    tens.push_back("eighty");
    tens.push_back("ninety");

    for (i = 0; i < ones.size(); i++){
        nums.push_back(new Number(ones[i], i + 1));
    }

    nums.push_back(new Number("ten", 10));
    nums.push_back(new Number("eleven", 11));
    nums.push_back(new Number("twelve", 12));
    nums.push_back(new Number("thirteen", 13));
    nums.push_back(new Number("fourteen", 14));
    nums.push_back(new Number("fifteen", 15));
    nums.push_back(new Number("sixteen", 16));
    nums.push_back(new Number("seventeen", 17));
    nums.push_back(new Number("eighteen", 18));
    nums.push_back(new Number("nineteen", 19));

    for (i = 0; i < tens.size(); i++){
        nums.push_back(new Number(tens[i], (i + 2) * 10));
        for (j = 0; j < ones.size(); j++){
            nums.push_back(new Number(tens[i] + "-" + ones[j], ((i + 2) * 10) + (j + 1)));
        }
    }

    for (i = 0; i < nums.size(); i++){
        if ((nums[i]->get_name()).size() == number.size()){
            difference = string_comparer(nums[i]->get_name(), number);
            if (min_difference == -1 || difference < min_difference){
                min_difference = difference;
                num_collisions = 1;
                return_index = i;
            } else if (difference == min_difference){
                num_collisions++;
            }
        }
    }

    if (num_collisions > 1 || min_difference == -1){
        for (i = 0; i < nums.size(); i++){
            delete nums[i];
        }
        nums.resize(0);

        return -1;
    }
    
    value = nums[return_index]->get_value();

    for (i = 0; i < nums.size(); i++){
        delete nums[i];
    }
    nums.resize(0);

    return value; 
}
