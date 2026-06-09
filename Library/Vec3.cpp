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

double Vec3::length() { return std::sqrt(length_sqrd()); }

double Vec3::length_sqrd() { 
    return std::pow(k(), 2) + 
	   std::pow(l(), 2) + 
	   std::pow(m(), 2);
}

std::ostream& Vec3::operator<<(std::ostream& out){
    return out << k() << ' ' << l() << ' ' << m();
}

Vec3 Vec3::operator+(const Vec3& v){
    return Vec3(k() + v[0], 
	        l() + v[1], 
	        m() + v[2]);
}

Vec3 Vec3::operator-(const Vec3& v){
    return Vec3(k() - v[0], 
		l() - v[1], 
		m() - v[2]);
}

Vec3 Vec3::operator*(const Vec3& v){
    return Vec3(k() * v[0], 
		l() * v[1], 
		m() * v[2]);
}

Vec3 Vec3::operator/(const Vec3& v){
    return Vec3(k() / v[0], 
		l() / v[1], 
		m() / v[2]);
}

double Vec3::prod_escalar(const Vec3& v){
    return k() * v[0] + 
	   l() * v[1] + 
	   m() * v[2];
}

Vec3 Vec3::prod_vec(const Vec3& v){
    return Vec3(l()*v[2] - m()*v[1], 
		m()*v[0] - k()*v[2], 
		k()*v[1] - l()*v[0]);
}

Vec3 Vec3::unit_vec(){
    return *this / this->length();
}

Vec3 operator+(double d, const Vec3& v){
    return Vec3(d + v.k(), 
	        d + v.l(), 
		d + v.m());
}

Vec3 operator+(const Vec3& v, double d){
    return Vec3(v.k() + d, 
	        v.l() + d, 
		v.m() + d);
}

Vec3 operator-(const Vec3& v, double d){
    return Vec3(v.k() - d, 
		v.l() - d, 
		v.m() - d);
}

Vec3 operator-(double d, const Vec3& v){
    return Vec3(d - v.k(), 
	        d - v.l(), 
		d - v.m());
}

Vec3 operator*(double d, const Vec3& v){
    return Vec3(d * v.k(), 
	        d * v.l(), 
		d * v.m());
}
Vec3 operator*(const Vec3& v, double d){
    return Vec3(v.k() * d, 
		v.l() * d, 
		v.m() * d);
}

Vec3 operator/(const Vec3& v, double d){
    return Vec3(v.k() / d, 
		v.l() / d, 
		v.m() / d);
}
