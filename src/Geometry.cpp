#include "geometry.h"
#include <iostream>

using namespace std;

void Nats::debug_string(std::string s){
    cout << "DEBUG: " << s << "." << endl;
}

Nats::Point::Point(int x, int y){
    //debug_string("point constructor");
    this->x = x;
    this->y = y;
}

void Nats::PointArray::resize(int n){
    debug_string("resizing from " + std::to_string(this->size) + " to " + std::to_string(n));
    if (n < 0){
        throw std::invalid_argument(std::string("New size is negative! New_size = " + std::to_string(n)));
    }else{
        if (n == 0){
            delete[] this->points;
            this->points = NULL;
        }else{          
            Point* old_points = this->points;
            this->points = new Point[n];
            for (int i=0; i < std::min(n, this->size); i++){
                this->points[i] = old_points[i];
            }
            this->size = n;
            delete[] old_points;
        }
    }
}

Nats::PointArray::PointArray(){
    debug_string("PointArray empty constructor");
    this->size = 0;
    this->points = NULL;
}

Nats::PointArray::~PointArray(){
    debug_string("PointArray destructor");
    delete [] this->points;
}

Nats::PointArray::PointArray(const Point points[], const int size){
    debug_string("PointArray constructor");
    if(size < 0){
        throw std::invalid_argument(std::string("Size is negative! Size = " + std::to_string(size)));
    }else{
        this->size = size;
        this->points = new Point [size];

        for(int i = 0; i < size; i++){
            this->points[i] = points[i];
        }
    }
}

/*
costruttore copia standard senza ereditarietà
Nats::PointArray::PointArray(const PointArray& pv){
    this->points = new Point[pv.size];
    for(int i = 0; i < pv.size; i++){
        this->points[i] = pv.points[i];
    }
    this->size = pv.size;
}
*/

std::string Nats::PointArray::as_string(){

    if(this->size == 0){
        std::string s;
        s += "[ empty ]";
        return s;
    }else{
    std::string s;
    s += "[";
        for(int i = 0; i < this->size; i++){
            s += "(";
            s += to_string(this->points[i].get_x());
            s += ", ";
            s += to_string(this->points[i].get_y());
            s += "), ";
        }
        int n = s.size();
        s.resize(n - 2);
        s += "]";
        return s;
    }
}

void Nats::PointArray::push_back(Point &p){
    Nats::debug_string("pushing back point: (" + std::to_string(p.get_x()) + ", " + std::to_string(p.get_y()) + ")");
    resize(this->size + 1);
    this->points[this->size -1] = p;
}

void Nats::PointArray::insert(int pos, Point &p){
    Nats::debug_string("inserting point (" + std::to_string(p.get_x()) + ", " + std::to_string(p.get_y()) + ")" + " at position " + std::to_string(pos));
    if(pos < 0){
        throw std::invalid_argument(string("Pos is negative! Pos = " + std::to_string(pos)));
    }else{
        if(pos > this->size){
            throw std::invalid_argument(string("Pos is greater than size! Pos = " + std::to_string(pos) + " > " + std::to_string(this->size)));
        }else{
            resize(this->size + 1);
            for(int i = size - 1; i > pos - 1; i--){
                this->points[i + 1] = this->points[i];
            }
            this->points[pos] = p;
        }
    }    
}