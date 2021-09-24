#include "geometry.h"
#include <iostream>

using namespace std;

void Nats::debug_string(std::string s){
    cout << "DEBUG: " << s << "." << endl;
}

Nats::Point::Point(int x, int y){
    debug_string("point constructor");
    this->x = x;
    this->y = y;
}

Nats::PointArray::PointArray(){
    debug_string("PointArray empty constructor");
    this->size = 0;
    this->points = NULL;
}

Nats::PointArray::PointArray(const Point points[], const int size){
    debug_string("PointArray constructor");
    if(size < 0){
        throw std::invalid_argument(std::string("Size is null or negative! Size = " + std::to_string(size)));
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

void Nats::PointArray::resize(int n){
    debug_string("resizing from " + std::to_string(this->size) + "to " + std::to_string(n));
    if (n < 0){
        throw std::invalid_argument(std::string("New size is negative! New_size = " + std::to_string(n)));
    }else{
        if (n == 0){
            delete[] this->points;
            this->points = NULL;
        }else{
            Point* new_points = new Point[n];
            for(int i = 0; i < std::min(n, this->size); i++){
                new_points[i] = this->points[i];
            }
            this->points = new_points;
            this->size = n;
            delete [] new_points;
        }
}