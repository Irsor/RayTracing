#ifndef RAY_HPP
#define RAY_HPP

#include "Collections/vec3.hpp"

class Ray
{
public: 
    Ray();

    Ray(const Point3& originParam, const Vec3& directionParam); 

    const Point3& getOrigin() const;

    const Vec3& getDirection() const;

    Point3 at(double t) const;

private: 
    Point3 origin;
    Vec3 direction;
};

#endif // RAY_HPP
