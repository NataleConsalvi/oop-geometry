#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdexcept>
#include <string>
using namespace std;



namespace Nats{
    
    void debug_string(std::string s);

    class Point{
        private:
        int x;
        int y;
        
        public:

        Point(int x = 0, int y = 0);

        int get_x(){
            return this->x;
        }

        int get_y(){
            return this->y;
        }

        void set_x(const int x){
            this->x = x;
        }

        void set_y(const int y){
            this->y = y;
        }

        std::string as_string(){
            return "[" + std::to_string(this->x) + ", " + std::to_string(this->y) + "]";
        }
    };

    class PointArray{
        private:
        Point* points;
        int size;
    
        public:
        PointArray();

        PointArray(const Point points[], const int size);

        //PointArray(const PointArray& pv); standard
        PointArray(const PointArray& pv) : PointArray(pv.points, pv.size) {
            debug_string("PointArray copy constructor");   
        }

        ~PointArray(){
            debug_string("PointArray destructor");
            delete [] this->points;
        }

        void resize(int n){

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

        }

    };
}





#endif //GEOMETRY_H