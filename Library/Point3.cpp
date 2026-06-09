#include "Point3.h"

std::ostream& Point3::operator<<(std::ostream& out){
    return out << x() << ' ' << y() << ' ' << z();
}

Vec3 Point3::operator-(const Point3& p){
    return Vec3(x() - p[0], 
	        y() - p[1], 
		z() - p[2]);
}

Point3 Point3::operator-(const Vec3& v){
    return Point3(x() - v[0], 
		  y() - v[1], 
		  z() - v[2]);
}

Point3 operator+(double d, const Point3& p){
    return Point3(d + p.x(), 
	          d + p.y(), 
	          d + p.z());
}

Point3 operator+(const Point3& p, double d){
    return Point3(p.x() + d, 
	          p.y() + d, 
		  p.z() + d);
}

Point3 operator-(const Point3& p, double d){
    return Point3(p.x() - d, 
		  p.y() - d, 
		  p.z() - d);
}

Point3 operator-(double d, const Point3& p){
    return Point3(d - p.x(), 
	          d - p.y(), 
		  d - p.z());
}

Point3 operator*(double d, const Point3& p){
    return Point3(d * p.x(), 
	          d * p.y(), 
		  d * p.z());
}
Point3 operator*(const Point3& p, double d){
    return Point3(p.x() * d, 
		  p.y() * d, 
		  p.z() * d);
}

Point3 operator/(const Point3& p, double d){
    return Point3(p.x() / d, 
		  p.y() / d, 
		  p.z() / d);
}

Point3 operator+(const Point3& p, const Vec3& v) {
    return Point3(p.x() - v[0], 
		  p.y() - v[1], 
		  p.z() - v[2]);
}

Point3 operator+(const Vec3& v, const Point3& p){
    return p + v;
}
