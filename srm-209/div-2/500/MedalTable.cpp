#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Country{
    private:
        string code;
        string result;
        int num_gold;
        int num_silver;
        int num_bronze;

    public:    
        Country(string s);
        void add_gold();
        void add_silver();
        void add_bronze();
        string form_result();
        string get_code();
        int get_gold();
        int get_silver();
        int get_bronze();
};

class MedalTable{
    public:
        vector <string> generate(vector <string> results) ;
};

Country::Country(string s){
    code = s;
    num_gold = 0;
    num_silver = 0;
    num_bronze = 0;
    result = "";
}

void Country::add_gold(){
    num_gold++;
}

void Country::add_silver(){
    num_silver++;
}

void Country::add_bronze(){
    num_bronze++;
}

string Country::form_result(){
    result += code;
    result.push_back(' ');
    result += to_string(num_gold);
    result.push_back(' ');
    result += to_string(num_silver);
    result.push_back(' ');
    result += to_string(num_bronze);

    return result;
}

string Country::get_code(){
    return code;
}

int Country::get_gold(){
    return num_gold;
}

int Country::get_silver(){
    return num_silver;
}

int Country::get_bronze(){
    return num_bronze;
}

bool greater_than(Country *alpha, Country *beta){
    if (alpha->get_gold() != beta->get_gold()){
        if (alpha->get_gold() > beta->get_gold()){
            return true;
        } else{
            return false;
        }
    } 

    if (alpha->get_silver() != beta->get_silver()){
        if (alpha->get_silver() > beta->get_silver()){
            return true;
        } else{
            return false;
        }
    }

    if (alpha->get_bronze() != beta->get_bronze()){
        if (alpha->get_bronze() > beta->get_bronze()){
            return true;
        } else{
            return false;
        }
    }

    if (alpha->get_code() < beta->get_code()){
        return true;
    }

    return false;
}

vector <string> MedalTable::generate(vector <string> results){
    int i = 0;
    int j = 0;
    string country_code;
    Country *arb_country;
    Country *tmp;
    stringstream ss;
    vector <Country *> complete_countries;
    vector <string> end_results;
    map <string, Country *> countries;
    map <string, Country *>::iterator mit;

    for (i = 0; i < results.size(); i++){
        ss.clear();
        ss.str(results[i]);
        
        for (j = 0; j < 3; j++){
            ss >> country_code;

            if ((mit = countries.find(country_code)) == countries.end()){
                arb_country = new Country(country_code);
            
                if (j == 0){
                    arb_country->add_gold();
                } else if (j == 1){
                    arb_country->add_silver();
                } else{
                    arb_country->add_bronze();
                }
            
                countries.insert(make_pair(country_code, arb_country));
            } else{
                if (j == 0){
                    mit->second->add_gold();
                } else if (j == 1){
                    mit->second->add_silver();
                } else{
                    mit->second->add_bronze();
                }
            }
        }
    }

    complete_countries.clear();

    for (mit = countries.begin(); mit != countries.end(); mit++){
        complete_countries.push_back(mit->second);
    }

    for (i = 1; i < complete_countries.size(); i++){
        for (j = i; j >= 1 && greater_than(complete_countries[j], complete_countries[j-1]); j--){
            tmp = complete_countries[j-1];
            complete_countries[j-1] = complete_countries[j];
            complete_countries[j] = tmp;
        }
    }

    end_results.clear();

    for (i = 0; i < complete_countries.size(); i++){
        end_results.push_back(complete_countries[i]->form_result());
    }

    return end_results;
}
