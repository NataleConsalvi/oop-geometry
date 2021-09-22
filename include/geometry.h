#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdexcept>
#include <string>
using namespace std;
namespace Nats{

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
}





#endif //GEOMETRY_H