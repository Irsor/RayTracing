#include "Ray.hpp"

Ray::Ray()
{
}

Ray::Ray(const Point3& originParam, const Vec3& directionParam) : origin(originParam), direction(directionParam)
{
}

const Point3& Ray::getOrigin() const
{
    return origin;
}

const Vec3& Ray::getDirection() const
{
    return direction;
}

Point3 Ray::at(double t) const
{
    return origin + t * direction;
}
