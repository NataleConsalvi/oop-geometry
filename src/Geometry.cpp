#include "geometry.h"
#include <iostream>

using namespace std;

Nats::Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

Nats::PointArray::PointArray(){
    this->size = 0;
    this->points = NULL;
}

Nats::PointArray::PointArray(const Point points[], const int size){
    this->size = size;
    this->points = new Point [size];

    for(int i = 0; i < size; i++){
        this->points[i] = points[i];
    }
            
    //add controlli size
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