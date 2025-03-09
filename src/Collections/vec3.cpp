#include "Vec3.hpp"

Vec3::Vec3() : values{ 0, 0, 0 } {}
Vec3::Vec3(double x, double y, double z) : values{ x, y, z } {}

double Vec3::x() const { return values[0]; }
double Vec3::y() const { return values[1]; }
double Vec3::z() const { return values[2]; }

Vec3 Vec3::operator-() const { return Vec3(-values[0], -values[1], -values[2]); }
double Vec3::operator[](int i) const { return values[i]; }
double& Vec3::operator[](int i) { return values[i]; }

Vec3& Vec3::operator+=(const Vec3& v)
{
    values[0] += v.values[0];
    values[1] += v.values[1];
    values[2] += v.values[2];
    return *this;
}

Vec3& Vec3::operator*=(double t)
{
    values[0] *= t;
    values[1] *= t;
    values[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(double t)
{
    return *this *= 1 / t;
}

double Vec3::length() const
{
    return std::sqrt(lengthSquared());
}

double Vec3::lengthSquared() const
{
    return values[0] * values[0] + values[1] * values[1] + values[2] * values[2];
}

std::array<double, 3> Vec3::getValues() const
{
    return values;
}

std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

Vec3 operator+(const Vec3& u, const Vec3& v)
{
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

Vec3 operator-(const Vec3& u, const Vec3& v)
{
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

Vec3 operator*(const Vec3& u, const Vec3& v)
{
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

Vec3 operator*(double t, const Vec3& v)
{
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}

Vec3 operator*(const Vec3& v, double t)
{
    return t * v;
}

Vec3 operator/(const Vec3& v, double t)
{
    return (1 / t) * v;
}

double dot(const Vec3& u, const Vec3& v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

Vec3 cross(const Vec3& u, const Vec3& v)
{
    return Vec3(u.y() * v.z() - u.z() * v.y(),
        u.z() * v.x() - u.x() * v.z(),
        u.x() * v.y() - u.y() * v.x());
}

Vec3 unitVector(const Vec3& v)
{
    return v / v.length();
}
