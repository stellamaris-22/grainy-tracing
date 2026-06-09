#ifndef RAY_H
#define RAY_H

#include "Vec3.h"
#include "Point3.h"

class Ray {
private:
    Point3 ori;
    Vec3 dir;

public:
    Ray() {}
    Ray(const Point3& o, const Vec3& d) : ori(o), dir(d) {}
    
    const Point3& origin() const { return ori; }
    const Vec3& direction() const { return dir; }

    Point3 at(double t) const { return ori + t*dir; }
}

#endif
