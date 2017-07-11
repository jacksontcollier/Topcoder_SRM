#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LittleElephantAndBooks{
    public:
        int getNumber(vector <int> pages, int number);
};

int LittleElephantAndBooks::getNumber(vector <int> pages, int number){
    int i = 0;
    int page_sum = 0;

    sort(pages.begin(), pages.end());

    for (i = 0; i < number - 1; i++){
        page_sum += pages[i];
    }

    i++;
    page_sum += pages[i];

    return page_sum;
}
