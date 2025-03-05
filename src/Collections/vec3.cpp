#include "Vec3.hpp"

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

inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
	return out << v.getValues()[0] << ' ' << v.getValues()[1] << ' ' << v.getValues()[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v)
{
	return Vec3(u.getValues()[0] + v.getValues()[0], u.getValues()[1] + v.getValues()[1], u.getValues()[2] + v.getValues()[2]);
}

inline Vec3 operator-(const Vec3& u, const Vec3& v)
{
	return Vec3(u.getValues()[0] - v.getValues()[0], u.getValues()[1] - v.getValues()[1], u.getValues()[2] - v.getValues()[2]);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v)
{
	return Vec3(u.getValues()[0] * v.getValues()[0], u.getValues()[1] * v.getValues()[1], u.getValues()[2] * v.getValues()[2]);
}

inline Vec3 operator*(double t, const Vec3& v)
{
	return Vec3(t * v.getValues()[0], t * v.getValues()[1], t * v.getValues()[2]);
}

inline Vec3 operator*(const Vec3& v, double t)
{
	return t * v;
}

inline Vec3 operator/(const Vec3& v, double t)
{
	return (1 / t) * v;
}

inline double dot(const Vec3& u, const Vec3& v)
{
	return u.getValues()[0] * v.getValues()[0]
		+ u.getValues()[1] * v.getValues()[1]
		+ u.getValues()[2] * v.getValues()[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v)
{
	return Vec3(u.getValues()[1] * v.getValues()[2] - u.getValues()[2] * v.getValues()[1],
		u.getValues()[2] * v.getValues()[0] - u.getValues()[0] * v.getValues()[2],
		u.getValues()[0] * v.getValues()[1] - u.getValues()[1] * v.getValues()[0]);
}

inline Vec3 unitVector(const Vec3& v)
{
	return v / v.length();
}
