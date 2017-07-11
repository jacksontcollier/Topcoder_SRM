#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class HuffmanDecoding{
    public:
        string decode(string archive, vector <string> dictionary);
};

string HuffmanDecoding::decode(string archive, vector <string> dictionary){
	int i;
	char ascii_char;
	string encoded_char;
	string decoded_message;
	map <string, char> bsc;				// bit string - character map
	map <string, char>::iterator mit;

	ascii_char = 65;
	for (i = 0; i < dictionary.size(); i++){
		bsc.insert(make_pair(dictionary[i], ascii_char));
		ascii_char++;
	}

	encoded_char.clear();
	for (i = 0; i < archive.size(); i++){
		encoded_char += archive[i];
		mit = bsc.find(encoded_char);

		if (mit != bsc.end()){
			decoded_message += mit->second;
			encoded_char.clear();
		}
	}

	return decoded_message;	
}
