#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class SerialNumbers{
    public:
        vector <string> sortSerials(vector <string> serialNumbers);
};

int sum_of_digits(string A){
    int i = 0;
    int sum = 0;

    for (i = 0; i < A.size(); i++){
        if ((A[i] > 47) && (A[i] < 58)){
            sum += A[i] - 48;
        }
    }

    return sum;
}

bool less_than(string A, string B){
    if (A.size() != B.size()){
        if (A.size() < B.size()){
            return true;
        } else{
            return false;
        }
    } else if (sum_of_digits(A) != sum_of_digits(B)){
        if (sum_of_digits(A) < sum_of_digits(B)){
            return true;
        } else{
            return false;
        }
    } else{
        if (A < B){
            return true;
        } else{
            return false;
        }
    }
}

vector <string> SerialNumbers::sortSerials(vector <string> serialNumbers){
    int i = 0;
    int j = 0;
    string tmp = "";

    for (i = 0; i < serialNumbers.size(); i++){
        for (j = i; j >= 1 && less_than(serialNumbers[j], serialNumbers[j-1]); j--){
            tmp = serialNumbers[j-1];
            serialNumbers[j-1] = serialNumbers[j];
            serialNumbers[j] = tmp;
        }
    }
    
    return serialNumbers;
}
