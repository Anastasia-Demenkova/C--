#include <iostream>
#include <cmath>
class Shape{
    public:
    virtual double area()=0;
    virtual void print(std::ostream&) = 0;
};


std::ostream& operator<<(std::ostream& stream, Shape *s){
    s->print(stream);
    return stream;
    }


class Triangle: public::Shape {
    private:
    double a,b,c;
    public:
    Triangle(double a, double b, double c):a(a),b(b),c(c){};
    virtual double area(){
        return sqrt((a+b+c)*(b+c)*(a+c)*(b+c));
    }
  virtual void print(std::ostream &stream){
     stream  << "Triangle("<< a << "; " << b << "; " << c << ")";
};}
;
class Rectangle: public::Shape {
    private:
    double a,b;
    public:
    Rectangle(double a, double b):a(a),b(b){};
    virtual double area(){
        return a*b;
    }
 virtual void print(std::ostream &stream){
     stream  << "Rectangle("<< a << "; " << b << ")";
};
};
class Circle: public::Shape {
    private:
    double r;
    public:
    Circle(double r):r(r){};
    virtual double area(){
        return 3.14*r*r;
    }
 virtual void print(std::ostream &stream){
     stream  << "Circle("<< r << ")";
};
;};
int main(){
    Shape *data[3];
    data[0] = new Triangle(3, 4, 5);
    data[1] = new Rectangle(6 ,8);
    data[2] = new Circle(5);

    for(int i = 0; i < 3; ++i){
        std::cout << data[i] << std::endl;
    }
    double res = 0;
    for(int i = 0; i < 3; ++i){
        res += data[i]->area(); 
    }
    std::cout << "summ area is " << res << std::endl;
    return 0;
}
