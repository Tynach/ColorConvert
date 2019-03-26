#pragma once
#include <vecmath/conf.h>
#include <vecmath/vec3.h>

namespace vecmath {
	/**
	 * A 3x3 square matrix for color conversion calculations
	 */
	struct mat3 {
		union {
			struct {
				vec3 x;
				vec3 y;
				vec3 z;
			};

			struct {
				vec3 r;
				vec3 g;
				vec3 b;
			};
		};

		/// Calculate the determinant of the matrix
		inline const floatp det() const
		{return vec3({x.x, -y.x, z.x}).dot(
		             {y.y*z.z - y.z*z.y,
		              x.y*z.z - z.y*x.z,
		              x.y*y.z - y.y*x.z});}

		/// Transpose the matrix
		inline const mat3 transpose() const
		{return {x.x, y.x, z.x,
		         x.y, y.y, z.y,
		         x.z, y.z, z.z};}

		/// Calculate the adjoint matrix
		inline const mat3 adjoint() const
		{return {y.y*z.z - y.z*z.y, -(x.y*z.z - z.y*x.z), x.y*y.z - y.y*x.z,
		         -(y.x*z.z - z.x*y.z), x.x*z.z - z.x*x.z, -(x.x*y.z - y.x*x.z),
		         y.x*z.y - z.x*y.y, -(x.x*z.y - z.x*x.y), x.x*y.y - y.x*x.y};}

		/// Calculate the inverse matrix
		inline const mat3 inverse() const
		{
			mat3 adj = this->adjoint();
			floatp det = adj.x.dot({x.x, y.x, z.x});

			return adj/det;
		}

		inline mat3& operator+=(const mat3& other)
		{
			x += other.x, y += other.y, z += other.z;
			return *this;
		}

		inline mat3& operator-=(const mat3& other)
		{
			x -= other.x, y -= other.y, z -= other.z;
			return *this;
		}

		inline mat3& operator*=(const mat3& other)
		{
			mat3 m1 = this->transpose();

			*this = {m1.x.dot(other.x), m1.y.dot(other.x), m1.z.dot(other.x),
			         m1.x.dot(other.y), m1.y.dot(other.y), m1.z.dot(other.y),
			         m1.x.dot(other.z), m1.y.dot(other.z), m1.z.dot(other.z)};

			return *this;
		}

		inline mat3& operator/=(const mat3& other)
		{return *this *= other.inverse();}

		inline const mat3 operator+(const mat3& other) const
		{return mat3(*this) += other;}

		inline const mat3 operator-(const mat3& other) const
		{return mat3(*this) -= other;}

		inline const mat3 operator*(const mat3& other) const
		{return mat3(*this) *= other;}

		inline const mat3 operator/(const mat3& other) const
		{return mat3(*this) /= other;}


		inline mat3& operator+=(const floatp& other)
		{
			x += other, y += other, z += other;
			return *this;
		}

		inline mat3& operator-=(const floatp& other)
		{
			x -= other, y -= other, z -= other;
			return *this;
		}

		inline mat3& operator*=(const floatp& other)
		{
			x *= other, y *= other, z *= other;
			return *this;
		}

		inline mat3& operator/=(const floatp& other)
		{
			x /= other, y /= other, z /= other;
			return *this;
		}

		inline const mat3 operator+(const floatp& other) const
		{return mat3(*this) += other;}

		inline const mat3 operator-(const floatp& other) const
		{return mat3(*this) -= other;}

		inline const mat3 operator*(const floatp& other) const
		{return mat3(*this) *= other;}

		inline const mat3 operator/(const floatp& other) const
		{return mat3(*this) /= other;}

		inline bool operator==(const mat3& other) const
		{return (x == other.x) && (y == other.y) && (z == other.z);}

		inline bool operator!=(const mat3& other) const
		{return !(*this == other);}


		inline const vec3 operator*(const vec3& other)
		{
			mat3 m1 = this->transpose();

			return {m1.x.dot(other), m1.y.dot(other), m1.z.dot(other)};
		}
	};
}