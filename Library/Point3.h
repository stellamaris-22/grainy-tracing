#ifndef POINT3_H
#define POINT3_H

#include <math.h>
#include <iostream>
#include "Vec3.h"

class Point3 {
private :
    double vector[3];

public :
    Point3() : vector{0.0,0.0,0.0} {}
    Point3(double p0, double p1, double p2) : vector{p0, p1, p2} {}
    ~Point3() = default;

    const Point3& operator+() const { return *this; }
    Point3 operator-() const { return Point3(-vector[0], -vector[1], -vector[2]); }
    double operator[](int i) const { return vector[i]; }
    double& operator[](int i) { return vector[i]; };

    double x() const {return vector[0];}
    double y() const {return vector[1];}
    double z() const {return vector[2];}

    std::ostream& operator<<(std::ostream& out);

    Vec3 operator-(const Point3& p);
    Point3 operator-(const Vec3& v);

};
    // How deal with rho operations type 
    // : double -> Point -> Point
    Point3 operator+(double d, const Point3& p);
    Point3 operator+(const Point3& p, double d);
    Point3 operator-(double d, const Point3& p);
    Point3 operator-(const Point3& p, double d);
    Point3 operator*(double d, const Point3& p);
    Point3 operator*(const Point3& p, double d);
    Point3 operator/(const Point3& p, double d);

    // Vector makes a comeback
    // (+) : Vec3 -> Point -> Point
    Point3 operator+(const Point3& p, const Vec3& v);
    Point3 operator+(const Vec3& v, const Point3& p);

#endif
