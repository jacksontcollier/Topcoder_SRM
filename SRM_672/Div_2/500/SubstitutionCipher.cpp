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

class SubstitutionCipher {
    public:
        string decode(string a, string b, string y);
};
		
string SubstitutionCipher::decode(string a, string b, string y){
    int i = 0; 
    int j = 0; 
    const int LENGTH_CYPHER_ALPHABET = 26;
    string decoded_message = "";
    map <char, char> encode_cypher;
    map <char, char> decode_cypher;
    map <char, char>::iterator mit;
    
    encode_cypher.clear();
    decode_cypher.clear();

    for (i = 0; i < a.size(); i++){
        encode_cypher.insert(make_pair(a[i], b[i]));
        decode_cypher.insert(make_pair(b[i], a[i]));
    }

    if (encode_cypher.size() == LENGTH_CYPHER_ALPHABET - 1){
        for (i = 65; i < 91; i++){
            if ((mit = encode_cypher.find(i)) == encode_cypher.end()){
                for (j = 65; j < 91; j++){
                    if ((mit = decode_cypher.find(j)) == decode_cypher.end()){
                        encode_cypher.insert(make_pair(i, j));
                        decode_cypher.insert(make_pair(j, i));
                    }
                }
            }
        }
    }

    for (i = 0; i < y.size(); i++){
        if ((mit = decode_cypher.find(y[i])) == decode_cypher.end()){
            return "";
        } else{
            decoded_message.push_back(mit->second);
        }
    }

    return decoded_message;
}
