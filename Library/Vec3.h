#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <iostream>

class Vec3 {
private :
    double vector[3];

public :
    Vec3() : vector{0.0,0.0,0.0} {}
    Vec3(double v0, double v1, double v2) : vector{v0, v1, v2} {}
    ~Vec3() = default;

    const Vec3& operator+() const { return *this; }
    Vec3 operator-() const { return Vec3(-vector[0], -vector[1], -vector[2]); }
    double operator[](int i) const { return vector[i]; }
    double& operator[](int i) { return vector[i]; };

    double x() const {return vector[0];}
    double y() const {return vector[1];}
    double z() const {return vector[2];}
    
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

    std::ostream& operator<<(std::ostream& out);

    Vec3 operator+(const Vec3& v);
    Vec3 operator-(const Vec3& v);
    Vec3 operator*(const Vec3& v);
    Vec3 operator/(const Vec3& v);

    double prod_escalar(const Vec3& v);
    Vec3 prod_vec(const Vec3& v);
    Vec3 unit_vec();

};
    // How deal with rho operations type 
    // : double -> Vec -> Vec
    Vec3 operator+(double d, const Vec3& v);
    Vec3 operator+(const Vec3& v, double d);
    Vec3 operator-(double d, const Vec3& v);
    Vec3 operator-(const Vec3& v, double d);
    Vec3 operator*(double d, const Vec3& v);
    Vec3 operator*(const Vec3& v, double d);
    Vec3 operator/(const Vec3& v, double d);

#endif
