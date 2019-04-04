#pragma once
#include <colorvec/conf.h>

namespace colorvec {
	/**
	 * A 3D vector for holding color values
	 */
	struct vec3 {
		union {
			struct {
				floatp x;
				floatp y;
				floatp z;
			};

			struct {
				floatp r;
				floatp g;
				floatp b;
			};
		};

		inline const floatp dot(const vec3& other) const
		{return x*other.x + y*other.y + z*other.z;}

		inline vec3& operator+=(const vec3& other)
		{
			x += other.x, y += other.y, z += other.z;
			return *this;
		}

		inline vec3& operator-=(const vec3& other)
		{
			x -= other.x, y -= other.y, z -= other.z;
			return *this;
		}

		inline vec3& operator*=(const vec3& other)
		{
			x *= other.x, y *= other.y, z *= other.z;
			return *this;
		}

		inline vec3& operator/=(const vec3& other)
		{
			x /= other.x, y /= other.y, z /= other.z;
			return *this;
		}

		inline const vec3 operator+(const vec3& other) const
		{return vec3(*this) += other;}

		inline const vec3 operator-(const vec3& other) const
		{return vec3(*this) -= other;}

		inline const vec3 operator*(const vec3& other) const
		{return vec3(*this) *= other;}

		inline const vec3 operator/(const vec3& other) const
		{return vec3(*this) /= other;}

		inline vec3& operator+=(const floatp& other)
		{return *this += {other, other, other};}

		inline vec3& operator-=(const floatp& other)
		{return *this -= {other, other, other};}

		inline vec3& operator*=(const floatp& other)
		{return *this *= {other, other, other};}

		inline vec3& operator/=(const floatp& other)
		{return *this /= {other, other, other};}

		inline const vec3 operator+(const floatp& other) const
		{return vec3(*this) += other;}

		inline const vec3 operator-(const floatp& other) const
		{return vec3(*this) -= other;}

		inline const vec3 operator*(const floatp& other) const
		{return vec3(*this) *= other;}

		inline const vec3 operator/(const floatp& other) const
		{return vec3(*this) /= other;}

		inline bool operator==(const vec3& other) const
		{return (x == other.x) && (y == other.y) && (z == other.z);}

		inline bool operator!=(const vec3& other) const
		{return !(*this == other);}
	};
}