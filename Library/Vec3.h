#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <iostream>

class Vec3 {
private :
    float vector[3];

public :
    Vec3() : vector{0.0,0.0,0.0} {}
    Vec3(float v0, float v1, float v2) : vector{v0, v1, v2} {}
    ~Vec3() = default;

    const Vec3& operator+() const { return *this; }
    Vec3 operator-() const { return Vec3(-vector[0], -vector[1], -vector[2]); }
    float operator[](int i) const { return vector[i]; }
    float& operator[](int i) { return vector[i]; };
    
    Vec3& operator+=(const Vec3 &v);
    Vec3& operator-=(const Vec3 &v);
    Vec3& operator*=(const Vec3 &v);
    Vec3& operator/=(const Vec3 &v);
    Vec3& operator+=(const float d);
    Vec3& operator-=(const float d);
    Vec3& operator*=(const float d);
    Vec3& operator/=(const float d);

    float length();
    float length_sqrd();

    std::ostream& operator<<(std::ostream& out, const Vec3& v);

    Vec3 operator+(const Vec3& u, const Vec3& v);
    Vec3 operator-(const Vec3& u, const Vec3& v);
    Vec3 operator*(const Vec3& u, const Vec3& v);
    Vec3 operator/(const Vec3& u, const Vec3& v);
    
    Vec3 operator+(float d, const Vec3& v);
    Vec3 operator+(const Vec3& v, float d);
    Vec3 operator-(float d, const Vec3& v);
    Vec3 operator-(const Vec3& v, float d);
    Vec3 operator*(float d, const Vec3& v);
    Vec3 operator*(const Vec3& v, float d); 
    Vec3 operator/(const Vec3& v, float d);

    float prod_escalar(const Vec3& u, const Vec3& v);
    Vec3& prod_vec(const Vec3& u, const Vec3& v);
    Vec3& unit_vec(const Vec3& v);

};

#endif
