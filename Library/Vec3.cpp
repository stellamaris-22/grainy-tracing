#include "Vec3.h"

Vec3& Vec3::operator+=(const Vec3 &v) {
    vector[0] += v[0];
    vector[1] += v[1];
    vector[2] += v[2];
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &v) {
    vector[0] -= v[0];
    vector[1] -= v[1];
    vector[2] -= v[2];
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &v) {
    vector[0] *= v[0];
    vector[1] *= v[1];
    vector[2] *= v[2];
    return *this;
}

Vec3& Vec3::operator/=(const Vec3 &v) {
    vector[0] /= v[0];
    vector[1] /= v[1];
    vector[2] /= v[2];
    return *this;
}

Vec3& Vec3::operator+=(const float d) {
    vector[0] += d;
    vector[1] += d;
    vector[2] += d;
    return *this;
}

Vec3& Vec3::operator-=(const float d) {
    vector[0] -= d;
    vector[1] -= d;
    vector[2] -= d;
    return *this;
}

Vec3& Vec3::operator*=(const float d) {
    vector[0] *= d;
    vector[1] *= d;
    vector[2] *= d;
    return *this;
}

Vec3& Vec3::operator/=(const float d) {
    vector[0] /= d;
    vector[1] /= d;
    vector[2] /= d;
    return *this;
}

float Vec3::length() { return std::sqrt(length_sqrd()); }

float Vec3::length_sqrd() { 
    return std::pow(x(), 2) + 
	   std::pow(y(), 2) + 
	   std::pow(z(), 2);
}

std::ostream& Vec3::operator<<(std::ostream& out){
    return out << x() << ' ' << y() << ' ' << z();
}

Vec3 Vec3::operator+(const Vec3& v){
    return Vec3(x() + v[0], 
	        y() + v[1], 
	        z() + v[2]);
}

Vec3 Vec3::operator-(const Vec3& v){
    return Vec3(x() - v[0], 
		y() - v[1], 
		z() - v[2]);
}

Vec3 Vec3::operator*(const Vec3& v){
    return Vec3(x() * v[0], 
		y() * v[1], 
		z() * v[2]);
}

Vec3 Vec3::operator/(const Vec3& v){
    return Vec3(x() / v[0], 
		y() / v[1], 
		z() / v[2]);
}

Vec3 Vec3::operator+(float d){
    return Vec3(x() + d, 
	        y() + d, 
		z() + d);
}

Vec3 Vec3::operator-(float d){
    return Vec3(x() - d, 
		y() - d, 
		z() - d);
}

Vec3 Vec3::operator*(float d){
    return Vec3(x() * d, 
		y() * d, 
		z() * d);
}

Vec3 Vec3::operator/(float d){
    return Vec3(x() / d, 
		y() / d, 
		z() / d);
}

float Vec3::prod_escalar(const Vec3& v){
    return x() * v[0] + 
	   y() * v[1] + 
	   z() * v[2];
}

Vec3 Vec3::prod_vec(const Vec3& v){
    return Vec3(y()*v[2] - z()*v[1], 
		z()*v[0] - x()*v[2], 
		x()*v[1] - y()*v[0]);
}

Vec3 Vec3::unit_vec(){
    return *this / this->length();
}
