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

		inline floatp const dot(vec3 const &other) const
		{return x*other.x + y*other.y + z*other.z;}

		inline vec3& operator+=(vec3 const &other)
		{
			x += other.x, y += other.y, z += other.z;
			return *this;
		}

		inline vec3& operator-=(vec3 const &other)
		{
			x -= other.x, y -= other.y, z -= other.z;
			return *this;
		}

		inline vec3& operator*=(vec3 const &other)
		{
			x *= other.x, y *= other.y, z *= other.z;
			return *this;
		}

		inline vec3& operator/=(vec3 const &other)
		{
			x /= other.x, y /= other.y, z /= other.z;
			return *this;
		}

		inline vec3 const operator+(vec3 const &other) const
		{return vec3(*this) += other;}

		inline vec3 const operator-(vec3 const &other) const
		{return vec3(*this) -= other;}

		inline vec3 const operator*(vec3 const &other) const
		{return vec3(*this) *= other;}

		inline vec3 const operator/(vec3 const &other) const
		{return vec3(*this) /= other;}

		inline vec3& operator+=(floatp const &other)
		{return *this += {other, other, other};}

		inline vec3& operator-=(floatp const &other)
		{return *this -= {other, other, other};}

		inline vec3& operator*=(floatp const &other)
		{return *this *= {other, other, other};}

		inline vec3& operator/=(floatp const &other)
		{return *this /= {other, other, other};}

		inline vec3 const operator+(floatp const &other) const
		{return vec3(*this) += other;}

		inline vec3 const operator-(floatp const &other) const
		{return vec3(*this) -= other;}

		inline vec3 const operator*(floatp const &other) const
		{return vec3(*this) *= other;}

		inline vec3 const operator/(floatp const &other) const
		{return vec3(*this) /= other;}

		inline bool operator==(vec3 const &other) const
		{return (x == other.x) && (y == other.y) && (z == other.z);}

		inline bool operator!=(vec3 const &other) const
		{return !(*this == other);}
	};
}