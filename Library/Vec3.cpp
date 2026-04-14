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

Vec3& Vec3::operator+=(const double d) {
    vector[0] += d;
    vector[1] += d;
    vector[2] += d;
    return *this;
}

Vec3& Vec3::operator-=(const double d) {
    vector[0] -= d;
    vector[1] -= d;
    vector[2] -= d;
    return *this;
}

Vec3& Vec3::operator*=(const double d) {
    vector[0] *= d;
    vector[1] *= d;
    vector[2] *= d;
    return *this;
}

Vec3& Vec3::operator/=(const double d) {
    vector[0] /= d;
    vector[1] /= d;
    vector[2] /= d;
    return *this;
}

double Vec3::length() { return std::sqrt(lenght_sqrd()); }

double Vec3::length_sqrd() { 
    return std::pow(vector[0], 2) + 
	   std::pow(vector[1], 2) + 
	   std::pow(vector[2], 2);
}

std::ostream& Vec3::operator<<(std::ostream& out, const Vec3& v){
    return out << '[ ' << v[0] << ' ' << v[1] << ' ' << v[2] << ' ]';
}

Vec3 Vec3::operator+(const Vec3& u, const Vec3& v){
    return Vec3::Vec3(u[0] + v[0], 
		      u[1] + v[1], 
		      u[2] + v[2]);
}

Vec3 Vec3::operator-(const Vec3& u, const Vec3& v){
    return Vec3::Vec3(u[0] - v[0], 
		      u[1] - v[1], 
		      u[2] - v[2]);
}

Vec3 Vec3::operator*(const Vec3& u, const Vec3& v){
    return Vec3::Vec3(u[0] * v[0], 
		      u[1] * v[1], 
		      u[2] * v[2]);
}

Vec3 Vec3::operator/(const Vec3& u, const Vec3& v){
    return Vec3::Vec3(u[0] / v[0], 
		      u[1] / v[1], 
		      u[2] / v[2]);
}

Vec3 Vec3::operator+(double d, const Vec3& v){
    return Vec3::Vec3(d + v[0], 
		      d + v[1], 
		      d + v[2]);
}

Vec3 Vec3::operator+(const Vec3& v, double d){
    return d + v;
}

Vec3 Vec3::operator-(double d, const Vec3& v){
    return Vec3::Vec3(d - v[0], 
		      d - v[1], 
		      d - v[2]);
}

Vec3 Vec3::operator-(const Vec3& v, double d){
    return Vec3::Vec3(v[0] - d, 
		      v[1] - d, 
		      v[2] - d);
}

Vec3 Vec3::operator*(double d, const Vec3& v){
    return Vec3::Vec3(d * v[0], 
		      d * v[1], 
		      d * v[2]);
}

Vec3 Vec3::operator*(const Vec3& v, double d){
    return d * v;
}

Vec3 Vec3::operator/(const Vec3& v, double d){
    return Vec3::Vec3(v[0] / d, 
		      v[1] / d, 
		      v[2] / d);
}

double Vec3::prod_escalar(const Vec3& u, const Vec3& v){
    return u[0] * v[0] + 
	   u[1] * v[1] + 
	   u[2] * v[2];
}

Vec3& Vec3::prod_vec(const Vec3& u, const Vec3& v){
    return Vec3::Vec3(u[1]*v[2] - u[2]*v[1], 
		      u[2]*v[0] - u[0]*v[2], 
		      u[0]*v[1] - u[1]*v[0]);
}

Vec3& unit_vec(const Vec3& v){
    return v / v.length();
}
