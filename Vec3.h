#pragma once
#include <math.h>
#include <stdio.h>
#include <iostream>
class Vec3
{
public:
	Vec3(){};
	inline Vec3(float e0, float e1, float e2) { e[0] = e0;e[1] = e1;e[2] = e2; }
	inline float x() { return e[0]; }
	inline float y() { return e[1]; }
	inline float z() { return e[2]; }
	inline float r() { return e[0]; }
	inline float g() { return e[1]; }
	inline float b() { return e[2]; }

	inline const Vec3& operator+() const { return *this; }
	inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const {return e[i];}
	inline float& operator[](int i) { return e[i]; }

	inline Vec3& operator+=(const Vec3& v);
	inline Vec3& operator-=(const Vec3& v);
	inline Vec3& operator*=(const Vec3& v);
	inline Vec3& operator/=(const Vec3& v);
	inline Vec3& operator*=(const float n);
	inline Vec3& operator/=(const float n);

	inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline float square_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

	inline void make_unit_vector();
	~Vec3(){};

	float e[3];
};

inline Vec3& Vec3::operator+=(const Vec3& v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& v){
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

inline Vec3& Vec3::operator*=(const Vec3& v) {
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}
inline Vec3& Vec3::operator/=(const Vec3& v) {
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline Vec3& Vec3::operator*=(const float n) {
	e[0] *= n;
	e[1] *= n;
	e[2] *= n;
	return *this;
}
inline Vec3& Vec3::operator/=(const float n) {
	float k = 1.0 / n;
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline void Vec3::make_unit_vector() {
	float k = 1 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline std::istream& operator>>(std::istream& is, Vec3& v) {
	is >> v.e[0] >> v.e[1] >> v.e[2];
	return is;
}

inline std::ostream& operator<<(std::ostream& os, Vec3& v) {
	os << v.e[0] << " " << v.e[1] << " " << v.e[2];
	return os;
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator/(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vec3 operator*(const float n, const Vec3& v1) {
	return Vec3(v1.e[0] * n, v1.e[1] * n, v1.e[2] * n);
}


inline Vec3 operator*(const Vec3& v1, const float n) {
	return Vec3(v1.e[0] * n, v1.e[1] * n, v1.e[2] * n);
}

inline Vec3 operator/(const Vec3& v1, const float n) {
	return Vec3(v1.e[0] / n, v1.e[1] / n, v1.e[2] / n);
}

inline float dot(const Vec3& v1, const Vec3& v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2) {
	return Vec3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}
inline Vec3 unit_vector(Vec3 v) {
	return v / v.length();
}