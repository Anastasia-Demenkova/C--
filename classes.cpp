//#include "classes.h"
#include <iostream>
#include <cmath>
class Vector
{
private:
    double x,y,z;
public:
Vector(double x=0, double y=0, double z=0):x(x), y(y), z(z){};
double abs();
Vector operator+(Vector other);
Vector operator-(Vector other);
double operator*(Vector other);
Vector operator^(Vector other);
Vector operator*(double other);
Vector operator-();
friend Vector operator*(double first, Vector second);   
friend std::ostream& operator<<(std::ostream& stream, Vector a);
};
double Vector::abs(){
    return sqrt(x*x + y*y + z*z);
};
Vector operator*(double first, Vector second);
std::ostream& operator<<(std::ostream& stream, Vector a){
    return stream<<"("<<a.x<<","<<a.y<<","<<a.z<<")";
}
Vector Vector::operator+(Vector other){
    return Vector(x + other.x, y + other.y, z + other.z);
}
Vector Vector::operator-(Vector other){
    return Vector(x - other.x, y - other.y, z - other.z);
}
double Vector::operator*(Vector other){
    return (x * other.x + y * other.y + z * other.z);
}
Vector Vector::operator^(Vector other){
    return Vector(y * other.z - z * other.y,z * other.x - x * other.z,x * other.y - y * other.x);
}
Vector Vector::operator*(double other){
    return Vector(x * other, y * other, z * other);
}
Vector operator*(double first, Vector second){
    return Vector(second.x * first, second.y * first, second.z * first);
}
Vector Vector::operator-(){
    return Vector(-x,-y,-z);

}

int main(){
    Vector a(1,2,3);
    Vector b(4,5,6);
    std::cout<<a+b<<std::endl<<a-b<<std::endl<<a*b<<std::endl<<3*b<<std::endl<<a*5<<std::endl<<(a^b)<<std::endl<<(-a)<<std::endl<<a.abs()<<std::endl;
}
