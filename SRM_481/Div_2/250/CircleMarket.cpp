#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// --------------------------------- //
// This class represents a Store //
class Store{
	public:	
		int index;									// position in circular market
		int ot;										// open time
		int ct;										// close time
		bool bought_item;							// true if we have bought item from store, false otherwise
		Store(int openTime, int closeTime, int i);
};

// --------------------------------- //
// Topcoder Problem class //
class CircleMarket{
    public:
        int makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime);
};


// --------------------------------- //
// Constructor for Store //
Store::Store(int openTime, int closeTime, int i){
	index = i;
	ot = openTime;
	ct = closeTime;
	bought_item = false;
}

// --------------------------------- //
// Definition for Topcoder Method //
int CircleMarket::makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime){
	int i = 0;						// arbitrary iteration variable
	int time = 0;					// Current time since beginning of shopping spree
	int num_purchases = 0;			// Number of purchases made so far
	int latest_closing_time = 0;	// The latest closing time of a store in the market
	Store *st;						// arbitrary store
	vector <Store *> stores;		// Instances of Store with original market order preserved

	stores.clear();

	// Create Store objects and fill vector stores, get latest closing time
	for (i = 0; i < openTime.size(); i++){
		st = new Store(openTime[i], closeTime[i], i);
		stores.push_back(st);
		
		if (closeTime[i] > latest_closing_time){
			latest_closing_time = closeTime[i];
		}
	}

	// Make circular trips around market until the last store has closed.. 
	// At each store see if you can buy an item from it. If you haven't already
	// bought item from store, increment total number of purchases made.
	i = 0;
	for (time = 0; time <= latest_closing_time; time += travelTime){ 
		if (time >= openTime[i % openTime.size()] && time <= closeTime[i % openTime.size()]){
			if (stores[i % openTime.size()]->bought_item == false){	
				num_purchases++;
				stores[i % openTime.size()]->bought_item = true;
			}
		}
		i++;
	}
	
	stores.clear();
	return num_purchases;
}
