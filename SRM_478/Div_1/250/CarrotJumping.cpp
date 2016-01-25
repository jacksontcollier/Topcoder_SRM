#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>

using namespace std;

class Node{
    private:
        unsigned long long position;
        int distance;

    public:
        Node(unsigned long long p, int d);
        unsigned long long get_position();
        int get_distance();
        void set_distance(int d);
        void set_position(unsigned long long p);
};

class CarrotJumping{
    public:
        int theJump(int init);
};

Node::Node(unsigned long long p, int d){
    position = p;
    distance = d;
}

unsigned long long Node::get_position(){
    return position;
}

int Node::get_distance(){
    return distance;
}

void Node::set_distance(int d){
    distance = d;
}

void Node::set_position(unsigned long long p){
    position = p;
}

int CarrotJumping::theJump(int init){
    int answer; 
    unsigned long long divisor = 1000000007; 
    Node *v; 
    Node *n; 
    queue <Node *> q;
    set <unsigned long long> visited;
    set <unsigned long long>::iterator sit;
    
    n = new Node(init % divisor, 0);
    q.push(n);

    while (q.size()){
        v = q.front(); 
        q.pop();

        if (((v->get_position() % divisor) == 0) || (v->get_distance() > 100000)){
            if (v->get_distance() <= 100000){
                answer = v->get_distance();
            } else{
                answer = -1;
            }

            delete v;

            while (q.size()){
                v = q.front();
                q.pop();
                delete v;
            }

            return answer;
        }

        if ((sit = visited.find(v->get_position())) == visited.end()){
            visited.insert(v->get_position() % divisor);

            n = new Node(((4 * v->get_position()) + 3) % divisor, v->get_distance() + 1);
            q.push(n);

            n = new Node(((8 * v->get_position()) + 7) % divisor, v->get_distance() + 1);
            q.push(n);
        }

        delete v;
    }
    
    return -1;
}
