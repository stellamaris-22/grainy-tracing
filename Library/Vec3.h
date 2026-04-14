#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <iostream>

class Vec3 {
public :
    double vector[3];

    Vec3() : vector{0,0,0} {}
    Vec3(double v0, double v1, double v2) : vector{v0, v1, v2} {}
    ~Vec3() = default;

    const Vec3& operator+() const { return *this; }
    Vec3 operator-() const { return Vec3(-vector[0], -vector[1], -vector[2]); }
    double operator[](int i) const { return vector[i]; }
    double& operator[](int i) { return vector[i]; };
    
    Vec3& operator+=(const Vec3 &v);
    Vec3& operator-=(const Vec3 &v);
    Vec3& operator*=(const Vec3 &v);
    Vec3& operator/=(const Vec3 &v);
    Vec3& operator+=(const double d);
    Vec3& operator-=(const double d);
    Vec3& operator*=(const double d);
    Vec3& operator/=(const double d);

    double length();
    double length_sqrd();

    std::ostream& operator<<(std::ostream& out, const Vec3& v);

    Vec3 operator+(const Vec3& u, const Vec3& v);
    Vec3 operator-(const Vec3& u, const Vec3& v);
    Vec3 operator*(const Vec3& u, const Vec3& v);
    Vec3 operator/(const Vec3& u, const Vec3& v);
    
    Vec3 operator+(double d, const Vec3& v);
    Vec3 operator+(const Vec3& v, double d);
    Vec3 operator-(double d, const Vec3& v);
    Vec3 operator-(const Vec3& v, double d);
    Vec3 operator*(double d, const Vec3& v);
    Vec3 operator*(const Vec3& v, double d); 
    Vec3 operator/(const Vec3& v, double d);

    double prod_escalar(const Vec3& u, const Vec3& v);
    Vec3& prod_vec(const Vec3& u, const Vec3& v);
    Vec3& unit_vec(const Vec3& v);

};

#endif
