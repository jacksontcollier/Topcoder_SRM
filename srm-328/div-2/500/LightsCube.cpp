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

/* =============================================== */
/* ===== Class for a "Light" in the "Cube" ======= */
/* =============================================== */
class Light{
    public:
        Light(int x_coord, int y_coord, int z_coord);
        void turn_on(int col);
        void turn_on();
        void will_turn_on(int col);
        bool is_on();
        int get_color();
        string get_coord_string();
        void add_adjacent_light(Light *adjacent);
        void check_adjacent_lights();

    private:
        int x;
        int y;
        int z;
        int color;
        bool on;
        string coord_string;
        vector <Light *> adj;
};

/* =============================================== */
/* ==== This class Represents the "Cube" ========= */
/* =============================================== */
class Cube{
    public:
        int dimension;
        int num_lights_on;
        int num_lights;
        Cube(int N, vector <string> l);
        ~Cube();
        void turn_on_lights();
        vector <int> get_colors();

    private:
        vector <int> colors;
        vector < vector < vector <Light *> > > lights; 
        map <string, Light *> off_lights;
};


/* =============================================== */
/* ========= Constructor for a "Light" =========== */
/* ======== Pass the (x,y,z) coordinates ========= */ 
/* =============================================== */
Light::Light(int x_coord, int y_coord, int z_coord){
    x = x_coord;
    y = y_coord;
    z = z_coord;
    coord_string = to_string(x) + " " + to_string(y) + " " + to_string(z);
    color = -1;
    on = false;
    adj.resize(0);
}

/* =============================================== */
/* Light -- Sets the "on" field to true            */
/* =============================================== */
void Light::turn_on(){
    on = true;
}

/* =============================================== */
/* Light -- Pass a color to a light to turn it on  */ 
/* =============================================== */
void Light::turn_on(int col){
    color = col;
    on = true;
}

/* =============================================== */
/* Light -- Takes an int and sets the Light's      */
/* color to be that color. Does not turn the light */
/* on.                                             */
/* =============================================== */
void Light::will_turn_on(int col){
    color = col;
}

/* =============================================== */
/* =============================================== */
bool Light::is_on(){
    return on;
}

/* =============================================== */
/* =============================================== */
int Light::get_color(){
    return color;
}

/* =============================================== */
/* =============================================== */
string Light::get_coord_string(){
    return coord_string;
}

/* =============================================== */
/* Light -- Pass a pointer to an adjacent Light to */
/* add that Light to this Lights adjacency list.   */
/* =============================================== */
void Light::add_adjacent_light(Light *adjacent){
    adj.push_back(adjacent);
}
        
void Light::check_adjacent_lights(){
    int i;
    int min_value;

    min_value = -1;
    for (i = 0; i < adj.size(); i++){
        if (adj[i]->is_on() && (min_value < 0 || adj[i]->get_color() < min_value)){
            min_value = adj[i]->get_color();
        }
    }

    if (min_value > -1){
        will_turn_on(min_value);
    }
}

/* =============================================== */
/* Cube -- Constructor: Pass dimension of Cube and */
/* and vector <string> describing lights that are  */
/* initially on.                                   */
/* =============================================== */
Cube::Cube(int N, vector <string> l){
    int i;              /* arbitrary iteration variable */ 
    int x;              /* x coordinate of light */
    int y;              /* y coordinate of light */
    int z;              /* z coordinate of light */
    stringstream ss;    /* For reading in coordinates of initially turned on lights */
    
    dimension = N;
    num_lights_on = 0;
    num_lights = N * N * N;
    off_lights.clear();
    colors.resize(l.size(), 0);

    /* Create lights */
    lights.resize(N);
    
    for (x = 0; x < lights.size(); x++){
        lights[x].resize(N);
    }

    for (x = 0; x < lights.size(); x++){
        for (y = 0; y < lights[x].size(); y++){
            lights[x][y].resize(N);
        }
    }

    for (x = 0; x < lights.size(); x++){
        for (y = 0; y < lights[x].size(); y++){
            for (z = 0; z < lights[x][y].size(); z++){
                lights[x][y][z] = new Light(x, y, z);
                off_lights.insert(make_pair(to_string(x) + " " + to_string(y) + " " + to_string(z), lights[x][y][z]));
            }
        }
    }
    
    /* Add adjacent lights to each light in cube */
    for (x = 0; x < lights.size(); x++){
        for (y = 0; y < lights[x].size(); y++){
            for (z = 0; z < lights[x][y].size(); z++){
                if (x + 1 < dimension){
                    (lights[x][y][z])->add_adjacent_light(lights[x+1][y][z]);
                }

                if (x - 1 >= 0){
                    (lights[x][y][z])->add_adjacent_light(lights[x-1][y][z]);
                }

                if (y + 1 < dimension){
                    (lights[x][y][z])->add_adjacent_light(lights[x][y+1][z]);
                }

                if (y - 1 >= 0){
                    (lights[x][y][z])->add_adjacent_light(lights[x][y-1][z]);
                }

                if (z + 1 < dimension){
                    (lights[x][y][z])->add_adjacent_light(lights[x][y][z+1]);
                }

                if (z - 1 >= 0){
                    (lights[x][y][z])->add_adjacent_light(lights[x][y][z-1]);
                }
            }
        }
    }

    /* Turn on lights that are initially on */
    for (i = 0; i < l.size(); i++){
        ss.clear();
        ss.str(l[i]);
        ss >> x;
        ss >> y;
        ss >> z;
        (lights[x][y][z])->turn_on(i);
        num_lights_on++; 
        
        off_lights.erase(l[i]);
    }

};

Cube::~Cube(){
    int x;
    int y;
    int z;

    for (x = 0; x < lights.size(); x++){
        for (y = 0; y < lights[x].size(); y++){
            for (z = 0; z < lights[x][y].size(); z++){
                delete lights[x][y][z];
            }
        }
    }

    return;
}

/* =============================================== */
/* =============================================== */
void Cube::turn_on_lights(){
    int i; 
    vector <Light *> lights_to_turn_on;
    map <string, Light *>::iterator mit;

    while (off_lights.size()){
        lights_to_turn_on.resize(0);
        for (mit = off_lights.begin(); mit != off_lights.end(); mit++){
            (mit->second)->check_adjacent_lights();

            if (((mit->second)->get_color() > -1) && !((mit->second)->is_on())){
                lights_to_turn_on.push_back(mit->second); 
            }
        }

        for (i = 0; i < lights_to_turn_on.size(); i++){
            (lights_to_turn_on[i])->turn_on();
            off_lights.erase(lights_to_turn_on[i]->get_coord_string());
        }
    }
}

vector <int> Cube::get_colors(){
    int x;
    int y;
    int z;

    for (x = 0; x < lights.size(); x++){
        for (y = 0; y < lights[x].size(); y++){
            for (z = 0; z < lights[x][y].size(); z++){
                colors[(lights[x][y][z])->get_color()]++;
            }
        }
    }

    return colors;
}

class LightsCube {
    public:
        vector <int> count(int N, vector <string> lights);
};
		
vector <int> LightsCube::count(int N, vector <string> lights){
    vector <int> color_results;
    Cube *c;
    
    c = new Cube(N, lights);
    
    c->turn_on_lights();
    color_results = c->get_colors();

    delete c;

    return color_results;
}


// Powered by FileEdit


// Powered by FileEdit
