#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <iostream>
#include <array>

class Vec3
{
public:
	Vec3() : values{ 0, 0, 0 } {}
	Vec3(double x, double y, double z) : values{ x, y, z } {}

	double x() const { return values[0]; }
	double y() const { return values[1]; }
	double z() const { return values[2]; }

	Vec3 operator-() const { return Vec3(-values[0], -values[1], -values[2]); }
	double operator[](int i) const { return values[i]; }
	double& operator[](int i) { return values[i]; }

	Vec3& operator+=(const Vec3& v);

	Vec3& operator*=(double t);

	Vec3& operator/=(double t);

	double length() const;

	double lengthSquared() const;

	std::array<double, 3> getValues() const;

private:
	std::array<double, 3> values;
};

using Point3 = Vec3;

inline std::ostream& operator<<(std::ostream& out, const Vec3& v);

inline Vec3 operator+(const Vec3& u, const Vec3& v);

inline Vec3 operator-(const Vec3& u, const Vec3& v);

inline Vec3 operator*(const Vec3& u, const Vec3& v);

inline Vec3 operator*(double t, const Vec3& v);

inline Vec3 operator*(const Vec3& v, double t);

inline Vec3 operator/(const Vec3& v, double t);

inline double dot(const Vec3& u, const Vec3& v);

inline Vec3 cross(const Vec3& u, const Vec3& v);

inline Vec3 unitVector(const Vec3& v);

#endif // VEC3_HPP